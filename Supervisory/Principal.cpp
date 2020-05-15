// ---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Principal.h"
#include <iostream>
#include "Threads/ThreadSerialBufferIn.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FrameConfig"
#pragma resource "*.fmx"
TfrmPrincipal *frmPrincipal;

// ---------------------------------------------------------------------------
__fastcall TfrmPrincipal::TfrmPrincipal(TComponent* Owner) : TForm(Owner)
{
   this->tbcPrincipal->ActiveTab = this->tbiChart;
/*	chartSignal->ClipPoints = false;
	chartSignal->Title->Visible = false;
	chartSignal->Legend->Visible = false;
	chartSignal->LeftAxis->Axis->Width = 1;
	chartSignal->BottomAxis->Axis->Width = 1;
	chartSignal->BottomAxis->RoundFirstLabel = false;
	chartSignal->View3D = false;
	lineSeriesSignal->XValues->Order = loNone;

	chartSignal->LeftAxis->SetMinMax(0, 1023);
	chartSignal->BottomAxis->SetMinMax(1, 500);

//	chartSignal->Canvas->ReferenceCanvas->Pen->OwnerCriticalSection = NULL;
//	lineSeriesSignal->LinePen->OwnerCriticalSection = NULL;
	chartSignal->Axes->FastCalc = true;*/
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void TfrmPrincipal::ConnectSerialPort()
{
	// Inicialização da porta serial.
	if (FSerialPort != NULL)
	{
		DisconnectSerialPort();
		return;
	}

	FSerialPort = new SerialPort();
	try
	{
		FSerialPort->OpenSerialPort(fraConfig->cbbSerialPort->Selected->Text, fraConfig->cbbBaudrate->Selected->Text);
		fraConfig->cbbSerialPort->Enabled = false;
		fraConfig->cbbBaudrate->Enabled = false;
		ThreadSerialBufferIn *AThreadSerialBufferIn = new ThreadSerialBufferIn(false);
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		ShowMessage("Falha na conexão.");
		DisconnectSerialPort();
	}
}
//---------------------------------------------------------------------------
void TfrmPrincipal::DisconnectSerialPort()
{
	if (FSerialPort == NULL)
		return;
	FSerialPort->CloseSerialPort();
	FSerialPort = NULL;
	delete FSerialPort;
	fraConfig->cbbSerialPort->Enabled = true;
	fraConfig->cbbBaudrate->Enabled = true;
}
//---------------------------------------------------------------------------
void TfrmPrincipal::ClearChartSeries()
{
	lineSeriesSignal->Clear();
	chartSignal->Axes->Left->Minimum = 0;
	chartSignal->Axes->Left->Maximum = 1023;
	chartSignal->Axes->Bottom->Minimum = 0;
	chartSignal->Axes->Bottom->Maximum = PLOT_WINDOW;
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::btnConnectClick(TObject *Sender)
{
	ConnectSerialPort();
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::btnDisconnectClick(TObject *Sender)
{
	DisconnectSerialPort();
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::btnCleanChartClick(TObject *Sender)
{
	ClearChartSeries();
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::FormShow(TObject *Sender)
{
	fraConfig->LoadComPorts();
}
//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::btnConfigClick(TObject *Sender)
{
	fraConfig->ShowPopup();
}
//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::chartSignalAfterDraw(TObject *Sender)
{
	double xIni, xFin, yIni, yFin;

	xIni = chartSignal->BottomAxis->CalcPosValue(FChartXPos - 1) - 8;
	yIni = chartSignal->LeftAxis->CalcPosValue(chartSignal->LeftAxis->Minimum) - 1;
	xFin = chartSignal->BottomAxis->CalcPosValue(FChartXPos - 1) + 8;
	yFin = chartSignal->LeftAxis->CalcPosValue(chartSignal->LeftAxis->Maximum) + 1;

	if (xFin < chartSignal->BottomAxis->CalcPosValue(chartSignal->BottomAxis->Maximum)+8)
	{
		//Chart1->Canvas->Pen->Style = psSolid;
		//Chart1->Canvas->Pen->Color = clWhite;
		//Chart1->Canvas->Brush->Color = clWhite;
		//Chart1->Canvas->ReferenceCanvas->Pen->Color = clWhite/
		//Chart1->Canvas->Fill->Color = TAlphaColorRec::White;

//		lineSeriesCH1Signal->FastPen = true;
		chartSignal->Canvas->Rectangle(xIni, yIni, xFin, yFin); //->AssignBrushColor(clWhite)->;
		chartSignal->Canvas->ReferenceCanvas->Fill->Color = 0xFF3F3F3F;
		chartSignal->Canvas->ReferenceCanvas->Stroke->Color = 0xFF3F3F3F;
	}
	if (FChartXPos > PLOT_WINDOW)
		FChartXPos = 0;
}
//---------------------------------------------------------------------------

