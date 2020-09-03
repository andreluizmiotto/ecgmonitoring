// ---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#pragma package(smart_init)
// ---------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include "ThreadSerialBufferIn.h"
// ---------------------------------------------------------------------------
SerialPort *serialPort;
float FCH1Sample;
float FCH2Sample;

// ---------------------------------------------------------------------------
void __fastcall ThreadSerialBufferIn::Update()
{
	chartPlot->Plot(FCH1Sample);
//   chartPlot->Plot(FCH2Sample);
}

// ---------------------------------------------------------------------------
__fastcall ThreadSerialBufferIn::ThreadSerialBufferIn(bool CreateSuspended, SerialPort *PSerialPort, ChartPlot *PChartPlot)
	: TThread(CreateSuspended) {
	serialPort = PSerialPort;
	chartPlot = PChartPlot;
	FreeOnTerminate = True; // don't need to cleanup after terminate
	Priority = tpTimeCritical;  // max priority
}

// ---------------------------------------------------------------------------
void __fastcall ThreadSerialBufferIn::Execute() {
	std::string vBuffer;
	std::ofstream vFile;
	int vPacketLenght = 6;

	vFile.open("Signal.txt", std::fstream::out | std::fstream::app);

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
					FCH1Sample = ((unsigned char)(vPackage.at(3)) << 8 | (unsigned char)(vPackage.at(4)));
//					FCH2Sample = (((unsigned char)(vPackage.at(5)) << 8 | (unsigned char)(vPackage.at(6)))* 0.00488758553274)/0.01;

					// Insere as amostras no gráfico
					Synchronize(&Update);

					// Grava as amostras em arquivo.
					vFile << FCH1Sample << "\n";// << FCH2Sample << "\n";
				}
			}
		}
		else
			DeleteInvalidPackage(&vBuffer);
	}
	serialPort->CloseSerialPort();
	serialPort = NULL;
	delete serialPort;
	vFile.close();
}

// ---------------------------------------------------------------------------
void ThreadSerialBufferIn::DeleteInvalidPackage(std::string *PSerialBuffer) {
	while ((PSerialBuffer->size() > 0) && ((PSerialBuffer->at(0) != '@') || (PSerialBuffer->at(1) != '#') || (PSerialBuffer->at(2) != '$')))
		PSerialBuffer->erase(0, 1);
}
