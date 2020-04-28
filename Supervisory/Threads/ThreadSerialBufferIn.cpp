//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include "ThreadSerialBufferIn.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
#include "Principal.h"
#include <iostream>
#include <fstream>
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//

//---------------------------------------------------------------------------
void __fastcall ThreadSerialBufferIn::PlotCH1Signal()
{
	frmPrincipal->lineSeriesCH1Signal->AddXY(FCount, FCH1SignalValue, "", clTeeColor);
	if (FCount > PLOT_WINDOW) {
		FCount = 0;
		frmPrincipal->ClearChartSeries();
    }
	frmPrincipal->chtCH1Signal->Refresh();
}
//---------------------------------------------------------------------------
void __fastcall ThreadSerialBufferIn::PlotCH2Signal()
{
	frmPrincipal->lineSeriesCH1Signal->AddXY(FCount, FCH2SignalValue, "", clTeeColor);
	if (FCount > PLOT_WINDOW) {
		FCount = 0;
		frmPrincipal->ClearChartSeries();
	}
	frmPrincipal->chtCH1Signal->Refresh();
}
//---------------------------------------------------------------------------
void __fastcall ThreadSerialBufferIn::PlotCH1FFT()
{
//	fft(FCH1SignalBuffer);
//	for (int index = 0; index < FCH1SignalBuffer.size(); index++)
//	{
//		double AFreq = index*(SAMPLING_RATE/FREQUENCY);
//		frmPrincipal->lineSeriesCH1FFT->AddXY(index, FCH1SignalBuffer[index].real(), "", clTeeColor);
//	}
}
//---------------------------------------------------------------------------
__fastcall ThreadSerialBufferIn::ThreadSerialBufferIn(bool CreateSuspended)
	: TThread(CreateSuspended)
{
}
//---------------------------------------------------------------------------
void __fastcall ThreadSerialBufferIn::Execute()
{
	FreeOnTerminate = true;
	FSerialBuffer.clear();
	std::ofstream ACH1File;
	std::ofstream ACH2File;
	std::ofstream AFile;

	ACH1File.open("CH1Signal.txt", std::fstream::out | std::fstream::app);
	ACH2File.open("CH2Signal.txt", std::fstream::out | std::fstream::app);
	AFile.open("Signal.txt", std::fstream::out | std::fstream::app);

	while(1){
		if (frmPrincipal->FSerialPort==NULL)
			return;

		FSerialBuffer.append(frmPrincipal->FSerialPort->ReadABuffer());

		if (FSerialBuffer.size() < 8)
			continue;

		if ((FSerialBuffer.at(0) == '#') && (FSerialBuffer.at(1) == '$') && (FSerialBuffer.at(2) == ':')) {
			std::string FPackageList;
			while(FSerialBuffer.size() >= 8) {
				if ((FSerialBuffer.at(0) != '#') || (FSerialBuffer.at(1) != '$') || (FSerialBuffer.at(2) != ':')) {
					ClearSerialBuffer();
					break;
				}
				std::string APackage = FSerialBuffer.substr(0, 8);
				FSerialBuffer.erase(0, 8);

				unsigned char checksum = 0x20;
				for(int index = 0; index < 7; index++) {
					checksum ^= (unsigned char) APackage.at(index);
				}

				if(checksum == (unsigned char) APackage.at(7))
					FPackageList.append(APackage);
			}

			if(FPackageList.size()) {
				for(int index = 8; index <= FPackageList.size(); index += 8)
				{
					std::string ASignal = FPackageList.substr(index - 8, index);

					FCH1SignalValue = ((unsigned char)(ASignal.at(3)) << 8 | (unsigned char)(ASignal.at(4)));// * ADC_1024;
					FCH2SignalValue = ((unsigned char)(ASignal.at(5)) << 8 | (unsigned char)(ASignal.at(6)));// * ADC_1024;

//					float APresentReading = ((unsigned char)(ASignal.at(3)) << 8 | (unsigned char)(ASignal.at(4))) * ADC_1024;
//					FCH1SignalValue = (SAMPLING_RATE * FCH1SignalValue + APresentReading)/(SAMPLING_RATE+1);
//
//					APresentReading = ((unsigned char)(ASignal.at(5)) << 8 | (unsigned char)(ASignal.at(6))) * ADC_1024;
//					FCH2SignalValue = (SAMPLING_RATE * FCH2SignalValue + APresentReading)/(SAMPLING_RATE+1);

					FCH1SignalBuffer.resize(FBufferIndex, FCH1SignalValue);
					FCH2SignalBuffer.resize(FBufferIndex++, FCH2SignalValue);

					if (FBufferIndex == FREQUENCY)
					{
						FBufferIndex = 0;
						Synchronize(&PlotCH1FFT);
					}

					Synchronize(&PlotCH1Signal);
					Synchronize(&PlotCH2Signal);

					ACH1File << FCH1SignalValue << "\n";
					ACH2File << FCH2SignalValue << "\n";
					AFile << FCH1SignalValue << "\n" << FCH2SignalValue << "\n";

					FCount++;
				}
			}
		} else
			ClearSerialBuffer();
	}
	ACH1File.close();
	ACH2File.close();
}
//---------------------------------------------------------------------------
void __fastcall ThreadSerialBufferIn::ClearSerialBuffer()
{
	while((FSerialBuffer.size() >= 3) && ((FSerialBuffer.at(0) != '#') || (FSerialBuffer.at(1) != '$') || (FSerialBuffer.at(2) != ':')))
		FSerialBuffer.erase(0, 1);
}
