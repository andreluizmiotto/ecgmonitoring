//---------------------------------------------------------------------------

#ifndef FrameChartViewH
#define FrameChartViewH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.ComboEdit.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.ImgList.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <System.ImageList.hpp>
#include "Lib/Utils.h"
//---------------------------------------------------------------------------
class TfraChartView : public TFrame
{
__published:	// IDE-managed Components
	TImageList *imgListChartView;
	TPanel *pnlBackground;
	TLabel *lblTimeWindow;
	TLayout *lytTimeWindow;
	TComboEdit *cbeTimeWindow;
	TToolBar *tlbChartView;
	TSpeedButton *btnGoBack;
	TSpeedButton *btnApply;
	TLabel *lblFrequency;
	TLayout *lytFrequency;
	TComboEdit *cbeFrequency;
	void __fastcall btnGoBackClick(TObject *Sender);
	void __fastcall btnApplyClick(TObject *Sender);
private:	// User declarations
	TBlurEffect *FBlur;
	void LoadComPorts();
	void LoadDefaultValues();
	void Save();
	void HidePopup();
public:		// User declarations
	__fastcall TfraChartView(TComponent* Owner);
	void Init(TBlurEffect *blur, void (*f)());
	void ShowPopup();
	AnsiString getFrequency();
	AnsiString getTimeWindow();
};
//---------------------------------------------------------------------------
extern PACKAGE TfraChartView *fraChartView;
//---------------------------------------------------------------------------
#endif
