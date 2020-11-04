//---------------------------------------------------------------------------

#ifndef ClassChartPlotH
#define ClassChartPlotH

#include <FMX.Controls.hpp>
#include "ClassDigitalFilter.h"
//---------------------------------------------------------------------------
class ChartPlot
{
	private:
		double centerYCoord;
		double maxYAxis;
		double x;
		double y;
		double screenWidth;
		double screenHeight;
		float incX;
		int samplingRate;
		int timeWindow;
		int samplingCount;
		int downsamplingRate;
		bool movingAverageEnabled;

		TPointF previousPoint;
		TPointF currentPoint;
		TRectF flowRect;
		TCanvas *canvas;
		FIRFilter *firFilter;

		bool Downsampling();
		double ScaleY(double PYValue);
	public:
		ChartPlot(TCanvas *PCanvas);
		~ChartPlot();
		void SetScreenSize(double PWidth, double PHeight);
		void SetSamplingRate(int PValue);
		void SetTimeWindow(int PValue);
		void SetYBounds(int PMaxYAxis);
		void SetDownsamplingRate(int PValue);
		void EnableMovingAverage(int PNPoints);
		void Rewind();
		void Plot(float PYValue);
      void Clean();
};
//---------------------------------------------------------------------------
#endif
