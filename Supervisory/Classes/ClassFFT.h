#ifndef CLASSFFT_H
#define CLASSFFT_H

//---------------------------------------------------------------------------

#include <complex>
#include <iostream>
#include <valarray>
#include <cmath>

typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;

void fft(CArray& x);
void ifft(CArray& x);

//---------------------------------------------------------------------------

#endif
