//---------------------------------------------------------------------------

#ifndef ClassDigitalFilterH
#define ClassDigitalFilterH

#define N 20
//---------------------------------------------------------------------------
class FIRFilter
{
	private:
		int size;
		float values[N];
	public:
		FIRFilter();
		~FIRFilter();
		float MovingAverage(float PValue);
};
//---------------------------------------------------------------------------
#endif
