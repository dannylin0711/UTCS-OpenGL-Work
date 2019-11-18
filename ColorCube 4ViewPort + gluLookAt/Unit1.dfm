object Form1: TForm1
  Left = 171
  Top = 111
  Width = 313
  Height = 337
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
    Left = 0
    Top = 0
    Width = 297
    Height = 297
    OnGLInit = init
    OnGLDraw = graphicDraw
  end
end
