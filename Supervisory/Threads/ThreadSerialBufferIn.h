// ---------------------------------------------------------------------------

#ifndef ThreadSerialBufferInH
#define ThreadSerialBufferInH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
// ---------------------------------------------------------------------------
#include <string>
#include "Classes/ClassFFT.h"

// ---------------------------------------------------------------------------
class ThreadSerialBufferIn : public TThread
{
	protected:
		void __fastcall Execute();
		void __fastcall PlotCH1Signal();
		void __fastcall PlotCH2Signal();
		void __fastcall ClearSerialBuffer();

	public:
		__fastcall ThreadSerialBufferIn(bool CreateSuspended);
};
// ---------------------------------------------------------------------------
#endif
