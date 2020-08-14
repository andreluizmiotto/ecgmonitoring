// ---------------------------------------------------------------------------

#ifndef ThreadSerialBufferInH
#define ThreadSerialBufferInH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Memo.hpp>
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
	public:
		__fastcall ThreadSerialBufferIn(bool CreateSuspended, SerialPort *PSerialPort, ChartPlot *PChartPlot, TMemo *PMeSignal);
};
// ---------------------------------------------------------------------------
#endif
