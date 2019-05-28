//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TShape *background;
        TImage *ball;
        TTimer *timer_ball;
        TImage *pad1;
        TImage *pad2;
        TTimer *pad1timerDown;
        TTimer *pad1timerUp;
        TTimer *pad2timerDown;
        TTimer *pad2timerUp;
        TButton *restart;
        TButton *newGame;
        TLabel *Label1;
        TLabel *Label2;
        TButton *levels;
        TLabel *turns;
        TLabel *score;
        void __fastcall timer_ballTimer(TObject *Sender);
        void __fastcall pad1timerUpTimer(TObject *Sender);
        void __fastcall pad1timerDownTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall pad2timerDownTimer(TObject *Sender);
        void __fastcall pad2timerUpTimer(TObject *Sender);
        void __fastcall restartClick(TObject *Sender);
        void __fastcall levelsClick(TObject *Sender);
        void __fastcall newGameClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 