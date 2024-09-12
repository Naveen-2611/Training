// ------------------------------------------------------------------------------------------------
// Assignment 3 ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.Naveenkumar s
// ------------------------------------------------------------------
// Testcase.c
// Decimal to Binary conversion and Decimal to HexaDecimal conversion
// ------------------------------------------------------------------------------------------------
#include"conversionfile.h"

void PrintResult (int input[], char* output[], char* (*func)(int), int length) {
   for (int i = 0; i < length; i++) {
      printf ("TestCase%2d: input->%12d ", i + 1, input[i]);
      printf ((strcmp (func (input[i]), output[i]) == 0) ? ("%11s", "pass\n") : (" %11s", "Fail\n"));
   }
}

int main () {
   int arr[] = { -255,65535, 5125412, -592,859,-7587,865482,0,-1784587,INT_MIN,-2147483649ll };
   int len = sizeof (arr) / sizeof (arr[0]);
//checking the value for Hexadecimal value
   char* hex[] = { "FFFFFF01",
      "0000FFFF",
      "004E3524",
      "FFFFFDB0",
      "0000035B",
      "FFFFE25D",
      "000D34CA",
      "00000000",
      "FFE4C4F5",
      "80000000",
      "FFFFFFFF7FFFFFFF" };
//checking the value for Binaryvalue
   char* binary[] = { "11111111111111111111111100000001",
      "00000000000000001111111111111111",
      "00000000010011100011010100100100",
      "11111111111111111111110110110000",
      "00000000000000000000001101011011",
      "11111111111111111110001001011101",
      "00000000000011010011010011001010",
      "00000000000000000000000000000000",
      "11111111111001001100010011110101",
      "10000000000000000000000000000000",
   "1111111111111111111111111111111101111111111111111111111111111111" };

   printf ("*****DecimaltoBinary*****\n");
   PrintResult (arr, binary, DecimalToBinary, len);

   printf ("\n*****DecimaltoHexadecimal*****\n");
   PrintResult (arr, hex, DecimalToHexadecimal, len);

//To get an user input 
   while (1) {
      char input[100];
      int number = 0;
      char* endptr;
      printf ("\nEnter an integer: ");
      if (fgets (input, sizeof (input), stdin) != NULL) {
         errno = 0;
         number = strtol (input, &endptr, 10);
         if (endptr == input || *endptr != '\n' && *endptr != '\0' || input[0] == ' ') {
            printf ("INVALID!!!\n");
         }
         else if (errno == ERANGE) {
            printf ("INDEX OUT OF RANGE\n");
         }
         else {
            printf ("Binary value:%s", DecimalToBinary (number));
            printf ("\nHexadecimal value:%s\n", DecimalToHexadecimal (number));
            return 0;
         }
      }
      else {
         printf ("INVALID!!!\n");
      }
   }
   return 0;
}
