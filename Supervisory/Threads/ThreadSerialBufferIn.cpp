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
float FCH1Value;
float FCH2Value;
unsigned int FCount;
unsigned int FScrollPoints = 10;

// ---------------------------------------------------------------------------
void __fastcall ThreadSerialBufferIn::Update()
{
	lineSeries->BeginUpdate();
	if (FCount >= chart->BottomAxis->Maximum - 1) {
		FCount = 0;
	}
	lineSeries->Delete(FCount, FScrollPoints, True);
//	lineSeries->AddXY(FCount++, FCH1Value);
//	lineSeries->AddXY(FCount++, FCH2Value);
	lineSeries->YValues->Value[FCount++] = FCH1Value;
	lineSeries->YValues->Value[FCount++] = FCH2Value;
	lineSeries->EndUpdate();
//	if (FCount % 5 == 0)
		chart->Repaint();



//	double vTempMin, vTempMax;
//	// Scroll horizontal bottom axis
//	lineSeries->GetHorizAxis->SetMinMax(FCount - chart->BottomAxis->Maximum + FScrollPoints, FCount + FScrollPoints);
//
//	// Scroll vertical left axis
//	vTempMin = lineSeries->YValues->MinValue;
//	vTempMax = lineSeries->YValues->MaxValue;
//
//	lineSeries->GetVertAxis->SetMinMax(vTempMin - vTempMin/5, vTempMax + vTempMax/5);

//   implementar delete series

//	frmPrincipal->lineSeries->YValues->Value[frmPrincipal->FChartXPos + 8] = frmPrincipal->chartSignal->Axes->Left->Maximum/2;
//	frmPrincipal->lineSeries->YValues->Value[frmPrincipal->FChartXPos] = FCH1Value;
//	frmPrincipal->meSignal->Lines->Add(FCH1Value);
//	frmPrincipal->meSignal->CaretPosition = TCaretPosition::Create(frmPrincipal->meSignal->Lines->Count, 0);
//	frmPrincipal->FChartXPos++;
//	frmPrincipal->lineSeries->Repaint();
}

// ---------------------------------------------------------------------------
__fastcall ThreadSerialBufferIn::ThreadSerialBufferIn(bool CreateSuspended, SerialPort *PSerialPort, TChart *PChart, TFastLineSeries *PLineSeries)
	: TThread(CreateSuspended) {
	serialPort = PSerialPort;
	chart = PChart;
	lineSeries = PLineSeries;
	FreeOnTerminate = True; // don't need to cleanup after terminate
	Priority = tpTimeCritical;  // max priority
}

// ---------------------------------------------------------------------------
void __fastcall ThreadSerialBufferIn::Execute() {
	std::string vSerialBuffer;
	std::ofstream AFile;

	AFile.open("Signal.txt", std::fstream::out | std::fstream::app);

	while (1) {
		if (Terminated) {
			serialPort->CloseSerialPort();
			serialPort = NULL;
			delete serialPort;
			return;
		}

		std::vector ABufferIn = serialPort->ReadABuffer();
		vSerialBuffer.append(ABufferIn.begin(), ABufferIn.end());

		if (vSerialBuffer.length() < 8)
			continue;

		if ((vSerialBuffer.at(0) == '#') && (vSerialBuffer.at(1) == '$') && (vSerialBuffer.at(2) == ':')) {

			std::string vPackageList;

			while (vSerialBuffer.size() >= 8) {
				if ((vSerialBuffer.at(0) != '#') || (vSerialBuffer.at(1) != '$') || (vSerialBuffer.at(2) != ':')) {
					ClearSerialBuffer(&vSerialBuffer);
					break;
				}
				std::string vPackage = vSerialBuffer.substr(0, 8);
				vSerialBuffer.erase(0, 8);

				unsigned char checksum = 0x50;
				for (int index = 3; index <= 6; index++) {
					checksum ^= (unsigned char)vPackage.at(index);
				}

				if (checksum == (unsigned char)vPackage.at(7))
					vPackageList.append(vPackage);
			}

			if (vPackageList.size()) {
				for (int index = 8; index <= vPackageList.size(); index += 8) {
					std::string ASignal = vPackageList.substr(index - 8, index);

					FCH1Value = ((unsigned char)(ASignal.at(3)) << 8 | (unsigned char)(ASignal.at(4))); // * ADC_1024;
					FCH2Value = ((unsigned char)(ASignal.at(5)) << 8 | (unsigned char)(ASignal.at(6))); // * ADC_1024;

					Synchronize(&Update);

					AFile << FCH1Value << "\n" << FCH2Value << "\n";
				}
			}
		}
		else
			ClearSerialBuffer(&vSerialBuffer);
	}
	AFile.close();
}

// ---------------------------------------------------------------------------
void ThreadSerialBufferIn::ClearSerialBuffer(std::string *PSerialBuffer) {
	while ((PSerialBuffer->size() > 0) && ((PSerialBuffer->at(0) != '#') || (PSerialBuffer->at(1) != '$') || (PSerialBuffer->at(2) != ':')))
		PSerialBuffer->erase(0, 1);
}
