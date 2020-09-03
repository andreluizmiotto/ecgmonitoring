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
	x = initialX;
	y = initialY;
	screenWidth = 0;
	screenHeight = 0;
	maxYValue = 0;
	minYValue = 0;
	incX = 0;
	samplingCount = 0;
	downsamplingRate = 1; // default
	movingAverageEnabled = false;
}
// ---------------------------------------------------------------------------
ChartPlot::~ChartPlot()
{
	if (movingAverageEnabled)
		delete firFilter;
}
// ---------------------------------------------------------------------------
void ChartPlot::Plot(float PYValue)
{
	if (movingAverageEnabled)
		PYValue = firFilter->MovingAverage(PYValue);
	if (Downsampling())
		return;

	y = ScaleY(PYValue);
	currentPoint = TPointF(x, y);
	flowRect = TRectF(x, 0, x+30, screenHeight);

	canvas->BeginScene();
	canvas->ClearRect(flowRect);
	canvas->Stroke->Thickness = 2;
	canvas->Stroke->Color = claLime;
	canvas->DrawLine(previousPoint, currentPoint, 1);
	canvas->EndScene();

	x += incX*downsamplingRate;
	if (x >= screenWidth)
		Rewind();
	else
		previousPoint = currentPoint;
}
// ---------------------------------------------------------------------------
bool ChartPlot::Downsampling()
{
	if (samplingCount++ % downsamplingRate == 0)
		return false;
	return true;
}
// ---------------------------------------------------------------------------
double ChartPlot::ScaleY(double PYValue)
{
	if (PYValue == zeroYValue)
		return initialY;
	double vY = (((screenHeight * PYValue)/(maxYValue)));
	if (minYValue < 0)
		vY = initialY + (vY*(-1));
	return vY;
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
	screenWidth = PWidth;
	screenHeight = PHeight;
}
// ---------------------------------------------------------------------------
void ChartPlot::SetYRange(double PMin, double PMax)
{
	maxYValue = PMax;
	minYValue = PMin;
	zeroYValue = (minYValue + maxYValue);
	if (zeroYValue != 0)
		zeroYValue = (zeroYValue/2);
}
// ---------------------------------------------------------------------------
void ChartPlot::SetSamplingRate(int PValue)
{
	samplingRate = PValue;
}
// ---------------------------------------------------------------------------
void ChartPlot::SetTimeWindow(int PValue)
{
	timeWindow = PValue;
}
// ---------------------------------------------------------------------------
void ChartPlot::SetDownsamplingRate(int PValue)
{
	downsamplingRate = PValue;
}
// ---------------------------------------------------------------------------
void ChartPlot::Rewind()
{
	x = initialX;
	if (y == 0)
		y = initialY;
	previousPoint = TPointF(x, y);
	samplingCount = downsamplingRate;
	incX = screenWidth/(samplingRate * timeWindow);
}
// ---------------------------------------------------------------------------
void ChartPlot::EnableMovingAverage(int PNPoints)
{
	firFilter = new FIRFilter();
	movingAverageEnabled = true;
}
// ---------------------------------------------------------------------------
