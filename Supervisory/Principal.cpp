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
	this->ConfigChartSeries();
	fraConfig->LoadComPorts();
   fraConfig->HidePopup();
}
//---------------------------------------------------------------------------
void TfrmPrincipal::ConfigChartSeries()
{
	this->chartSignal->ClipPoints = false;
	this->chartSignal->Title->Visible = false;
	this->chartSignal->Legend->Visible = false;
	this->chartSignal->LeftAxis->Axis->Width = 1;
	this->chartSignal->BottomAxis->Axis->Width = 1;
	this->chartSignal->BottomAxis->RoundFirstLabel = false;
	this->chartSignal->View3D = false;
//	this->lineSeriesSignal->XValues->Order = loNone;
//	this->lineSeriesSignal->FastPen = true;

	this->ClearChartSeries();
}
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
		FSerialPort->OpenSerialPort(fraConfig->getSerialPort(), fraConfig->getBaudrate());
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
	this->lineSeriesSignal->Clear();
	this->chartSignal->Axes->Left->Minimum = 0;
	this->chartSignal->Axes->Left->Maximum = 1023;
	this->chartSignal->Axes->Bottom->Minimum = 0;
	this->chartSignal->Axes->Bottom->Maximum = PLOT_WINDOW;
	for (unsigned int i = 0; i < PLOT_WINDOW+1; i++)
		this->lineSeriesSignal->AddY(NULL);
	this->FChartXPos = 0;
	this->meSignal->Lines->Clear();
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

void __fastcall TfrmPrincipal::btnConfigClick(TObject *Sender)
{
	fraConfig->ShowPopup();
}
//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::chartSignalAfterDraw(TObject *Sender)
{

//	double xIni, xFin, yIni, yFin;
//
//	xIni = chartSignal->BottomAxis->CalcPosValue(FChartXPos - 1) - 8;
//	yIni = chartSignal->LeftAxis->CalcPosValue(chartSignal->LeftAxis->Minimum) - 1;
//	xFin = chartSignal->BottomAxis->CalcPosValue(FChartXPos - 1) + 8;
//	yFin = chartSignal->LeftAxis->CalcPosValue(chartSignal->LeftAxis->Maximum) + 1;
//
//	if (xFin < chartSignal->BottomAxis->CalcPosValue(chartSignal->BottomAxis->Maximum)+8)
//	{
//		//Chart1->Canvas->Pen->Style = psSolid;
//		//Chart1->Canvas->Pen->Color = clWhite;
//		//Chart1->Canvas->Brush->Color = clWhite;
//		//Chart1->Canvas->ReferenceCanvas->Pen->Color = clWhite/
//		//Chart1->Canvas->Fill->Color = TAlphaColorRec::White;
//
////		lineSeriesCH1Signal->FastPen = true;
//		chartSignal->Canvas->Rectangle(xIni, yIni, xFin, yFin); //->AssignBrushColor(clWhite)->;
//		chartSignal->Canvas->ReferenceCanvas->Fill->Color = 0xFF3F3F3F;
//		chartSignal->Canvas->ReferenceCanvas->Stroke->Color = 0xFF3F3F3F;
//	}
}
//---------------------------------------------------------------------------

