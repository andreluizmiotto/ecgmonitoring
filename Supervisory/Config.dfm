object frmConfig: TfrmConfig
  Left = 295
  Top = 243
  Align = alCustom
  Caption = 'Config'
  ClientHeight = 143
  ClientWidth = 225
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object grpBaudrate: TGroupBox
    AlignWithMargins = True
    Left = 3
    Top = 54
    Width = 219
    Height = 45
    Align = alTop
    Caption = 'Baudrate'
    TabOrder = 0
    object cbbBaudrate: TComboBox
      AlignWithMargins = True
      Left = 5
      Top = 18
      Width = 209
      Height = 21
      Align = alClient
      ItemIndex = 4
      TabOrder = 0
      Text = '115200'
      Items.Strings = (
        '9600'
        '19200'
        '38400'
        '57600'
        '115200')
    end
  end
  object grpSerialPort: TGroupBox
    AlignWithMargins = True
    Left = 3
    Top = 3
    Width = 219
    Height = 45
    Align = alTop
    Caption = 'Serial port'
    TabOrder = 1
    object cbbSerialPort: TComboBox
      AlignWithMargins = True
      Left = 5
      Top = 18
      Width = 209
      Height = 21
      Align = alClient
      TabOrder = 0
    end
  end
  object btnApply: TButton
    AlignWithMargins = True
    Left = 3
    Top = 105
    Width = 219
    Height = 32
    Align = alTop
    Caption = 'Aplicar'
    TabOrder = 2
  end
end
