//---------------------------------------------------------------------------

#ifndef ThreadFilePlottingH
#define ThreadFilePlottingH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMXTee.Chart.hpp>
#include <FMXTee.Series.hpp>
#include <FMX.Memo.hpp>
// ---------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <string>
//---------------------------------------------------------------------------
class TThreadFilePlotting : public TThread
{
private:
protected:
	void __fastcall Execute();
	void __fastcall Update();
public:
	__fastcall TThreadFilePlotting(bool CreateSuspended, AnsiString PFileName, TChart *PChart, TFastLineSeries *PLineSeries, TMemo *PMeSignal);
};
//---------------------------------------------------------------------------
#endif
