object Form1: TForm1
  Left = 468
  Top = 191
  Width = 825
  Height = 634
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
    Width = 601
    Height = 601
    Cursor = crDrag
    GLColorBits = 32
    OnGLInit = init
    OnGLDraw = graphicDraw
  end
  object RotateGroup: TGroupBox
    Left = 608
    Top = 56
    Width = 209
    Height = 177
    Caption = #26059#36681
    TabOrder = 1
    object XRotateLabel: TLabel
      Left = 8
      Top = 24
      Width = 19
      Height = 13
      Caption = 'X'#36600
    end
    object YRotateLabel: TLabel
      Left = 8
      Top = 64
      Width = 19
      Height = 13
      Caption = 'Y'#36600
    end
    object ZRotateLabel: TLabel
      Left = 8
      Top = 104
      Width = 19
      Height = 13
      Caption = 'Z'#36600
    end
    object XRotateAmount: TLabel
      Left = 96
      Top = 24
      Width = 6
      Height = 13
      Alignment = taCenter
      Caption = '0'
    end
    object YRotateAmount: TLabel
      Left = 96
      Top = 64
      Width = 6
      Height = 13
      Alignment = taCenter
      Caption = '0'
    end
    object ZRotateAmount: TLabel
      Left = 96
      Top = 104
      Width = 6
      Height = 13
      Alignment = taCenter
      Caption = '0'
    end
    object XRotateScrollBar: TScrollBar
      Left = 8
      Top = 40
      Width = 185
      Height = 17
      HelpType = htKeyword
      Max = 180
      Min = -180
      PageSize = 0
      TabOrder = 0
      OnChange = XRotateScrollBarChange
    end
    object YRotateScrollBar: TScrollBar
      Left = 8
      Top = 80
      Width = 185
      Height = 17
      Max = 180
      Min = -180
      PageSize = 0
      TabOrder = 1
      OnChange = YRotateScrollBarChange
    end
    object ZRotateScrollBar: TScrollBar
      Left = 8
      Top = 120
      Width = 185
      Height = 17
      Max = 180
      Min = -180
      PageSize = 0
      TabOrder = 2
      OnChange = ZRotateScrollBarChange
    end
    object ResetRotateButton: TButton
      Left = 112
      Top = 144
      Width = 81
      Height = 25
      Caption = #37325#32622
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS UI Gothic'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
      OnClick = ResetRotateButtonClick
    end
  end
  object MoveGroup: TGroupBox
    Left = 608
    Top = 240
    Width = 209
    Height = 177
    Caption = #24179#31227
    TabOrder = 2
    object XMoveLabel: TLabel
      Left = 8
      Top = 24
      Width = 19
      Height = 13
      Caption = 'X'#36600
    end
    object YMoveLabel: TLabel
      Left = 8
      Top = 64
      Width = 19
      Height = 13
      Caption = 'Y'#36600
    end
    object ZMoveLable: TLabel
      Left = 8
      Top = 104
      Width = 19
      Height = 13
      Caption = 'Z'#36600
    end
    object XMoveAmount: TLabel
      Left = 96
      Top = 24
      Width = 6
      Height = 13
      Alignment = taCenter
      Caption = '0'
    end
    object YMoveAmount: TLabel
      Left = 96
      Top = 64
      Width = 6
      Height = 13
      Alignment = taCenter
      Caption = '0'
    end
    object ZMoveAmount: TLabel
      Left = 96
      Top = 104
      Width = 6
      Height = 13
      Alignment = taCenter
      Caption = '0'
    end
    object XMoveScrollBar: TScrollBar
      Left = 8
      Top = 40
      Width = 185
      Height = 17
      HelpType = htKeyword
      Max = 200
      Min = -200
      PageSize = 0
      TabOrder = 0
      OnChange = XMoveScrollBarChange
    end
    object YMoveScrollBar: TScrollBar
      Left = 8
      Top = 80
      Width = 185
      Height = 17
      Max = 200
      Min = -200
      PageSize = 0
      TabOrder = 1
      OnChange = YMoveScrollBarChange
    end
    object ZMoveScrollBar: TScrollBar
      Left = 8
      Top = 120
      Width = 185
      Height = 17
      Max = 200
      Min = -200
      PageSize = 0
      TabOrder = 2
      OnChange = ZMoveScrollBarChange
    end
    object ResetMoveButton: TButton
      Left = 112
      Top = 144
      Width = 81
      Height = 25
      Caption = #37325#32622
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS UI Gothic'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
      OnClick = ResetMoveButtonClick
    end
  end
  object GroupBox3: TGroupBox
    Left = 608
    Top = 0
    Width = 209
    Height = 57
    Caption = #27169#24335
    TabOrder = 3
    object SingleMode: TRadioButton
      Left = 16
      Top = 24
      Width = 57
      Height = 17
      Caption = #21934#19968
      Checked = True
      TabOrder = 0
      TabStop = True
      OnClick = ChangeSingleMode
    end
    object MultiMode: TRadioButton
      Left = 120
      Top = 24
      Width = 57
      Height = 17
      Caption = #22810#20491
      TabOrder = 1
      OnClick = ChangeMultiMode
    end
  end
  object ScaleGroup: TGroupBox
    Left = 608
    Top = 424
    Width = 209
    Height = 177
    Caption = #32302#25918
    TabOrder = 4
    object XScaleLabel: TLabel
      Left = 8
      Top = 24
      Width = 19
      Height = 13
      Caption = 'X'#36600
    end
    object YScaleLabel: TLabel
      Left = 8
      Top = 64
      Width = 19
      Height = 13
      Caption = 'Y'#36600
    end
    object ZScaleLable: TLabel
      Left = 8
      Top = 104
      Width = 19
      Height = 13
      Caption = 'Z'#36600
    end
    object XScaleAmount: TLabel
      Left = 96
      Top = 24
      Width = 18
      Height = 13
      Alignment = taCenter
      Caption = '100'
    end
    object YScaleAmount: TLabel
      Left = 96
      Top = 64
      Width = 18
      Height = 13
      Alignment = taCenter
      Caption = '100'
    end
    object ZScaleAmount: TLabel
      Left = 96
      Top = 104
      Width = 18
      Height = 13
      Alignment = taCenter
      Caption = '100'
    end
    object XScaleScrollBar: TScrollBar
      Left = 8
      Top = 40
      Width = 185
      Height = 17
      HelpType = htKeyword
      Max = 200
      Min = -200
      PageSize = 0
      Position = 100
      TabOrder = 0
      OnChange = XScaleScrollBarChange
    end
    object YScaleScrollBar: TScrollBar
      Left = 8
      Top = 80
      Width = 185
      Height = 17
      Max = 200
      Min = -200
      PageSize = 0
      Position = 100
      TabOrder = 1
      OnChange = YScaleScrollBarChange
    end
    object ZScaleScrollBar: TScrollBar
      Left = 8
      Top = 120
      Width = 185
      Height = 17
      Max = 200
      Min = -200
      PageSize = 0
      Position = 100
      TabOrder = 2
      OnChange = ZScaleScrollBarChange
    end
    object ResetScaleGroup: TButton
      Left = 112
      Top = 144
      Width = 81
      Height = 25
      Caption = #37325#32622
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS UI Gothic'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
      OnClick = ResetScaleGroupClick
    end
    object ScaleCheckBox: TCheckBox
      Left = 8
      Top = 144
      Width = 97
      Height = 17
      Caption = #31561#27604#20363
      TabOrder = 4
      OnClick = checkScale
    end
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 1
    OnTimer = Timer1Timer
    Left = 160
    Top = 104
  end
end
