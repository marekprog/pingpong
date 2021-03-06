//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit3.h"
#include <iostream>
#include <string.h>
#include <sstream>
#include <dstring.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;


int x=-5;
int y=-5;
//Scores
int playerOne,playerTwo,roundNr, nrOfTurns;


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm1::timer_ballTimer(TObject *Sender)
{

    ball->Left+=x;
    ball->Top+=y;
    //odbicie od gornej sciany
    if(ball->Top -10 <= background->Top) y= -y;
    //odbicie od dolnej sciany
    if(ball->Top+ball->Height +10 >= background->Height) y= -y;
    //skucie
    if(ball->Left >= pad2->Left+20 || ball->Left <= pad1->Left-20)
    { timer_ball->Enabled=false ;
       restart->Visible=true;
       newGame->Visible=true;
       turns->Visible=true;
       score->Visible=true;
       turns->Caption="Number of turns: "+IntToStr(nrOfTurns);
       //std::to_string(nrOfTurns);
       nrOfTurns=0;
       if(ball->Left >= pad2->Left+20)playerOne++;
       if (ball->Left <= pad1->Left-20)playerTwo++;
       score->Caption="Score: "+IntToStr(playerOne)+" : "+IntToStr(playerTwo);
    }
    if(ball->Top > pad2->Top && ball->Top < (pad2->Top+pad2->Height) && ball->Left> pad2->Left-15)
    {
        if (x>0) x=-x;
        nrOfTurns++;
    }
    else if (ball->Top > pad1->Top && ball->Top < (pad1->Top+pad1->Height) && ball->Left < pad1->Left+15)
    {
        if (x<0) x=-x;
        nrOfTurns++;
    }


}
//---------------------------------------------------------------------------



void __fastcall TForm1::pad1timerUpTimer(TObject *Sender)
{
         if(pad1->Top >10)pad1->Top-=10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pad1timerDownTimer(TObject *Sender)
{
        if ((pad1->Top+105) < background->Height)pad1->Top +=10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key==0x51) pad1timerUp->Enabled=true;
        if(Key==0x41) pad1timerDown->Enabled=true;
        if(Key==VK_UP) pad2timerUp->Enabled=true;
        if(Key==VK_DOWN) pad2timerDown->Enabled=true;



}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
      if(Key==0x51) pad1timerUp->Enabled=false;
      if(Key==0x41) pad1timerDown->Enabled=false;
      if(Key==VK_UP) pad2timerUp->Enabled=false;
      if(Key==VK_DOWN) pad2timerDown->Enabled=false;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::pad2timerDownTimer(TObject *Sender)
{
    if ((pad2->Top+105) < background->Height)pad2->Top +=10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pad2timerUpTimer(TObject *Sender)
{
    if(pad2->Top >10)pad2->Top-=10;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::restartClick(TObject *Sender)
{
        timer_ball->Enabled=true;
        ball->Left=400;
        ball->Top=300;
        restart->Visible=false;
        newGame->Visible=false;
        turns->Visible=false;


}
//---------------------------------------------------------------------------






void __fastcall TForm1::levelsClick(TObject *Sender)
{
        Form3->Show();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::newGameClick(TObject *Sender)
{
        playerOne=0;
        playerTwo=0;
        roundNr=0;
        nrOfTurns=0;
        timer_ball->Enabled=true;
        ball->Left=400;
        ball->Top=300;
        newGame->Visible=false;
        restart->Visible=false;
        turns->Visible=false;


}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
AnsiString strWelcome = "Welcome to Ping Pong game";
	AnsiString strFirst = "1st player controls: 'q':up,'a':down";
	AnsiString strSecond = "2nd player controls: 'UP ARROW key':up. 'DOWN ARROW key':down";
	AnsiString strFinal = "Enjoy!";
       	ShowMessage(strWelcome + sLineBreak + strFirst + sLineBreak +
	 		strSecond + sLineBreak + strFinal);
}
//---------------------------------------------------------------------------

