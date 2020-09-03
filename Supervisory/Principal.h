// ---------------------------------------------------------------------------

#ifndef PrincipalH
#define PrincipalH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.MultiView.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
#include <FMX.TabControl.hpp>
#include <FMX.ImgList.hpp>
#include <System.ImageList.hpp>
#include "FrameConfig.h"
#include <FMX.Memo.hpp>
#include <FMX.ScrollBox.hpp>
#include "FrameChartView.h"
#include <FMX.Effects.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.Dialogs.hpp>
#include <FMX.Objects.hpp>
#include <FMX.ExtCtrls.hpp>
#include <ClassChartPlot.h>
#include "Lib/Utils.h"
// ---------------------------------------------------------------------------
class TfrmPrincipal : public TForm {
__published: // IDE-managed Components
	TMultiView *mvMenu;
	TSpeedButton *btnMenu;
	TSpeedButton *btnDisconnect;
	TSpeedButton *btnCleanChart;
	TSpeedButton *btnConnect;
	TStyleBook *StyleBookPrincipal;
	TImageList *ImageListMvMenu;
	TSpeedButton *btnChartView;
	TSpeedButton *btnConfig;
	TBlurEffect *blurBackground;
	TfraConfig *fraConfig;
	TfraChartView *fraChartView;
	TSpeedButton *btnOpenECGFile;
	TOpenDialog *dlgOpenFile;
	TLine *lnTopConfig;
	TLine *lnBotSerial;
	TLine *lnBotFile;
	TLine *lnTopCleanChart;
	TLayout *lytBackground;
	TImage *pltChart;
	TPlotGrid *pltGrid;
	void __fastcall btnConnectClick(TObject *Sender);
	void __fastcall btnDisconnectClick(TObject *Sender);
	void __fastcall btnCleanChartClick(TObject *Sender);
	void __fastcall btnConfigClick(TObject *Sender);
	void __fastcall btnChartViewClick(TObject *Sender);
	void __fastcall btnOpenECGFileClick(TObject *Sender);
	void __fastcall OnTerminateThread(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
private: // User declarations
	void StartSerialReading();
	void CloseSerialPort();
	void StartFilePlotting();
	void CloseFile();
	ChartPlot * NewChartPlotObj();
public: // User declarations
	__fastcall TfrmPrincipal(TComponent* Owner);
};

// ---------------------------------------------------------------------------
extern PACKAGE TfrmPrincipal *frmPrincipal;
// ---------------------------------------------------------------------------
#endif
