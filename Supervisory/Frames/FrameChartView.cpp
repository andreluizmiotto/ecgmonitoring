//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "FrameChartView.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TfraChartView *fraChartView;
//---------------------------------------------------------------------------
__fastcall TfraChartView::TfraChartView(TComponent* Owner)
	: TFrame(Owner)
{
}
//---------------------------------------------------------------------------
void TfraChartView::Init(TBlurEffect *blur)
{
	FBlur = blur;
	HidePopup();
}
//---------------------------------------------------------------------------
void TfraChartView::ShowPopup()
{
	this->Visible = true;
	FBlur->Enabled = true;
}
//---------------------------------------------------------------------------
void TfraChartView::HidePopup()
{
	this->Visible = false;
	FBlur->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TfraChartView::btnGoBackClick(TObject *Sender)
{
	 this->HidePopup();
}
//---------------------------------------------------------------------------
AnsiString TfraChartView::getFrequency()
{
	AnsiString AResult = EmptyAnsiStr;
	if (cbeFrequency->ItemIndex >= 0)
		AResult = cbeFrequency->Text;
	return AResult;
}
//---------------------------------------------------------------------------
AnsiString TfraChartView::getTimeWindow()
{
	AnsiString AResult = EmptyAnsiStr;
	if (cbeTimeWindow->ItemIndex >= 0)
		AResult = cbeTimeWindow->Text;
	return AResult;
}
//---------------------------------------------------------------------------
