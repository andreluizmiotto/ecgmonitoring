//---------------------------------------------------------------------------

#ifndef FrameConfigH
#define FrameConfigH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.ListBox.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Objects.hpp>
//---------------------------------------------------------------------------
class TfraConfig : public TFrame
{
__published:	// IDE-managed Components
	TComboBox *cbbBaudrate;
	TComboBox *cbbSerialPort;
	TLabel *lblSerialPort;
	TLabel *lblBaudrate;
	TButton *btnApply;
	TToolBar *tlbConfig;
	TSpeedButton *btnGoBack;
	TImage *img1;
	void __fastcall btnGoBackClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfraConfig(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfraConfig *fraConfig;
//---------------------------------------------------------------------------
#endif
