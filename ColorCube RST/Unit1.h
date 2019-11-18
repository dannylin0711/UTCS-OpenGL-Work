//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "GLCtrl.h"
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TGLBox *GLBox1;
    TTimer *Timer1;
    TRadioButton *SingleMode;
    TRadioButton *MultiMode;
    TGroupBox *RotateGroup;
    TScrollBar *XRotateScrollBar;
    TLabel *XRotateLabel;
    TScrollBar *YRotateScrollBar;
    TLabel *YRotateLabel;
    TScrollBar *ZRotateScrollBar;
    TLabel *ZRotateLabel;
    TButton *ResetRotateButton;
    TGroupBox *MoveGroup;
    TLabel *XMoveLabel;
    TLabel *YMoveLabel;
    TLabel *ZMoveLable;
    TScrollBar *XMoveScrollBar;
    TScrollBar *YMoveScrollBar;
    TScrollBar *ZMoveScrollBar;
    TButton *ResetMoveButton;
    TGroupBox *GroupBox3;
    TGroupBox *ScaleGroup;
    TLabel *XScaleLabel;
    TLabel *YScaleLabel;
    TLabel *ZScaleLable;
    TScrollBar *XScaleScrollBar;
    TScrollBar *YScaleScrollBar;
    TScrollBar *ZScaleScrollBar;
    TButton *ResetScaleGroup;
        TCheckBox *ScaleCheckBox;
    TLabel *XRotateAmount;
    TLabel *YRotateAmount;
    TLabel *ZRotateAmount;
    TLabel *XMoveAmount;
    TLabel *YMoveAmount;
    TLabel *ZMoveAmount;
    TLabel *XScaleAmount;
    TLabel *YScaleAmount;
    TLabel *ZScaleAmount;
    void __fastcall init(TObject *Sender);
    void __fastcall graphicDraw(TObject *Sender);
    void __fastcall Timer1Timer(TObject *Sender);
    void __fastcall XRotateScrollBarChange(TObject *Sender);
    void __fastcall YRotateScrollBarChange(TObject *Sender);
    void __fastcall ZRotateScrollBarChange(TObject *Sender);
    void __fastcall XMoveScrollBarChange(TObject *Sender);
    void __fastcall YMoveScrollBarChange(TObject *Sender);
    void __fastcall ZMoveScrollBarChange(TObject *Sender);
    void __fastcall XScaleScrollBarChange(TObject *Sender);
    void __fastcall YScaleScrollBarChange(TObject *Sender);
    void __fastcall ZScaleScrollBarChange(TObject *Sender);
    void __fastcall ResetRotateButtonClick(TObject *Sender);
    void __fastcall ResetMoveButtonClick(TObject *Sender);
    void __fastcall ResetScaleGroupClick(TObject *Sender);
    void __fastcall ChangeSingleMode(TObject *Sender);
    void __fastcall ChangeMultiMode(TObject *Sender);
    void __fastcall checkScale(TObject *Sender);



private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
