// ---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Principal.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Threads/ThreadSerialBufferIn.h"
#include "Threads/ThreadFilePlotting.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "FrameConfig"
#pragma link "FrameChartView"
#pragma resource "*.fmx"
TfrmPrincipal *frmPrincipal;
ThreadSerialBufferIn *FThreadSerialBuffer;
TThreadFilePlotting *FThreadFilePlotting;
bool FThreadRunning;

// ---------------------------------------------------------------------------
__fastcall TfrmPrincipal::TfrmPrincipal(TComponent* Owner) : TForm(Owner)
{
	this->ClientWidth = 1280 + this->mvMenu->Width;
	this->ClientHeight = 720 + this->tbiChart->Height;
	this->tbcPrincipal->ActiveTab = this->tbiChart;
	fraConfig->Init(blurBackground);
	fraChartView->Init(blurBackground);
	this->ConfigChartSeries();
}
//---------------------------------------------------------------------------
void TfrmPrincipal::ConfigChartSeries()
{
//	this->lineSeries->Clear();
//	this->meSignal->Lines->Clear();

	/* Prepare chart for maximum speed */
//	this->chartSignal->ClipPoints = false;
//	this->chartSignal->Title->Visible = false;
//	this->chartSignal->Legend->Visible = false;
//	this->chartSignal->LeftAxis->Axis->Width = 1;
//	this->chartSignal->BottomAxis->Axis->Width = 1;
//	this->chartSignal->BottomAxis->RoundFirstLabel = false;
//	this->chartSignal->View3D = false;

	unsigned int AFrequency = StrToIntDef(fraChartView->getFrequency(), 400);
	unsigned int ATimeWindow = StrToIntDef(fraChartView->getTimeWindow(), 5);
	unsigned int AMaxPoints = AFrequency * ATimeWindow;

	pltChart->Canvas->Stroke->Thickness = 3;
	pltChart->Canvas->Stroke->Color = claLime;

//	this->chartSignal->AutoRepaint = false; // For "real-time" drawing mode
//	this->lineSeries->XValues->Order = loNone; // Increment speed when adding points

//	this->chartSignal->LeftAxis->SetMinMax(-2, 2);
//	this->chartSignal->BottomAxis->SetMinMax(0, AMaxPoints);

//	this->chartSignal->Axes->FastCalc = true;

//	for (unsigned int i = 0; i < AMaxPoints; i++)
//		this->lineSeries->AddY(0);
//
//	this->chartSignal->Repaint();
}
//---------------------------------------------------------------------------
ChartPlot * TfrmPrincipal::NewChartPlotObj()
{
	ChartPlot *vChartPlot = new ChartPlot(pltChart->Canvas);
	vChartPlot->SetInitialX(this->mvMenu->Width);
	vChartPlot->SetInitialY((this->pltChart->Height/2) + this->tbiChart->Height);
	vChartPlot->SetScreenSize(this->pltChart->Width, this->pltChart->Height);

	unsigned int AFrequency = StrToIntDef(fraChartView->getFrequency(), 400);
	unsigned int ATimeWindow = StrToIntDef(fraChartView->getTimeWindow(), 5);
	double AMaxPoints = AFrequency * ATimeWindow;
	vChartPlot->SetXMax(AMaxPoints);
   vChartPlot->SetDownsamplingRate(10);

	vChartPlot->Prepare();
	return vChartPlot;
}
//---------------------------------------------------------------------------
void TfrmPrincipal::StartSerialReading()
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
		FThreadSerialBuffer = new ThreadSerialBufferIn(true, vSerialPort, NewChartPlotObj(), meSignal);
		FThreadSerialBuffer->Resume(); // Run the thread
		FThreadRunning = true;
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		ShowMessage("Falha na conexão.");
		CloseSerialPort();
	}
}
//---------------------------------------------------------------------------
void TfrmPrincipal::CloseSerialPort()
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
void TfrmPrincipal::StartFilePlotting()
{
	// Inicialização da porta serial.
	if (FThreadRunning) {
		ShowMessage("Thread is already running.");
		return;
	}

	dlgOpenFile->Options.Clear();
	dlgOpenFile->Filter = "Text files (*.txt)|*.txt|All files (*.*)|*.*";
	if (!dlgOpenFile->Execute())
		return;
	try
	{
		btnConfig->Enabled = false;
		FThreadFilePlotting = new TThreadFilePlotting(true, dlgOpenFile->FileName, NewChartPlotObj(), meSignal);
		FThreadFilePlotting->Resume(); // Run the thread
		FThreadFilePlotting->OnTerminate = OnTerminateThread;
		FThreadRunning = true;
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		ShowMessage("Falha na leitura do arquivo.");
		CloseFile();
	}
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::OnTerminateThread(TObject *Sender)
{
	CloseFile();
}
//---------------------------------------------------------------------------
void TfrmPrincipal::CloseFile()
{
	if (!FThreadRunning)
		return;
	FThreadFilePlotting->Terminate();
	FThreadFilePlotting = NULL;
	delete FThreadFilePlotting;
	btnConfig->Enabled = true;
	FThreadRunning = false;
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::btnConnectClick(TObject *Sender)
{
	StartSerialReading();
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::btnDisconnectClick(TObject *Sender)
{
	CloseSerialPort();
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


void __fastcall TfrmPrincipal::btnOpenECGFileClick(TObject *Sender)
{
	StartFilePlotting();
}
//---------------------------------------------------------------------------
