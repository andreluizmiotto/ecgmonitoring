//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include "ThreadFilePlotting.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
std::ifstream ecgFile;
ChartPlot *chartPlot;
TMemo *meSignal;
float FSignal;
unsigned int FCount;
double xPixels, yPixels, FResolution;

// ---------------------------------------------------------------------------
void __fastcall TThreadFilePlotting::Update()
{
   chartPlot->Plot(FSignal);

	meSignal->Lines->Add(FSignal);
	meSignal->CaretPosition = TCaretPosition::Create(meSignal->Lines->Count, 0);
}

// ---------------------------------------------------------------------------
__fastcall TThreadFilePlotting::TThreadFilePlotting(bool CreateSuspended, AnsiString PFileName, ChartPlot *PChartPlot, TMemo *PMeSignal)
	: TThread(CreateSuspended)
{
	ecgFile.open(PFileName.c_str(), std::fstream::in);
	chartPlot = PChartPlot;
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
