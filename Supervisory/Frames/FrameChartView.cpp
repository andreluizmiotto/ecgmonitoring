//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "FrameChartView.h"
#include "IniFiles.hpp"
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
	LoadDefaultValues();
	HidePopup();
}
//---------------------------------------------------------------------------
void TfraChartView::Save()
{
	TCustomIniFile *vIniFile = new TIniFile("./Config.ini");
	try
	{
		vIniFile->WriteInteger("ChartView", "Frequency", this->cbeFrequency->ItemIndex);
		vIniFile->WriteInteger("ChartView", "TimeWindow", this->cbeTimeWindow->ItemIndex);
	}
	catch(Exception* e)
	{
	}
	delete vIniFile;
}
//---------------------------------------------------------------------------
void TfraChartView::LoadDefaultValues()
{
	TCustomIniFile *vIniFile = new TIniFile("./Config.ini");
	try
	{
		this->cbeFrequency->ItemIndex = vIniFile->ReadInteger("ChartView", "Frequency", 2);
		this->cbeTimeWindow->ItemIndex = vIniFile->ReadInteger("ChartView", "TimeWindow", 2);
	}
	catch(Exception* e)
	{
	}
	delete vIniFile;
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
	LoadDefaultValues();
	HidePopup();
}
//---------------------------------------------------------------------------
AnsiString TfraChartView::getFrequency()
{
	AnsiString AResult = EmptyAnsiStr;
	if ((cbeFrequency->ItemIndex >= 0) || (cbeFrequency->Text != EmptyAnsiStr))
		AResult = cbeFrequency->Text;
	return AResult;
}
//---------------------------------------------------------------------------
AnsiString TfraChartView::getTimeWindow()
{
	AnsiString AResult = EmptyAnsiStr;
	if ((cbeTimeWindow->ItemIndex >= 0) || (cbeTimeWindow->Text != EmptyAnsiStr))
		AResult = cbeTimeWindow->Text;
	return AResult;
}
//---------------------------------------------------------------------------
void __fastcall TfraChartView::btnApplyClick(TObject *Sender)
{
	Save();
	HidePopup();
}
//---------------------------------------------------------------------------


