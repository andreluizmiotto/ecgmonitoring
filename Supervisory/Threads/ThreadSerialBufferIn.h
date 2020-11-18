// ---------------------------------------------------------------------------

#ifndef ThreadSerialBufferInH
#define ThreadSerialBufferInH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
// ---------------------------------------------------------------------------
#include <string>
#include "Classes/ClassConexaoSerial.h"
#include "Classes/ClassChartPlot.h"
// ---------------------------------------------------------------------------
class ThreadSerialBufferIn : public TThread
{
	protected:
		void __fastcall Execute();
		void __fastcall Update();
	private:
		void DeleteInvalidPackage(std::string *PSerialBuffer);
		void IncAcquisitionTime();
      std::string LeftPadMilliseconds();
	public:
		__fastcall ThreadSerialBufferIn(bool CreateSuspended, SerialPort *PSerialPort, ChartPlot *PChartPlot);
		ChartPlot *chartPlot;
};
// ---------------------------------------------------------------------------
#endif
