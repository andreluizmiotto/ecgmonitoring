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
#include <FMX.Layouts.hpp>
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
	TLayout *lytSerialPort;
	TButton *btnRefresh;
	void __fastcall btnGoBackClick(TObject *Sender);
	void __fastcall btnRefreshClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfraConfig(TComponent* Owner);
	void LoadComPorts();
	void ShowPopup();
   void HidePopup();
	AnsiString getSerialPort();
	AnsiString getBaudrate();
};
//---------------------------------------------------------------------------
extern PACKAGE TfraConfig *fraConfig;
//---------------------------------------------------------------------------
#endif
