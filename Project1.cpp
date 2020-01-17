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
                 AnsiString second = "Gracz pierwszy steruje paletk¹ klawiszami A - góra, Z - dó³";
                 AnsiString third = "Gracz drugi steruje paletk¹ strza³kami góra/dó³";
                 AnsiString fourth = "Dodatkowo odbicie œrodkiem przyspiesza pi³kê";
                 AnsiString fifth = "Gra toczy siê do 10 punktów. Mi³ej zabawy!";
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
