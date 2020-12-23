//---------------------------------------------------------------------------
#include "ClassChartPlot.h"
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma package(smart_init)
// ---------------------------------------------------------------------------
ChartPlot::ChartPlot(TCanvas *PCanvas)
{
	canvas = PCanvas;
	centerYCoord = 0;
	maxYAxis = 0;
	x = 0;
	y = centerYCoord;
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

	x += incX;
	if (x >= canvas->Width)
		Rewind();

	y = ScaleY(PYValue);
	currentPoint = TPointF(x, y);
	flowRect = TRectF(x, 0, x+50, canvas->Height);

	canvas->BeginScene();
	canvas->ClearRect(flowRect);
	canvas->Stroke->Thickness = 2;
	canvas->Stroke->Color = claLime;
	canvas->DrawLine(previousPoint, currentPoint, 1);
	canvas->EndScene();

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
	return centerYCoord - double(centerYCoord * PYValue)/double(maxYAxis);
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
void ChartPlot::SetYBounds(int PMaxYAxis)
{
	maxYAxis = PMaxYAxis;
}
// ---------------------------------------------------------------------------
void ChartPlot::SetDownsamplingRate(int PValue)
{
	downsamplingRate = PValue;
}
// ---------------------------------------------------------------------------
void ChartPlot::Rewind()
{
	x = 0;
	centerYCoord = (double(canvas->Height)/2.0);
	if (y == 0)
		y = centerYCoord;
	previousPoint = TPointF(x, y);
	samplingCount = downsamplingRate;
	incX = (double(canvas->Width)/double(samplingRate * timeWindow))*double(downsamplingRate);
}
// ---------------------------------------------------------------------------
void ChartPlot::EnableMovingAverage(int PNPoints)
{
	firFilter = new FIRFilter();
	movingAverageEnabled = true;
}
// ---------------------------------------------------------------------------
void ChartPlot::Clean()
{
	Rewind();
	flowRect = TRectF(x, 0, canvas->Width, canvas->Height);
	canvas->BeginScene();
	canvas->ClearRect(flowRect);
	canvas->EndScene();
}
// ---------------------------------------------------------------------------
int ChartPlot::GetSamplingRate()
{
   return samplingRate;
}
// ---------------------------------------------------------------------------
