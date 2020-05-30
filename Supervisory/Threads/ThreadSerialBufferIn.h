// ---------------------------------------------------------------------------

#ifndef ThreadSerialBufferInH
#define ThreadSerialBufferInH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMXTee.Chart.hpp>
#include <FMXTee.Series.hpp>
// ---------------------------------------------------------------------------
#include <string>
#include "Classes/ClassConexaoSerial.cpp"
// ---------------------------------------------------------------------------
class ThreadSerialBufferIn : public TThread
{
	protected:
		void __fastcall Execute();
		void __fastcall Update();
	private:
		void ClearSerialBuffer(std::string *PSerialBuffer);

	public:
		__fastcall ThreadSerialBufferIn(bool CreateSuspended, SerialPort *PSerialPort, TChart *PChart, TFastLineSeries *PLineSeries);
};
// ---------------------------------------------------------------------------
#endif
