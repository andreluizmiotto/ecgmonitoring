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
bool FThreadSerialBufferRunning, FThreadFilePlottingRunning;

//---------------------------------------------------------------------------
void UpdateConfig()
{
	int ASamplingRate = StrToIntDef(frmPrincipal->fraChartView->getFrequency(), 400);
	int ATimeWindow = StrToIntDef(frmPrincipal->fraChartView->getTimeWindow(), 5);
	frmPrincipal->pltGrid->Frequency = frmPrincipal->pltGrid->Width/(5*ATimeWindow);
	frmPrincipal->pltChart->Bitmap->Resize(frmPrincipal->pltChart->Width, frmPrincipal->pltChart->Height);
	if (FThreadFilePlottingRunning) {
		FThreadFilePlotting->chartPlot->SetScreenSize(frmPrincipal->pltChart->Width, frmPrincipal->pltChart->Height);
		FThreadFilePlotting->chartPlot->SetSamplingRate(ASamplingRate);
		FThreadFilePlotting->chartPlot->SetTimeWindow(ATimeWindow);
		FThreadFilePlotting->chartPlot->Rewind();
	}
	if (FThreadSerialBufferRunning) {
		FThreadSerialBuffer->chartPlot->SetScreenSize(frmPrincipal->pltChart->Width, frmPrincipal->pltChart->Height);
		FThreadSerialBuffer->chartPlot->SetSamplingRate(ASamplingRate);
		FThreadSerialBuffer->chartPlot->SetTimeWindow(ATimeWindow);
		FThreadSerialBuffer->chartPlot->Rewind();
	}
}
// ---------------------------------------------------------------------------
__fastcall TfrmPrincipal::TfrmPrincipal(TComponent* Owner) : TForm(Owner)
{
	FThreadSerialBufferRunning = false;
	FThreadFilePlottingRunning = false;
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
	vChartPlot->SetScreenSize(this->pltChart->Width, this->pltChart->Height);
	vChartPlot->SetSamplingRate(StrToIntDef(fraChartView->getFrequency(), 400));
	vChartPlot->SetTimeWindow(StrToIntDef(fraChartView->getTimeWindow(), 5));
	vChartPlot->SetYBounds(3);
	vChartPlot->SetDownsamplingRate(1);
	vChartPlot->EnableMovingAverage(5);
	vChartPlot->Rewind();
	return vChartPlot;
}
//---------------------------------------------------------------------------
bool TfrmPrincipal::ThreadRunning(char *pResultMsg)
{
	if (FThreadSerialBufferRunning) {
		pResultMsg = "Serial read thread is already running.";
		return true;
	}
	if (FThreadFilePlottingRunning) {
		pResultMsg = "File read thread is already running.";
		return true;
	}
	return false;
}
//---------------------------------------------------------------------------
void TfrmPrincipal::StartSerialReading()
{
	char *pMsg;
	if (ThreadRunning(pMsg)) {
		ShowMessage(pMsg);
		return;
	}
	SerialPort *vSerialPort = new SerialPort();
	try
	{
		bool AConnection = vSerialPort->OpenSerialPort(fraConfig->getSerialPort(), fraConfig->getBaudrate());
		if (!AConnection) {
			ShowMessage("Failed to establish connection. Check the serial port and try again.");
			return;
		}
		btnConfig->Enabled = false;
		FThreadSerialBuffer = new ThreadSerialBufferIn(true, vSerialPort, NewChartPlotObj());
		FThreadSerialBuffer->Start(); // Run the thread
		FThreadSerialBufferRunning = true;
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		ShowMessage("Failed to establish connection. Check the serial port and try again.");
		CloseSerialPort();
	}
}
//---------------------------------------------------------------------------
void TfrmPrincipal::CloseSerialPort()
{
	if (!FThreadSerialBufferRunning)
		return;
	FThreadSerialBuffer->Terminate();
	FThreadSerialBuffer = NULL;
	delete FThreadSerialBuffer;
	btnConfig->Enabled = true;
	FThreadSerialBufferRunning = false;
}
//---------------------------------------------------------------------------
void TfrmPrincipal::StartFilePlotting()
{
	char *pMsg;
	if (ThreadRunning(pMsg)) {
		ShowMessage(pMsg);
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
		FThreadFilePlottingRunning = true;
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		ShowMessage("File reading failed. Try again.");
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
	if (!FThreadFilePlottingRunning)
		return;
	FThreadFilePlotting->Terminate();
	FThreadFilePlotting = NULL;
	delete FThreadFilePlotting;
	this->btnConfig->Enabled = true;
	FThreadFilePlottingRunning = false;
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
void __fastcall TfrmPrincipal::btnCleanChartClick(TObject *Sender)
{
	if (FThreadFilePlottingRunning)
		FThreadFilePlotting->chartPlot->Clean();
	if (FThreadSerialBufferRunning)
		FThreadSerialBuffer->chartPlot->Clean();
	this->pltChart->Bitmap->Clear(NULL);
}
//---------------------------------------------------------------------------

