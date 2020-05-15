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
#include <FMX.ImgList.hpp>
#include <System.ImageList.hpp>
//---------------------------------------------------------------------------
class TfraConfig : public TFrame
{
__published:	// IDE-managed Components
	TComboBox *cbbBaudrate;
	TComboBox *cbbSerialPort;
	TLabel *lblSerialPort;
	TLabel *lblBaudrate;
	TToolBar *tlbConfig;
	TPanel *pnlBackground;
	TSpeedButton *btnGoBack;
	TSpeedButton *btnApply;
	TImageList *imgListConfig;
	void __fastcall btnGoBackClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfraConfig(TComponent* Owner);
	void LoadComPorts();
   void ShowPopup();
};
//---------------------------------------------------------------------------
extern PACKAGE TfraConfig *fraConfig;
//---------------------------------------------------------------------------
#endif
