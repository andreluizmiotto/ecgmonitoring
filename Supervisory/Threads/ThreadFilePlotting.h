//---------------------------------------------------------------------------

#ifndef ThreadFilePlottingH
#define ThreadFilePlottingH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
// ---------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <string>
#include "Classes/ClassChartPlot.h"
//---------------------------------------------------------------------------
class TThreadFilePlotting : public TThread
{
private:
protected:
	void __fastcall Execute();
	void __fastcall Update();
public:
	__fastcall TThreadFilePlotting(bool CreateSuspended, AnsiString PFileName, ChartPlot *PChartPlot);
   ChartPlot *chartPlot;
};
//---------------------------------------------------------------------------
#endif
