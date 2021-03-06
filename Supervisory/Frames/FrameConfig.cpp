//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "FrameConfig.h"
#include "IniFiles.hpp"
//---------------------------------------------------------------------------
#include "Classes/ClassConexaoSerial.cpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TfraConfig *fraConfig;
void (*Callback)();
//---------------------------------------------------------------------------
__fastcall TfraConfig::TfraConfig(TComponent* Owner)
	: TFrame(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfraConfig::btnGoBackClick(TObject *Sender)
{
	LoadDefaultValues();
	HidePopup();
}
//---------------------------------------------------------------------------
void TfraConfig::Init(TBlurEffect *blur, void (*PCallback)())
{
	FBlur = blur;
	Callback = PCallback;
	LoadComPorts();
	LoadDefaultValues();
	HidePopup();
}
//---------------------------------------------------------------------------
void TfraConfig::Save()
{
	TCustomIniFile *vIniFile = new TIniFile("./Config.ini");
	try
	{
		vIniFile->WriteInteger("SerialComm", "SerialPort", this->cbbSerialPort->ItemIndex);
		vIniFile->WriteInteger("SerialComm", "Baudrate", this->cbeBaudrate->ItemIndex);
      Callback();
	}
	catch(Exception* e)
	{
	}
	delete vIniFile;
}
//---------------------------------------------------------------------------
void TfraConfig::LoadDefaultValues()
{
	TCustomIniFile *vIniFile = new TIniFile("./Config.ini");
	try
	{
		this->cbbSerialPort->ItemIndex = vIniFile->ReadInteger("SerialComm", "SerialPort", -1);
		this->cbeBaudrate->ItemIndex = vIniFile->ReadInteger("SerialComm", "Baudrate", 4);
	}
	catch(Exception* e)
	{
	}
	delete vIniFile;
}
//---------------------------------------------------------------------------
void __fastcall TfraConfig::ShowPopup()
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
	} __finally {
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
	if ((cbeBaudrate->ItemIndex >= 0) || (cbeBaudrate->Text != EmptyAnsiStr))
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

void __fastcall TfraConfig::btnApplyClick(TObject *Sender)
{
	Save();
	HidePopup();
}
//---------------------------------------------------------------------------

