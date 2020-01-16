//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int verticalChange = -8;
int horizontalChange = -8;
int scoreLeft = 0;
int scoreRight = 0;


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



void __fastcall TForm1::TimerBallTimer(TObject *Sender)
{
    ball -> Left += horizontalChange;
    ball -> Top += verticalChange;

    // odbicie od góry
    if(ball -> Top - 5 < background -> Top) verticalChange = -verticalChange;

    // odbicie od do³u
    if(ball -> Top + ball -> Height + 5 > background -> Height) verticalChange = -verticalChange;

    // odbicie i nieudane odbicie od lewej paletki

    if(ball -> Left < paddleLeft -> Left)
    {
       TimerBall -> Enabled = false;
       ball -> Visible = false;
       scoreRight++;
       Label1 -> Caption = "Punkt dla gracza nr 2. Aktualny wynik: " + IntToStr(scoreLeft) + ":" + IntToStr(scoreRight);
       Label1 -> Visible = true;
       Button1 -> Visible = true;
    } else if((ball -> Top > paddleLeft -> Top - ball -> Height) &&
    (ball -> Top < paddleLeft -> Top + paddleLeft -> Height + ball -> Height) &&
    (ball -> Left <= paddleLeft -> Left + paddleLeft -> Width))
    {
     if(horizontalChange < 0) horizontalChange = -horizontalChange;
    }

     // odbicie i nieudane odbicie od prawej paletki

    if(ball -> Left > paddleRight -> Left)
    {
       TimerBall -> Enabled = false;
       ball -> Visible = false;
       scoreLeft++;
       Label1 -> Caption = "Punkt dla gracza nr 1. Aktualny wynik: " + IntToStr(scoreLeft) + ":" + IntToStr(scoreRight);
       Label1 -> Visible = true;
       Button1 -> Visible = true;
    } else if((ball -> Top > paddleRight -> Top - ball -> Height) &&
    (ball -> Top < paddleRight -> Top + paddleRight -> Height + ball -> Height) &&
    (ball -> Left + ball -> Width >= paddleRight -> Left))
    {
     if(horizontalChange > 0) horizontalChange = -horizontalChange;
    }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
   Button1 -> Visible = false;
   Label1 -> Visible = false;
   ball -> Left = 512;
   ball -> Top = 240;
   ball -> Visible = true;
   TimerBall -> Enabled = true;

}
//---------------------------------------------------------------------------

