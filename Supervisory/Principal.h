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
#include <FMXTee.Chart.hpp>
#include <FMXTee.Engine.hpp>
#include <FMXTee.Procs.hpp>
#include <FMXTee.Series.hpp>
#include <FMX.Memo.hpp>
#include <FMX.ScrollBox.hpp>
#include "FrameChartView.h"
#include <FMX.Effects.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.Dialogs.hpp>
#include <FMX.Objects.hpp>
// ---------------------------------------------------------------------------
class TfrmPrincipal : public TForm {
__published: // IDE-managed Components
	TMultiView *mvMenu;
	TSpeedButton *btnMenu;
	TSpeedButton *btnDisconnect;
	TSpeedButton *btnCleanChart;
	TSpeedButton *btnConnect;
	TStyleBook *StyleBookPrincipal;
	TPanel *pBackground;
	TTabControl *tbcPrincipal;
	TTabItem *tbiChart;
	TTabItem *tbiValues;
	TImageList *ImageListMvMenu;
	TMemo *meSignal;
	TSpeedButton *btnChartView;
	TSpeedButton *btnConfig;
	TBlurEffect *blurBackground;
	TLayout *lytBackground;
	TfraConfig *fraConfig;
	TfraChartView *fraChartView;
	TChart *chartSignal;
	TFastLineSeries *lineSeries;
	TSpeedButton *btnOpenECGFile;
	TOpenDialog *dlgOpenFile;
	TLine *lnTopConfig;
	TLine *lnBotSerial;
	TLine *lnBotFile;
	TLine *lnTopCleanChart;
	TTimer *tmrRepaintChart;
	void __fastcall btnConnectClick(TObject *Sender);
	void __fastcall btnDisconnectClick(TObject *Sender);
	void __fastcall btnCleanChartClick(TObject *Sender);
	void __fastcall btnConfigClick(TObject *Sender);
	void __fastcall btnChartViewClick(TObject *Sender);
	void __fastcall btnOpenECGFileClick(TObject *Sender);
	void __fastcall tmrRepaintChartTimer(TObject *Sender);
	void __fastcall OnTerminateThread(TObject *Sender);
private: // User declarations
	void StartSerialReading();
	void CloseSerialPort();
	void StartFilePlotting();
	void CloseFile();
	void ConfigChartSeries();
public: // User declarations
	__fastcall TfrmPrincipal(TComponent* Owner);
};

// ---------------------------------------------------------------------------
extern PACKAGE TfrmPrincipal *frmPrincipal;
// ---------------------------------------------------------------------------
#endif
