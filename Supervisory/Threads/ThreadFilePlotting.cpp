//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include "ThreadFilePlotting.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
std::ifstream ecgFile;
TChart *chart;
TFastLineSeries *lineSeries;
TMemo *meSignal;
float FSignal;
unsigned int FCount;

// ---------------------------------------------------------------------------
void __fastcall TThreadFilePlotting::Update()
{
	lineSeries->BeginUpdate();
	if (FCount >= chart->BottomAxis->Maximum - 1) {
		FCount = 0;
	}

	lineSeries->YValues->Value[FCount++] = FSignal;
	lineSeries->EndUpdate();
//	chart->Repaint();

	meSignal->Lines->Add(FSignal);
	meSignal->CaretPosition = TCaretPosition::Create(meSignal->Lines->Count, 0);
}

// ---------------------------------------------------------------------------
__fastcall TThreadFilePlotting::TThreadFilePlotting(bool CreateSuspended, AnsiString PFileName, TChart *PChart, TFastLineSeries *PLineSeries, TMemo *PMeSignal)
	: TThread(CreateSuspended)
{
	ecgFile.open(PFileName.c_str(), std::fstream::in);
	chart = PChart;
	lineSeries = PLineSeries;
	meSignal = PMeSignal;
	FreeOnTerminate = True; // don't need to cleanup after terminate
	Priority = tpTimeCritical;  // max priority
}
//---------------------------------------------------------------------------
void __fastcall TThreadFilePlotting::Execute()
{
	std::string line;

	while (std::getline(ecgFile, line)) {
		line = line.substr(13, 5);
		FSignal = std::stof(line);

		Synchronize(&Update);
	}

}
//---------------------------------------------------------------------------
