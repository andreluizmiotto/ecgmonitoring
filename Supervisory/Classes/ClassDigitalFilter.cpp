//---------------------------------------------------------------------------

#pragma hdrstop

#include "ClassDigitalFilter.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
FIRFilter::FIRFilter()
{
	size = 0;
}
//---------------------------------------------------------------------------
FIRFilter::~FIRFilter()
{
//   delete []values;
}
//---------------------------------------------------------------------------
float FIRFilter::MovingAverage(float PValue)
{
	float vSum = 0;
	for (int i = size; i > 0; i--)
		values[i] = values[i-1];
	values[0] = PValue;
	if (size < N)
		size++;
	for (int i = 0; i < size; i++)
		vSum += values[i];
	vSum /= size;
	return vSum;
}
