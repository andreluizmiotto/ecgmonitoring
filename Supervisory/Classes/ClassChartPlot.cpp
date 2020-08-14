//---------------------------------------------------------------------------
#include "ClassChartPlot.h"
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma package(smart_init)

// ---------------------------------------------------------------------------
ChartPlot::ChartPlot(TCanvas *PCanvas)
{
   canvas = PCanvas;
	initialX = 0;
	initialY = 0;
	X = initialX;
	ScreenWidth = 0;
	ScreenHeight = 0;
	incX = 0;
	samplingCount = 0;
	downsamplingRate = 0;
}
// ---------------------------------------------------------------------------
void ChartPlot::Plot(double PYValue)
{
	X += incX;
	if (Downsampling())
		return;

	double vY = Scale(PYValue);
	TPointF vNextPoint = TPointF(X, vY);

	canvas->BeginScene();
	canvas->Stroke->Thickness = 1;
	canvas->Stroke->Color = claLime;
	canvas->DrawLine(currentPoint, vNextPoint, 1);
	canvas->EndScene();

	if (X >= (ScreenWidth+initialX))
		Prepare();
	else
		currentPoint = vNextPoint;
}
// ---------------------------------------------------------------------------
bool ChartPlot::Downsampling()
{
	if (downsamplingRate == 0)
		return false;
	if (++samplingCount % downsamplingRate == 0)
		return false;
	return true;
}
// ---------------------------------------------------------------------------
double ChartPlot::Scale(double PYValue)
{
	if (PYValue == 0)
		return initialY;
	return (initialY + ((ScreenHeight * PYValue)/(-4)));
}
// ---------------------------------------------------------------------------
void ChartPlot::SetInitialX(double PValue)
{
	initialX = PValue;
}
// ---------------------------------------------------------------------------
void ChartPlot::SetInitialY(double PValue)
{
	initialY = PValue;
}
// ---------------------------------------------------------------------------
void ChartPlot::SetScreenSize(double PWidth, double PHeight)
{
	ScreenWidth = PWidth;
	ScreenHeight = PHeight;
}
// ---------------------------------------------------------------------------
void ChartPlot::SetXMax(double PValue)
{
	incX = ScreenWidth/PValue;
}
// ---------------------------------------------------------------------------
void ChartPlot::SetDownsamplingRate(int PValue)
{
	downsamplingRate = PValue;
}
// ---------------------------------------------------------------------------
void ChartPlot::Prepare()
{
	X = initialX;
	currentPoint = TPointF(X, initialY);
   samplingCount = 0;
}
