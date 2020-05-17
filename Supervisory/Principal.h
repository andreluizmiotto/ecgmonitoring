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
#include "Lib/Const.h"
#include "Classes/ClassConexaoSerial.cpp"
#include "Classes/ClassFFT.h"
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
// ---------------------------------------------------------------------------
class TfrmPrincipal : public TForm {
__published: // IDE-managed Components
	TMultiView *mvMenu;
	TSpeedButton *btnConfig;
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
	TChart *chartSignal;
	TFastLineSeries *lineSeriesSignal;
	TMemo *meSignal;
	TfraConfig *fraConfig;
	void __fastcall btnConnectClick(TObject *Sender);
	void __fastcall btnDisconnectClick(TObject *Sender);
	void __fastcall btnCleanChartClick(TObject *Sender);
	void __fastcall btnConfigClick(TObject *Sender);
	void __fastcall chartSignalAfterDraw(TObject *Sender);

private: // User declarations
	void ConfigChartSeries();
	void RefreshProgressBar();
	void ConnectSerialPort();
	void DisconnectSerialPort();
public: // User declarations
	__fastcall TfrmPrincipal(TComponent* Owner);
	void ClearChartSeries();
	// Globais
	SerialPort *FSerialPort;
   unsigned int FChartXPos;
};

// ---------------------------------------------------------------------------
extern PACKAGE TfrmPrincipal *frmPrincipal;
// ---------------------------------------------------------------------------
#endif
