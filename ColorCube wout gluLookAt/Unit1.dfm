object Form1: TForm1
  Left = 192
  Top = 125
  Width = 554
  Height = 577
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object GLBox1: TGLBox
    Left = 8
    Top = 8
    Width = 529
    Height = 529
    OnGLInit = init
    OnGLDraw = graphicDraw
  end
end
