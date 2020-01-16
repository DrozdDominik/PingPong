//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerPaddleLeftUpTimer(TObject *Sender)
{
     if(paddleLeft -> Top >=10) paddleLeft -> Top -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerPaddleLeftDownTimer(TObject *Sender)
{
    if(paddleLeft -> Top + paddleLeft -> Height < background -> Height - 10) paddleLeft -> Top += 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key == 'A') TimerPaddleLeftUp -> Enabled = true;
    if(Key == 'Z') TimerPaddleLeftDown -> Enabled = true;
    if(Key == VK_UP) TimerPaddleRightUp -> Enabled = true;
    if(Key == VK_DOWN) TimerPaddleRightDown -> Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
     if(Key == 'A') TimerPaddleLeftUp -> Enabled = false;
     if(Key == 'Z') TimerPaddleLeftDown -> Enabled = false;
     if(Key == VK_UP) TimerPaddleRightUp -> Enabled = false;
     if(Key == VK_DOWN) TimerPaddleRightDown -> Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerPaddleRightDownTimer(TObject *Sender)
{
   if(paddleRight -> Top + paddleRight -> Height < background -> Height - 10) paddleRight -> Top += 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerPaddleRightUpTimer(TObject *Sender)
{
       if(paddleRight -> Top >= 10) paddleRight -> Top -= 10;
}
//---------------------------------------------------------------------------


