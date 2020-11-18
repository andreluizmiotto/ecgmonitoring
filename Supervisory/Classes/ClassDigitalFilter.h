//---------------------------------------------------------------------------

#ifndef ClassDigitalFilterH
#define ClassDigitalFilterH

#include "Lib/Const.h"
//---------------------------------------------------------------------------
class FIRFilter
{
	private:
		int size;
		float values[MOV_AVG];
	public:
		FIRFilter();
		~FIRFilter();
		float MovingAverage(float PValue);
};
//---------------------------------------------------------------------------
#endif
