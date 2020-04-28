//---------------------------------------------------------------------------

#ifndef PrincipalH
#define PrincipalH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <System.ImageList.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.CategoryButtons.hpp>
#include <Vcl.ButtonGroup.hpp>
#include <VCLTee.Chart.hpp>
#include <VCLTee.Series.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
//---------------------------------------------------------------------------
#include "Lib/Const.h"
#include "Classes/ClassConexaoSerial.cpp"
#include "Classes/ClassFFT.h"
//---------------------------------------------------------------------------
class TfrmPrincipal : public TForm
{
__published:	// IDE-managed Components
	TImageList *imgListIcons;
	TButtonGroup *btnGroupMenu;
	TChart *chtCH1Signal;
	TLineSeries *lineSeriesCH1Signal;
	void __fastcall btnGroupMenuItems0Click(TObject *Sender);
	void __fastcall btnGroupMenuItems1Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall btnGroupMenuItems2Click(TObject *Sender);
	void __fastcall btnGroupMenuItems3Click(TObject *Sender);
private:	// User declarations
	void LoadCommPorts();
	void RefreshProgressBar();
	void ConnectSerialPort();
	void DisconnectSerialPort();
public:		// User declarations
	__fastcall TfrmPrincipal(TComponent* Owner);
	void ClearChartSeries();
	// Globais
	SerialPort *FSerialPort;
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmPrincipal *frmPrincipal;
//---------------------------------------------------------------------------
#endif
