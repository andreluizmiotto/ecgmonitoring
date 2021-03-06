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
		FThreadFilePlotting->chartPlot->SetSamplingRate(ASamplingRate);
		FThreadFilePlotting->chartPlot->SetTimeWindow(ATimeWindow);
		FThreadFilePlotting->chartPlot->Rewind();
	}
	if (FThreadSerialBufferRunning) {
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
	this->ClientWidth = 1000;
	this->ClientHeight = 600;
	this->fraConfig->Init(blurBackground, &UpdateConfig);
	this->fraChartView->Init(blurBackground, &UpdateConfig);
	this->pltChart->Bitmap = new TBitmap(frmPrincipal->pltChart->Width, frmPrincipal->pltChart->Height);
}
//---------------------------------------------------------------------------
ChartPlot * TfrmPrincipal::NewChartPlotObj()
{
	ChartPlot *vChartPlot = new ChartPlot(pltChart->Bitmap->Canvas);
	vChartPlot->SetSamplingRate(StrToIntDef(fraChartView->getFrequency(), 400));
	vChartPlot->SetTimeWindow(StrToIntDef(fraChartView->getTimeWindow(), 5));
	vChartPlot->SetYBounds(3);
	vChartPlot->SetDownsamplingRate(1);
	vChartPlot->EnableMovingAverage(5);
	vChartPlot->Rewind();
	return vChartPlot;
}
//---------------------------------------------------------------------------
bool TfrmPrincipal::ThreadRunning(bool pShowMsg)
{
	if (FThreadSerialBufferRunning) {
		if (pShowMsg)
			ShowMessage("Serial read thread is running.");
		return true;
	}
	if (FThreadFilePlottingRunning) {
		if (pShowMsg)
			ShowMessage("File read thread is running.");
		return true;
	}
	return false;
}
//---------------------------------------------------------------------------
void TfrmPrincipal::StartSerialReadingThread()
{
	if (ThreadRunning(true))
		return;
	SerialPort *vSerialPort = new SerialPort();
	try
	{
		bool AConnection = vSerialPort->OpenSerialPort(fraConfig->getSerialPort(), fraConfig->getBaudrate());
		if (!AConnection) {
			ShowMessage("Failed to establish connection. Check the serial port and try again.");
			return;
		}
		FThreadSerialBuffer = new ThreadSerialBufferIn(true, vSerialPort, NewChartPlotObj());
		FThreadSerialBuffer->Start(); // Run the thread
		FThreadSerialBufferRunning = true;
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		ShowMessage("Failed to establish connection. Check the serial port and try again.");
		TerminateSerialReadingThread();
	}
}
//---------------------------------------------------------------------------
void TfrmPrincipal::TerminateSerialReadingThread()
{
	if (!FThreadSerialBufferRunning)
		return;
	FThreadSerialBuffer->Terminate();
	FThreadSerialBuffer = NULL;
	delete FThreadSerialBuffer;
	FThreadSerialBufferRunning = false;
}
//---------------------------------------------------------------------------
void TfrmPrincipal::StartFilePlottingThread()
{
	if (ThreadRunning(true))
		return;

	dlgOpenFile->Options.Clear();
	dlgOpenFile->Filter = "ECG files (*.ecg)|*.ecg|All files (*.*)|*.*";
	if (!dlgOpenFile->Execute())
		return;
	try
	{
		FThreadFilePlotting = new TThreadFilePlotting(true, dlgOpenFile->FileName, NewChartPlotObj());
		FThreadFilePlotting->Start(); // Run the thread
		FThreadFilePlotting->OnTerminate = OnTerminateThread;
		FThreadFilePlottingRunning = true;
	}
	__except(EXCEPTION_EXECUTE_HANDLER)
	{
		ShowMessage("File reading failed. Try again.");
		TerminateFilePlottingThread();
	}
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::OnTerminateThread(TObject *Sender)
{
	TerminateFilePlottingThread();
}
//---------------------------------------------------------------------------
void TfrmPrincipal::TerminateFilePlottingThread()
{
	if (!FThreadFilePlottingRunning)
		return;
	FThreadFilePlotting->Terminate();
	FThreadFilePlotting = NULL;
	delete FThreadFilePlotting;
	FThreadFilePlottingRunning = false;
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::btnConnectClick(TObject *Sender)
{
	StartSerialReadingThread();
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::btnDisconnectClick(TObject *Sender)
{
	TerminateSerialReadingThread()
	;
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::btnConfigClick(TObject *Sender)
{
	TThread::Synchronize(NULL, fraConfig->ShowPopup);
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::btnChartViewClick(TObject *Sender)
{
	TThread::Synchronize(NULL, fraChartView->ShowPopup);
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::btnOpenECGFileClick(TObject *Sender)
{
	StartFilePlottingThread();
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
