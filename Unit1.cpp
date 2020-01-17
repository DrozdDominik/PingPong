//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "mmsystem.h"

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
       sndPlaySound("snd/fail.wav", SND_ASYNC);
       TimerBall -> Enabled = false;
       ball -> Visible = false;
       scoreRight++;
       if(scoreRight >= 10)
       {
          Button2 -> Caption = "Wygrana gracza nr 2. Nowa gra?";
          Button2 -> Visible = true;
          sndPlaySound("snd/gameover.wav", SND_ASYNC);
       } else
       {
       Label1 -> Caption = "Punkt dla gracza nr 2. Aktualny wynik: " + IntToStr(scoreLeft) + ":" + IntToStr(scoreRight);
       Label1 -> Visible = true;
       Button1 -> Visible = true;
       }
    } else if((ball -> Top > paddleLeft -> Top - ball -> Height) &&
    (ball -> Top < paddleLeft -> Top + paddleLeft -> Height + ball -> Height) &&
    (ball -> Left <= paddleLeft -> Left + paddleLeft -> Width))
    { sndPlaySound("snd/ball.wav", SND_ASYNC);
     if(ball -> Top < paddleLeft -> Top + (paddleLeft -> Height / 2) + 35 &&
     ball -> Top > paddleLeft -> Top + (paddleLeft -> Height / 2) - 35 )
    {
      randomize();
      if(horizontalChange < 0) horizontalChange = -horizontalChange;
      if(TimerBall -> Interval > 12)
      {
      TimerBall -> Interval = TimerBall -> Interval - random(4);
      } else
      {
       if(horizontalChange < 0) horizontalChange = -(horizontalChange - random(5));
       verticalChange = random(10) + 3;
       TimerBall -> Interval = 4;
      }
    } else
    {
     if(horizontalChange < 0) horizontalChange = -horizontalChange;
    }
    }

     // odbicie i nieudane odbicie od prawej paletki

    if(ball -> Left > paddleRight -> Left)
    {
       sndPlaySound("snd/fail.wav", SND_ASYNC);
       TimerBall -> Enabled = false;
       ball -> Visible = false;
       scoreLeft++;
       if(scoreLeft >= 10)
       {
          Button2 -> Caption = "Wygrana gracza nr 1. Nowa gra?";
          Button2 -> Visible = true;
          sndPlaySound("snd/gameover.wav", SND_ASYNC);
       } else
       {
       Label1 -> Caption = "Punkt dla gracza nr 1. Aktualny wynik: " + IntToStr(scoreLeft) + ":" + IntToStr(scoreRight);
       Label1 -> Visible = true;
       Button1 -> Visible = true;
       }
    } else if((ball -> Top > paddleRight -> Top - ball -> Height) &&
    (ball -> Top < paddleRight -> Top + paddleRight -> Height + ball -> Height) &&
    (ball -> Left + ball -> Width >= paddleRight -> Left))
    {sndPlaySound("snd/ball.wav", SND_ASYNC);
     if(ball -> Top < paddleRight -> Top + (paddleRight -> Height / 2) + 35 &&
     ball -> Top > paddleRight -> Top + (paddleRight -> Height / 2) - 35 )
    {
      randomize();
      if(horizontalChange > 0) horizontalChange = -horizontalChange;
      if(TimerBall -> Interval > 12)
      {
      TimerBall -> Interval = TimerBall -> Interval - random(4);
      }else
      {
       if(horizontalChange > 0) horizontalChange = -(horizontalChange + random(5));
       verticalChange = random(10) + 3;
       TimerBall -> Interval = 4;
      }
    }else
     {
     if(horizontalChange > 0) horizontalChange = -horizontalChange;
     }
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
   randomize();
   verticalChange = -1* (random(5) + 5);
   horizontalChange = -1* (random(5) + 5);
   TimerBall -> Interval = 25;
   TimerBall -> Enabled = true;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
        Button2 -> Visible = false;
        Button1 -> Visible = false;
        Label1 -> Visible = false;
        scoreLeft = 0;
        scoreRight = 0;
        ball -> Top = 300;
        ball -> Left = 300;
        ball -> Visible = true;
        verticalChange = -8;
        horizontalChange = -8;
        TimerBall -> Interval = 25;
        TimerBall -> Enabled = true;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button3Click(TObject *Sender)
{
  paddleLeft -> Enabled = true;
  paddleRight -> Enabled = true;
  TimerBall -> Enabled = true;
  Button3 -> Visible = false;
}
//---------------------------------------------------------------------------

