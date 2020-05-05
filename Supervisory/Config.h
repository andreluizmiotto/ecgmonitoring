// ---------------------------------------------------------------------------

#ifndef ConfigH
#define ConfigH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>

// ---------------------------------------------------------------------------
class TfrmConfig : public TForm {
__published: // IDE-managed Components
	TGroupBox *grpSerialPort;
	TComboBox *cbbSerialPort;
	TGroupBox *grpBaudrate;
	TComboBox *cbbBaudrate;
	TButton *btnApply;

	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);

private: // User declarations
public: // User declarations
	__fastcall TfrmConfig(TComponent* Owner);
};

// ---------------------------------------------------------------------------
extern PACKAGE TfrmConfig *frmConfig;
// ---------------------------------------------------------------------------
#endif
