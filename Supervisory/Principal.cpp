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

//---------------------------------------------------------------------------
void UpdateConfig()
{
	int ASamplingRate = StrToIntDef(frmPrincipal->fraChartView->getFrequency(), 400);
	int ATimeWindow = StrToIntDef(frmPrincipal->fraChartView->getTimeWindow(), 5);
	frmPrincipal->pltGrid->Frequency = frmPrincipal->pltGrid->Width/(5*ATimeWindow);
	frmPrincipal->pltChart->Bitmap->Resize(frmPrincipal->pltChart->Width, frmPrincipal->pltChart->Height);
	if (!FThreadRunning)
		return;
	if (FThreadFilePlotting != NULL) {
		FThreadFilePlotting->chartPlot->SetScreenSize(frmPrincipal->pltChart->Width, frmPrincipal->pltChart->Height);
		FThreadFilePlotting->chartPlot->SetSamplingRate(ASamplingRate);
		FThreadFilePlotting->chartPlot->SetTimeWindow(ATimeWindow);
		FThreadFilePlotting->chartPlot->Rewind();
	}
	if (FThreadSerialBuffer != NULL) {
		FThreadSerialBuffer->chartPlot->SetScreenSize(frmPrincipal->pltChart->Width, frmPrincipal->pltChart->Height);
		FThreadSerialBuffer->chartPlot->SetSamplingRate(ASamplingRate);
		FThreadSerialBuffer->chartPlot->SetTimeWindow(ATimeWindow);
		FThreadSerialBuffer->chartPlot->Rewind();
	}
}
// ---------------------------------------------------------------------------
__fastcall TfrmPrincipal::TfrmPrincipal(TComponent* Owner) : TForm(Owner)
{
	this->ClientWidth = 1600;
	this->ClientHeight = 900;
	this->fraConfig->Init(blurBackground, &UpdateConfig);
	this->fraChartView->Init(blurBackground, &UpdateConfig);
	this->pltChart->Bitmap = new TBitmap(frmPrincipal->pltChart->Width, frmPrincipal->pltChart->Height);
}
//---------------------------------------------------------------------------
ChartPlot * TfrmPrincipal::NewChartPlotObj()
{
	ChartPlot *vChartPlot = new ChartPlot(pltChart->Bitmap->Canvas);
	vChartPlot->SetInitialX(0);
	vChartPlot->SetInitialY(this->pltChart->Height/2);
	vChartPlot->SetScreenSize(this->pltChart->Width, this->pltChart->Height);
//	vChartPlot->SetYRange(-4, 4);
	vChartPlot->SetYRange(0, 1023);
	vChartPlot->SetSamplingRate(StrToIntDef(fraChartView->getFrequency(), 400));
	vChartPlot->SetTimeWindow(StrToIntDef(fraChartView->getTimeWindow(), 5));
	vChartPlot->SetDownsamplingRate(5);
	vChartPlot->EnableMovingAverage(5);

	vChartPlot->Rewind();
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
		FThreadSerialBuffer = new ThreadSerialBufferIn(true, vSerialPort, NewChartPlotObj());
		FThreadSerialBuffer->Start(); // Run the thread
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
		FThreadFilePlotting = new TThreadFilePlotting(true, dlgOpenFile->FileName, NewChartPlotObj());
		FThreadFilePlotting->Start(); // Run the thread
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
	this->btnConfig->Enabled = true;
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
   this->pltChart->Repaint();
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

void __fastcall TfrmPrincipal::FormResize(TObject *Sender)
{
	UpdateConfig();
}
//---------------------------------------------------------------------------



