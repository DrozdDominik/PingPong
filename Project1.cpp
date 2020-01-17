//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("Unit1.cpp", Form1);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TForm1), &Form1);
                 AnsiString first = "Witaj w grze PingPong";
                 AnsiString second = "Gracz pierwszy steruje paletk� klawiszami A - g�ra, Z - d�";
                 AnsiString third = "Gracz drugi steruje paletk� strza�kami g�ra/d�";
                 AnsiString fourth = "Dodatkowo odbicie �rodkiem przyspiesza pi�k�";
                 AnsiString fifth = "Gra toczy si� do 10 punkt�w. Mi�ej zabawy!";
                 ShowMessage(first + sLineBreak + second + sLineBreak + third + sLineBreak + fourth + sLineBreak + fifth);
                 Application->Run();

        }catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------
