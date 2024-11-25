// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Naveenkumar S (c) Metamation India.
// ------------------------------------------------------------------
// ChessBoard
// Program on main branch.
// ------------------------------------------------------------------------------------------------
#include <corecrt.h>
#include <fcntl.h>
#include <io.h>
#include<stdio.h>

/// <summary> Function to comapare the characters </summary>
static void ChessBoardTest (char* output) {
   FILE* f1 = fopen ("Reference.txt", "r");
   FILE* f2 = fopen (output, "r");
   wint_t outChar = fgetwc (f2), refChar = fgetwc (f1);
   while (outChar != WEOF && refChar != WEOF)
      if (outChar != refChar) {
         wprintf (L"\x1b[31mTest case Failed\x1b[0m");
         break;
      }
      else {
         outChar = fgetwc (f2);
         refChar = fgetwc (f1);
      }
   wprintf (L"\x1b[32m Test case passed\x1b[0m\n");
}

void main () {
   int a = _setmode (_fileno (stdout), _O_U8TEXT);
   char* output = "outputfile.txt";
   FILE* f1 = fopen (output, "w ,ccs = UTF-8");
   if (f1 == NULL)wprintf (L"Unable to  open ");
   else {
      const wchar_t* const coins[] = { L"♜", L"♞", L"♝",L"♛",L"♚",L"♝",L"♞",L"♜",
            L"♖", L"♘", L"♗", L"♕", L"♔" , L"♗", L"♘", L"♖" };
      wprintf (L"┏━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┓\n");
      fputws (L"┏━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┓", f1);
      fputws (L"\n", f1);
      for (int i = 0; i < 8; i++) {
         wprintf (L"\u2503");
         fputws (L"\u2503", f1);
         for (int j = 0; j < 8; j++)
            switch (i) {
            case 0:
               wprintf (L" %s \u2503", coins[j]);
               fputws (L" ", f1);
               fputws (coins[j], f1);
               fputws (L" ", f1);
               fputws (L"\u2503", f1);
               break;
            case 1:
               wprintf (L" %s\u2503", L"\u265F");
               fputws (L" ", f1);
               fputws (L"\u2503", f1);
               fputws (L"\u265F", f1);
               break;
            case 6:
               wprintf (L" \u2659 \u2503");
               fputws (L" ", f1);
               fputws (L"\u2659", f1);
               fputws (L" ", f1);
               fputws (L"\u2503", f1);
               break;
            case 7:
               wprintf (L" %s \u2503", coins[8 + j]);
               fputws (L" ", f1);
               fputws (coins[8 + j], f1);
               fputws (L" ", f1);
               fputws (L"\u2503", f1);
               break;
            default:
               wprintf (L"   \u2503");
               fputws (L"   ", f1);
               fputws (L"\u2503", f1);
            }
         if (i < 7) {
            wprintf (L"\n┣━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━┫\n");
            fputws (L"\n", f1);
            fputws (L"┣━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━┫", f1);
            fputws (L"\n", f1);
         }
      }
      wprintf (L"\n┗━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┛\n");
      fputws (L"\n", f1);
      fputws (L"┗━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┛", f1);
      fputws (L"\n", f1);
      fclose (f1);
   }
   ChessBoardTest (output);
}