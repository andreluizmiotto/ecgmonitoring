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
	 this->Visible = false;
}
//---------------------------------------------------------------------------
void TfraConfig::ShowPopup()
{
	this->Visible = true;
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



