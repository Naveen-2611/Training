// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// Naveenkumar s
// ------------------------------------------------------------------
// Boardgame.c
// Tic Tac Toe
// ------------------------------------------------------------------------------------------------

#include <stdio.h>

#define DRAW -1
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_RESET   "\x1b[0m"

/// <summary>Function to initialize the board </summary>
void InitializeBoard (char board[3][3]) {
   for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
         board[i][j] = ' ';
}

/// <summary>Function to print the board </summary>
void PrintBoard (char board[3][3]) {
   printf ("\n");
   for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
         printf (" %c ", board[i][j]);
         if (j < 2) printf ("|");
      }
      printf ("\n");
      if (i < 2) printf ("---|---|---\n");
   }
   printf ("\n");
}

/// <summary>Function to check the winner status board </summary>
int CheckWinner (char board[3][3]) {
   for (int i = 0; i < 3; i++) {
      if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ' &&
          board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') return 1;
   }
   if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ' &&
       board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') return 1;
   for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++)
         if (board[i][j] == ' ') return 0;
   }
   return DRAW;
}

/// <summary>Function to get the user input</summary>
void PlayGame (char board[3][3]) {
   int move, next = 0;
   char player;
   while (1) {
      player = (next % 2 == 0) ? 'X' : 'O';
      PrintBoard (board);
      printf (ANSI_COLOR_BLUE"Player %c, Enter No (1-9): "ANSI_COLOR_RESET, player);
      scanf_s ("%d", &move);
      if (move < 1 || move > 9) {
         printf (ANSI_COLOR_MAGENTA "Invalid .\n"ANSI_COLOR_RESET);
         continue;
      }
      int row = (move - 1) / 3;
      int colu = (move - 1) % 3;
      if (board[row][colu] != ' ') {// To check if the box is already occupied
         printf ("Invalid Move\n");
         continue;
      }
      board[row][colu] = player;
      int result = CheckWinner (board);
      if (result == 1) {
         PrintBoard (board);
         printf (ANSI_COLOR_GREEN"Player %c wins!\n"ANSI_COLOR_RESET, player);
         break;
      }
      else if (result == -1) {
         PrintBoard (board);
         printf ("It's a draw!\n");
         break;
      }
      next++;
   }
}

int main () {
   char board[3][3];
   printf ("Welcome to Tic Tac Toe\n");
   printf (ANSI_COLOR_YELLOW "Player X and Player O"ANSI_COLOR_RESET);
   InitializeBoard (board);
   PlayGame (board);
   return 0;
}