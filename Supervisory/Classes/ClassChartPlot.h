//---------------------------------------------------------------------------

#ifndef ClassChartPlotH
#define ClassChartPlotH

#include <FMX.Controls.hpp>
//---------------------------------------------------------------------------
class ChartPlot
{
	private:
		double initialX;
		double initialY;
		double X;
		double ScreenWidth;
		double ScreenHeight;
		float incX;
		int samplingCount;
		int downsamplingRate;

		TPointF currentPoint;
		TCanvas *canvas;
	public:
		ChartPlot(TCanvas *PCanvas);
		void SetInitialX(double PValue);
		void SetInitialY(double PValue);
		void SetScreenSize(double PWidth, double PHeight);
		void SetXMax(double PValue);
      void SetDownsamplingRate(int PValue);
		void Prepare();
		double Scale(double PYValue);
		void Plot(double PYValue);
      bool Downsampling();
};
//---------------------------------------------------------------------------
#endif
