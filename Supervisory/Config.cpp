//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Config.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmConfig *frmConfig;
//---------------------------------------------------------------------------
__fastcall TfrmConfig::TfrmConfig(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmConfig::FormClose(TObject *Sender, TCloseAction &Action)
{
  if (MessageDlg("Sair sem salvar?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
	Action = caHide;
  else
	Action = caNone;
}
//---------------------------------------------------------------------------

