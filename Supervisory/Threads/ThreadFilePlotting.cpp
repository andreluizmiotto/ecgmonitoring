//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#pragma package(smart_init)
//---------------------------------------------------------------------------
#include "ThreadFilePlotting.h"
//---------------------------------------------------------------------------
std::ifstream ecgFile;
float FSample;

// ---------------------------------------------------------------------------
void __fastcall TThreadFilePlotting::Update()
{
	chartPlot->Plot(FSample);
}

// ---------------------------------------------------------------------------
__fastcall TThreadFilePlotting::TThreadFilePlotting(bool CreateSuspended, AnsiString PFileName, ChartPlot *PChartPlot)
	: TThread(CreateSuspended)
{
	ecgFile.open(PFileName.c_str(), std::fstream::in);
	chartPlot = PChartPlot;
	FreeOnTerminate = True; // don't need to cleanup after terminate
	Priority = tpTimeCritical;  // max priority
}
//---------------------------------------------------------------------------
void __fastcall TThreadFilePlotting::Execute()
{
	std::string line;

	while (std::getline(ecgFile, line)) {
		line = line.substr(13, 5);
		FSample = std::stof(line);

		Synchronize(&Update);
	}
	ecgFile.close();
	delete chartPlot;
}
//---------------------------------------------------------------------------
