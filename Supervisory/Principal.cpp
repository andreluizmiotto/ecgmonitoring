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
	this->tbcPrincipal->ActiveTab = this->tbiChart;
	fraConfig->Init(blurBackground);
	fraChartView->Init(blurBackground);
	this->ConfigChartSeries();
}
//---------------------------------------------------------------------------
void TfrmPrincipal::ConfigChartSeries()
{
	this->lineSeries->Clear();
	this->meSignal->Lines->Clear();

	/* Prepare chart for maximum speed */
//	this->chartSignal->ClipPoints = false;
//	this->chartSignal->Title->Visible = false;
//	this->chartSignal->Legend->Visible = false;
//	this->chartSignal->LeftAxis->Axis->Width = 1;
//	this->chartSignal->BottomAxis->Axis->Width = 1;
//	this->chartSignal->BottomAxis->RoundFirstLabel = false;
//	this->chartSignal->View3D = false;

	unsigned int AFrequency = 720;//StrToIntDef(fraChartView->getFrequency(), 400);
	unsigned int ATimeWindow = 10;//StrToIntDef(fraChartView->getTimeWindow(), 5);
	unsigned int AMaxPoints = AFrequency * ATimeWindow;

//	this->chartSignal->AutoRepaint = false; // For "real-time" drawing mode
//	this->lineSeries->XValues->Order = loNone; // Increment speed when adding points

	this->chartSignal->LeftAxis->SetMinMax(-2, 2);
	this->chartSignal->BottomAxis->SetMinMax(0, AMaxPoints);

//	this->chartSignal->Axes->FastCalc = true;

	for (unsigned int i = 0; i < AMaxPoints; i++)
		this->lineSeries->AddY(0);

	this->chartSignal->Repaint();
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
		this->tmrRepaintChart->Enabled = true;
		FThreadSerialBuffer = new ThreadSerialBufferIn(true, vSerialPort, chartSignal, lineSeries, meSignal);
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
	this->tmrRepaintChart->Enabled = false;
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
		this->tmrRepaintChart->Enabled = true;
		FThreadFilePlotting = new TThreadFilePlotting(true, dlgOpenFile->FileName, chartSignal, lineSeries, meSignal);
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
	this->tmrRepaintChart->Enabled = false;
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

void __fastcall TfrmPrincipal::tmrRepaintChartTimer(TObject *Sender)
{
	this->chartSignal->Repaint();
}
//---------------------------------------------------------------------------

