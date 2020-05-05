//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "FrameConfig.h"
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
    fraConfig->Visible = false;
}
//---------------------------------------------------------------------------

