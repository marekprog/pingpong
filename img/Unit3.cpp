//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button1Click(TObject *Sender)
{

   //difficulty->Close();
   //Form1->Show();
}
//---------------------------------------------------------------------------


void __fastcall TForm3::level1Click(TObject *Sender)
{
        Form1->timer_ball->Interval=25;
        Form3->Close();
}
//---------------------------------------------------------------------------


void __fastcall TForm3::level2Click(TObject *Sender)
{
        Form1->timer_ball->Interval=15;
        Form3->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::level3Click(TObject *Sender)
{
       Form1->timer_ball->Interval=5;
       Form3->Close();
}
//---------------------------------------------------------------------------

