// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// Program.c
// Program to calculate the minimum number of coins .
// Naveenkumar s
// ------------------------------------------------------------------------------------------------

#include<stdio.h>
#include<stdlib.h>

#define ANSI_COLOR_RED   "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_RESET   "\x1b[0m"

/// <summary>To calculate number of coins </summary>
static void CalculateBalance (int* denominations, int balance, int* count) {
   for (int i = 0; i < 4; i++) {
      count[i] = balance / denominations[i];
      balance = balance % denominations[i];
   }
}

/// <summary>Function to run the test cases </summary>
static void Testcase (int* denominations) {
   int inputs[] = { 55,65,80,49,37 }, expOutput[][5] = { { 5,1,0,0 },{6,1,0,0},{8,0,0,0},{4,1,2,0},{3,1,1,0} }, count[4],
      input = sizeof (inputs) / sizeof (inputs[0]);
   printf (ANSI_COLOR_YELLOW"\nTEST CASES\n"ANSI_COLOR_RESET);
   for (int i = 0; i < input; i++) {
      CalculateBalance (denominations, inputs[i], count);
      int j;
      for (j = 0; j < input; j++)
         if (count[j] != expOutput[i][j])
            break;
      printf (j == 4 ? ANSI_COLOR_GREEN"Passed\n"ANSI_COLOR_RESET : ANSI_COLOR_RED "Failed\n"ANSI_COLOR_RESET);
   }
}
int main () {
   char amount[50];
   int denominations[] = { 10, 5, 2, 1 }, count[4] = { 0 };
   int cashpaid, actualAmount;
   printf (ANSI_COLOR_GREEN"Enter the cash paid by the customer:"ANSI_COLOR_RESET);
   fgets (amount, sizeof (amount), stdin);
   cashpaid = atoi (amount);
   printf (ANSI_COLOR_GREEN"Enter the actual amount to be paid:"ANSI_COLOR_RESET);
   fgets (amount, sizeof (amount), stdin);
   actualAmount = atoi (amount);
   if (cashpaid < actualAmount)
      printf (ANSI_COLOR_RED"Error cash paid less than the actual amount"ANSI_COLOR_RESET);
   int balance = cashpaid - actualAmount;
   printf (ANSI_COLOR_GREEN"Total balance to be returned :%d\n"ANSI_COLOR_RESET, balance);
   printf (ANSI_COLOR_GREEN"Coins returned:"ANSI_COLOR_RESET);
   CalculateBalance (denominations, balance, count);
   for (int i = 0; i < 4; i++)
      if (count[i] > 0)
         printf (ANSI_COLOR_GREEN"Rs.%d: %d\n"ANSI_COLOR_RESET, denominations[i], count[i]);
   Testcase (denominations);
   return 0;
}