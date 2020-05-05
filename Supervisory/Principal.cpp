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
}
//---------------------------------------------------------------------------
void TfrmPrincipal::LoadCommPorts()
{
	TCHAR lpTargetPath[5000]; // buffer to store the path of the COMPORTS
	for(int i=0; i<255; i++) // checking ports from COM0 to COM255
	{
		std::string AComPort = "COM" + std::to_string(i);
		DWORD ASuccess = QueryDosDevice(charToWChar(AComPort.c_str()), charToWChar((LPSTR)lpTargetPath), 5000);

		if(ASuccess!=0)
		{
			fraConfig->cbbSerialPort->Items->Add(AComPort.c_str());
			fraConfig->cbbSerialPort->ItemIndex = 0;
		}

		if(::GetLastError()==ERROR_INSUFFICIENT_BUFFER)
		{
		}
	}
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
	lineSeriesCH1Signal->Clear();
	chtCH1Signal->Axes->Left->Minimum = 0;
	chtCH1Signal->Axes->Left->Maximum = 0;
	chtCH1Signal->Axes->Bottom->Minimum = 0;
	chtCH1Signal->Axes->Bottom->Maximum = PLOT_WINDOW;
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
	LoadCommPorts();
}
//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::btnConfigClick(TObject *Sender)
{
	fraConfig->Visible = true;
}
//---------------------------------------------------------------------------

