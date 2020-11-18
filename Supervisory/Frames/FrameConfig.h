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
#include <FMX.ComboEdit.hpp>
#include <FMX.Edit.hpp>
//---------------------------------------------------------------------------
class TfraConfig : public TFrame
{
__published:	// IDE-managed Components
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
	TLayout *lytBaudrate;
	TButton *btnEditBaudrate;
	TComboEdit *cbeBaudrate;
	void __fastcall btnGoBackClick(TObject *Sender);
	void __fastcall btnRefreshClick(TObject *Sender);
	void __fastcall btnEditBaudrateClick(TObject *Sender);
	void __fastcall btnApplyClick(TObject *Sender);
private:	// User declarations
	TBlurEffect *FBlur;
	void LoadComPorts();
	void LoadDefaultValues();
	void Save();
	void HidePopup();
public:		// User declarations
	__fastcall TfraConfig(TComponent* Owner);
	void Init(TBlurEffect *blur, void (*PCallback)());
	void __fastcall ShowPopup();
	AnsiString getSerialPort();
	AnsiString getBaudrate();
};
//---------------------------------------------------------------------------
extern PACKAGE TfraConfig *fraConfig;
//---------------------------------------------------------------------------
#endif
