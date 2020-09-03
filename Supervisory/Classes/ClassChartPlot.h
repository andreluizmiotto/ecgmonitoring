//---------------------------------------------------------------------------

#ifndef ClassChartPlotH
#define ClassChartPlotH

#include <FMX.Controls.hpp>
#include "ClassDigitalFilter.h"
//---------------------------------------------------------------------------
class ChartPlot
{
	private:
		double initialX;
		double initialY;
		double x;
		double y;
		double screenWidth;
		double screenHeight;
		double maxYValue;
		double minYValue;
		double zeroYValue;
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
	public:
		ChartPlot(TCanvas *PCanvas);
		~ChartPlot();
		void SetInitialX(double PValue);
		void SetInitialY(double PValue);
		void SetScreenSize(double PWidth, double PHeight);
		void SetYRange(double PMin, double PMax);
		void SetSamplingRate(int PValue);
		void SetTimeWindow(int PValue);
		void SetDownsamplingRate(int PValue);
		void EnableMovingAverage(int PNPoints);
		void Rewind();
		double ScaleY(double PYValue);
		void Plot(float PYValue);
      bool Downsampling();
};
//---------------------------------------------------------------------------
#endif
