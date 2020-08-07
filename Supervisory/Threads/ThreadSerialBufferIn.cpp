// ---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include "ThreadSerialBufferIn.h"
#pragma package(smart_init)
// ---------------------------------------------------------------------------
#include <iostream>
#include <fstream>
// ---------------------------------------------------------------------------
SerialPort *serialPort;
TChart *chart;
TFastLineSeries *lineSeries;
TMemo *meSignal;
float FCH1Sample;
float FCH2Sample;
unsigned int FCount;

// ---------------------------------------------------------------------------
void __fastcall ThreadSerialBufferIn::Update()
{
	lineSeries->BeginUpdate();
	if (FCount >= chart->BottomAxis->Maximum - 1) {
		FCount = 0;
	}

//	if (FCount % 2 == 0) {
		lineSeries->YValues->Value[FCount++] = FCH1Sample;
//	} else
		lineSeries->YValues->Value[FCount++] = FCH2Sample;

//	FCount++;
	lineSeries->EndUpdate();
//	chart->Repaint();

	meSignal->Lines->Add(FCH1Sample);
	meSignal->Lines->Add(FCH2Sample);
	meSignal->CaretPosition = TCaretPosition::Create(meSignal->Lines->Count, 0);
}

// ---------------------------------------------------------------------------
__fastcall ThreadSerialBufferIn::ThreadSerialBufferIn(bool CreateSuspended, SerialPort *PSerialPort, TChart *PChart, TFastLineSeries *PLineSeries, TMemo *PMeSignal)
	: TThread(CreateSuspended) {
	serialPort = PSerialPort;
	chart = PChart;
	lineSeries = PLineSeries;
	meSignal = PMeSignal;
	FreeOnTerminate = True; // don't need to cleanup after terminate
	Priority = tpTimeCritical;  // max priority
}

// ---------------------------------------------------------------------------
void __fastcall ThreadSerialBufferIn::Execute() {
	std::string vBuffer;
	std::ofstream vFile;

	vFile.open("Signal.txt", std::fstream::out | std::fstream::app);

	while (!Terminated) {
		// Leitura serial
		std::vector vSerialBuffer = serialPort->ReadABuffer();
		vBuffer.append(vSerialBuffer.begin(), vSerialBuffer.end());

		if (vBuffer.length() < 8)
			continue;

		// Verifica o cabeçalho do primeiro pacote do buffer.
		if ((vBuffer.at(0) == '@') && (vBuffer.at(1) == '#') && (vBuffer.at(2) == '$')) {

			std::string vPackageList;

			while (vBuffer.size() >= 8) {
				// Remove pacotes inválidos/corrompidos
				if ((vBuffer.at(0) != '@') || (vBuffer.at(1) != '#') || (vBuffer.at(2) != '$')) {
					DeleteInvalidPackage(&vBuffer);
					break;
				}

				// Extrai do buffer o pacote de interesse (primeiro da fila).
				std::string vPackage = vBuffer.substr(0, 8);
				vBuffer.erase(0, 8);

				// Verificação de checksum para validar a integridade do pacote.
				unsigned char vChecksum = 0x50;
				for (int index = 3; index <= 6; index++)
					vChecksum ^= (unsigned char)vPackage.at(index);

				if (vChecksum == (unsigned char)vPackage.at(7))
					vPackageList.append(vPackage);
			}

			if (vPackageList.size()) {
				for (int index = 8; index <= vPackageList.size(); index += 8) {
					std::string vSample = vPackageList.substr(index - 8, index);

					// Reconstrói as amostras em valores inteiros.
					FCH1Sample = ((unsigned char)(vSample.at(3)) << 8 | (unsigned char)(vSample.at(4)));
					FCH2Sample = ((unsigned char)(vSample.at(5)) << 8 | (unsigned char)(vSample.at(6)));

					// Insere as amostras no gráfico
					Synchronize(&Update);

					// Grava as amostras em arquivo.
					vFile << FCH1Sample << "\n" << FCH2Sample << "\n";
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
