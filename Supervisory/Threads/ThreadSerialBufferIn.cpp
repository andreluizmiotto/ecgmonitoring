// ---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#pragma package(smart_init)
// ---------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include "ThreadSerialBufferIn.h"
#include "Lib/Const.h"
#include <DateUtils.hpp>
#include <IOUtils.hpp>
// ---------------------------------------------------------------------------
SerialPort *serialPort;
float FSample;
TDateTime FAcquisitionTime;
float FIncMillisecond;
float FMilliseconds;

// ---------------------------------------------------------------------------
void __fastcall ThreadSerialBufferIn::Update()
{
	chartPlot->Plot(FSample);
}
// ---------------------------------------------------------------------------
__fastcall ThreadSerialBufferIn::ThreadSerialBufferIn(bool CreateSuspended, SerialPort *PSerialPort, ChartPlot *PChartPlot)
	: TThread(CreateSuspended) {
	serialPort = PSerialPort;
	chartPlot = PChartPlot;
	FreeOnTerminate = True; // don't need to cleanup after terminate
	Priority = tpTimeCritical;  // max priority
	FIncMillisecond = (1000.0/float(chartPlot->GetSamplingRate()));
	FAcquisitionTime = 0;
	FMilliseconds = 0;
}

// ---------------------------------------------------------------------------
void __fastcall ThreadSerialBufferIn::Execute() {
	std::string vBuffer;
	std::ofstream vFile;
	int vPacketLenght = 6;

	std::time_t t = std::time(0);
	std::tm* vDate = std::localtime(&t);
	char vFileName[40];
	TDirectory::CreateDirectory(L"ECG Files");
	strftime(vFileName, 40, ".\\ECG Files\\%Y-%m-%d %Hh%Mmin.ecg", vDate);

	vFile.open(vFileName, std::fstream::out | std::fstream::app);
	try {
		while (!Terminated) {
			// Leitura serial
			std::vector vSerialBuffer = serialPort->ReadABuffer();
			vBuffer.append(vSerialBuffer.begin(), vSerialBuffer.end());

			if (vBuffer.length() < vPacketLenght)
				continue;

			// Verifica o cabeçalho do primeiro pacote do buffer.
			if ((vBuffer.at(0) == '@') && (vBuffer.at(1) == '#') && (vBuffer.at(2) == '$')) {

				while (vBuffer.size() >= vPacketLenght) {
					// Remove pacotes inválidos/corrompidos
					if ((vBuffer.at(0) != '@') || (vBuffer.at(1) != '#') || (vBuffer.at(2) != '$')) {
						DeleteInvalidPackage(&vBuffer);
						break;
					}

					// Extrai do buffer o pacote de interesse (primeiro da fila).
					std::string vPackage = vBuffer.substr(0, vPacketLenght);
					vBuffer.erase(0, vPacketLenght);

					// Verificação de checksum para validar a integridade do pacote.
					unsigned char vChecksum = 0x50;
					for (int index = 3; index <= vPacketLenght-2; index++)
						vChecksum ^= (unsigned char)vPackage.at(index);

					if (vChecksum == (unsigned char)vPackage.at(vPacketLenght-1)) {
						// Reconstrói as amostras em valores inteiros.
						FSample = ((unsigned char)(vPackage.at(3)) << 8 | (unsigned char)(vPackage.at(4)));
						FSample = (float(FSample * VOLTAGE)/float(ADC_PRECISION)) - float(OFFSET_VLTG);

						try {
							// Insere as amostras no gráfico
							Synchronize(&Update);

							// Grava as amostras em arquivo.
							IncAcquisitionTime();	
						} __finally {
							vFile << FAcquisitionTime << '.' << LeftPadMilliseconds() << int(FMilliseconds) << ' ' << FSample << std::endl;
						}
					}
				}
			}
			else
				DeleteInvalidPackage(&vBuffer);
		}
	} __finally {
		serialPort->CloseSerialPort();
		serialPort = NULL;
		delete serialPort;
		vFile.close();
	}
}
// ---------------------------------------------------------------------------
void ThreadSerialBufferIn::DeleteInvalidPackage(std::string *PSerialBuffer)
{
	while ((PSerialBuffer->size() > 0) && ((PSerialBuffer->at(0) != '@') || (PSerialBuffer->at(1) != '#') || (PSerialBuffer->at(2) != '$')))
		PSerialBuffer->erase(0, 1);
}
// ---------------------------------------------------------------------------
void ThreadSerialBufferIn::IncAcquisitionTime()
{
	FMilliseconds += FIncMillisecond;
	if (FMilliseconds >= 1000) {
		FMilliseconds = 0;
		FAcquisitionTime = IncSecond(FAcquisitionTime);
	}
}
// ---------------------------------------------------------------------------
std::string ThreadSerialBufferIn::LeftPadMilliseconds()
{
	if (int(FMilliseconds) < 10)
		return "00";
	if (int(FMilliseconds) < 100)
		return "0";
}
// ---------------------------------------------------------------------------
