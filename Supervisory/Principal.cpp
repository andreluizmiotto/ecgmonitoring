// ---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Principal.h"
#include <iostream>
#include "Threads/ThreadSerialBufferIn.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FrameConfig"
#pragma link "FrameChartView"
#pragma resource "*.fmx"
TfrmPrincipal *frmPrincipal;
ThreadSerialBufferIn *FThreadSerialBuffer;
bool FThreadRunning;

// ---------------------------------------------------------------------------
__fastcall TfrmPrincipal::TfrmPrincipal(TComponent* Owner) : TForm(Owner)
{
	this->tbcPrincipal->ActiveTab = this->tbiChart;
	this->ConfigChartSeries();
	fraConfig->Init(blurBackground);
	fraChartView->Init(blurBackground);
}
//---------------------------------------------------------------------------
void TfrmPrincipal::ConfigChartSeries()
{
	this->lineSeries->Clear();
	this->meSignal->Lines->Clear();

	/* Prepare chart for maximum speed */
	this->chartSignal->ClipPoints = false;
	this->chartSignal->Title->Visible = false;
	this->chartSignal->Legend->Visible = false;
	this->chartSignal->LeftAxis->Axis->Width = 1;
	this->chartSignal->BottomAxis->Axis->Width = 1;
	this->chartSignal->BottomAxis->RoundFirstLabel = false;
	this->chartSignal->View3D = false;

	unsigned int AFrequency = StrToIntDef(fraChartView->getFrequency(), 500);
	unsigned int ATimeWindow = StrToIntDef(fraChartView->getTimeWindow(), 10);
	unsigned int AMaxPoints = AFrequency * ATimeWindow;

	this->chartSignal->AutoRepaint = false; // For "real-time" drawing mode
	this->lineSeries->XValues->Order = loNone; // Increment speed when adding points

	this->chartSignal->LeftAxis->SetMinMax(0, 1023);
	this->chartSignal->BottomAxis->SetMinMax(0, AMaxPoints);

	this->chartSignal->Axes->FastCalc = true;

	for (unsigned int i = 0; i < AMaxPoints; i++)
		this->lineSeries->AddY(0);

   this->chartSignal->Repaint();
}
//---------------------------------------------------------------------------
void TfrmPrincipal::ConnectSerialPort()
{
	// Inicialização da porta serial.
	if (FThreadRunning) {
		ShowMessage("Thread is already running.");
		return;
	}
	SerialPort *vSerialPort = new SerialPort();
	try
	{
		bool AConnection = vSerialPort->OpenSerialPort(fraConfig->getSerialPort(), fraConfig->getBaudrate());
		if (!AConnection) {
			ShowMessage("Falha na conexão.");
			return;
		}
		btnConfig->Enabled = false;
		FThreadSerialBuffer = new ThreadSerialBufferIn(true, vSerialPort, chartSignal, lineSeries);
		FThreadSerialBuffer->Resume(); // Run the thread
		FThreadRunning = true;
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
	if (!FThreadRunning)
		return;
	FThreadSerialBuffer->Terminate();
	FThreadSerialBuffer = NULL;
	delete FThreadSerialBuffer;
	btnConfig->Enabled = true;
	FThreadRunning = false;
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
	ConfigChartSeries();
}
//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::btnConfigClick(TObject *Sender)
{
	fraConfig->ShowPopup();
}
//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::btnChartViewClick(TObject *Sender)
{
	fraChartView->ShowPopup();
}
//---------------------------------------------------------------------------


