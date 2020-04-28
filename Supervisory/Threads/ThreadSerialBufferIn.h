//---------------------------------------------------------------------------

#ifndef ThreadSerialBufferInH
#define ThreadSerialBufferInH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
#include <string>
#include "Classes/ClassFFT.h"
//---------------------------------------------------------------------------
class ThreadSerialBufferIn : public TThread
{
private:
	std::string FSerialBuffer;
	CArray FCH1SignalBuffer;
	CArray FCH2SignalBuffer;
   unsigned int FBufferIndex;
	float FCH1SignalValue;
	float FCH2SignalValue;
	unsigned int FCount;
protected:
	void __fastcall Execute();
	void __fastcall PlotCH1Signal();
	void __fastcall PlotCH2Signal();
	void __fastcall PlotCH1FFT();
   void __fastcall ClearSerialBuffer();
public:
	__fastcall ThreadSerialBufferIn(bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif
