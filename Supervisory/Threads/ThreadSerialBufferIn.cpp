// ---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include "ThreadSerialBufferIn.h"
#pragma package(smart_init)
// ---------------------------------------------------------------------------
#include "Principal.h"
#include <iostream>
#include <fstream>
// ---------------------------------------------------------------------------

std::string FSerialBuffer;
float FCH1SignalValue;
float FCH2SignalValue;

// ---------------------------------------------------------------------------
void __fastcall ThreadSerialBufferIn::PlotCH1Signal() {
	frmPrincipal->lineSeriesSignal->BeginUpdate();
	frmPrincipal->lineSeriesSignal->YValues->Value[frmPrincipal->FChartXPos] = FCH1SignalValue;
	frmPrincipal->lineSeriesSignal->EndUpdate();
	frmPrincipal->meSignal->Lines->Add(FCH1SignalValue);
	frmPrincipal->meSignal->CaretPosition = TCaretPosition::Create(frmPrincipal->meSignal->Lines->Count, 0);
	frmPrincipal->FChartXPos++;
	if (frmPrincipal->FChartXPos > PLOT_WINDOW)
		frmPrincipal->FChartXPos = 0;
	frmPrincipal->lineSeriesSignal->Repaint();
//	frmPrincipal->chartSignal->Repaint();
}

// ---------------------------------------------------------------------------
void __fastcall ThreadSerialBufferIn::PlotCH2Signal() {
	frmPrincipal->lineSeriesSignal->BeginUpdate();
	frmPrincipal->lineSeriesSignal->YValues->Value[frmPrincipal->FChartXPos] = FCH2SignalValue;
	frmPrincipal->lineSeriesSignal->EndUpdate();
	frmPrincipal->meSignal->Lines->Add(FCH2SignalValue);
	frmPrincipal->meSignal->CaretPosition = TCaretPosition::Create(frmPrincipal->meSignal->Lines->Count, 0);
	frmPrincipal->FChartXPos++;
	if (frmPrincipal->FChartXPos > PLOT_WINDOW)
		frmPrincipal->FChartXPos = 0;
	frmPrincipal->lineSeriesSignal->Repaint();
//	frmPrincipal->chartSignal->Repaint();
}

// ---------------------------------------------------------------------------
__fastcall ThreadSerialBufferIn::ThreadSerialBufferIn(bool CreateSuspended)
	: TThread(CreateSuspended) {
}

// ---------------------------------------------------------------------------
void __fastcall ThreadSerialBufferIn::Execute() {
	FreeOnTerminate = true;
	FSerialBuffer.clear();
	std::ofstream ACH1File;
	std::ofstream ACH2File;
	std::ofstream AFile;

	ACH1File.open("CH1Signal.txt", std::fstream::out | std::fstream::app);
	ACH2File.open("CH2Signal.txt", std::fstream::out | std::fstream::app);
	AFile.open("Signal.txt", std::fstream::out | std::fstream::app);

	while (1) {
		if (frmPrincipal->FSerialPort == NULL)
			return;
		std::vector ABufferIn = frmPrincipal->FSerialPort->ReadABuffer();
		FSerialBuffer.append(ABufferIn.begin(), ABufferIn.end());

		if (FSerialBuffer.length() < 8)
			continue;

		if ((FSerialBuffer.at(0) == '#') && (FSerialBuffer.at(1) == '$') && (FSerialBuffer.at(2) == ':')) {

			std::string FPackageList;

			while (FSerialBuffer.size() >= 8) {
				if ((FSerialBuffer.at(0) != '#') || (FSerialBuffer.at(1) != '$') || (FSerialBuffer.at(2) != ':')) {
					ClearSerialBuffer();
					break;
				}
				std::string APackage = FSerialBuffer.substr(0, 8);
				FSerialBuffer.erase(0, 8);

				unsigned char checksum = 0x50;
				for (int index = 3; index <= 6; index++) {
					checksum ^= (unsigned char)APackage.at(index);
				}

				if (checksum == (unsigned char)APackage.at(7))
					FPackageList.append(APackage);
			}

			if (FPackageList.size()) {
				for (int index = 8; index <= FPackageList.size(); index += 8) {
					std::string ASignal = FPackageList.substr(index - 8, index);

					FCH1SignalValue = ((unsigned char)(ASignal.at(3)) << 8 | (unsigned char)(ASignal.at(4))); // * ADC_1024;
					FCH2SignalValue = ((unsigned char)(ASignal.at(5)) << 8 | (unsigned char)(ASignal.at(6))); // * ADC_1024;

					Synchronize(&PlotCH1Signal);
					Synchronize(&PlotCH2Signal);

					ACH1File << FCH1SignalValue << "\n";
					ACH2File << FCH2SignalValue << "\n";
					AFile << FCH1SignalValue << "\n" << FCH2SignalValue << "\n";
				}
			}
		}
		else
			ClearSerialBuffer();
	}
	ACH1File.close();
	ACH2File.close();
}

// ---------------------------------------------------------------------------
void __fastcall ThreadSerialBufferIn::ClearSerialBuffer() {
	while ((FSerialBuffer.size() > 0) && ((FSerialBuffer.at(0) != '#') || (FSerialBuffer.at(1) != '$') || (FSerialBuffer.at(2) != ':')))
		FSerialBuffer.erase(0, 1);
}
