//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "FrameConfig.h"
//---------------------------------------------------------------------------
#include "Classes/ClassConexaoSerial.cpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TfraConfig *fraConfig;
//---------------------------------------------------------------------------
__fastcall TfraConfig::TfraConfig(TComponent* Owner)
	: TFrame(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfraConfig::btnGoBackClick(TObject *Sender)
{
	 this->HidePopup();
}
//---------------------------------------------------------------------------
void TfraConfig::Init(TBlurEffect *blur)
{
	FBlur = blur;
	HidePopup();
   LoadComPorts();
}
//---------------------------------------------------------------------------
void TfraConfig::ShowPopup()
{
	this->Visible = true;
	FBlur->Enabled = true;
}
//---------------------------------------------------------------------------
void TfraConfig::HidePopup()
{
	this->Visible = false;
	FBlur->Enabled = false;
}
//---------------------------------------------------------------------------
void TfraConfig::LoadComPorts()
{
	SerialPort *ASerialPort = new SerialPort();
	TStringList *AComPorts;
	try {
		AComPorts = ASerialPort->LoadComPorts();
	}
	__finally
	{
		ASerialPort->CloseSerialPort();
		ASerialPort = NULL;
		delete ASerialPort;
	}
	for (auto AComPort : AComPorts)
		cbbSerialPort->Items->Add(AComPort.c_str());
	if (cbbSerialPort->Items->Count > 0)
		cbbSerialPort->ItemIndex = 0;
}
//---------------------------------------------------------------------------
AnsiString TfraConfig::getSerialPort()
{
	AnsiString AResult = EmptyAnsiStr;
	if (cbbSerialPort->ItemIndex >= 0)
		AResult = cbbSerialPort->Selected->Text;
	return AResult;
}
//---------------------------------------------------------------------------
AnsiString TfraConfig::getBaudrate()
{
	AnsiString AResult = EmptyAnsiStr;
	if (cbeBaudrate->ItemIndex >= 0)
		AResult = cbeBaudrate->Text;
	return AResult;
}
//---------------------------------------------------------------------------

void __fastcall TfraConfig::btnRefreshClick(TObject *Sender)
{
   this->LoadComPorts();
}
//---------------------------------------------------------------------------

void __fastcall TfraConfig::btnEditBaudrateClick(TObject *Sender)
{
   cbeBaudrate->SetFocus();
}
//---------------------------------------------------------------------------

