// ------------------------------------------------------------------------------------------------
// Assignment 3 ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.Naveenkumar s
// ------------------------------------------------------------------
// Testcase.c
// Decimal to Binary conversion and Decimal to HexaDecimal conversion
// ------------------------------------------------------------------------------------------------
#include"conversionfile.h"

/// <summary>Checks the user input whether its invalid or not </summary>
int GetInteger () {
   char input[100];
   int number = 0;
   char* endptr;
   printf ("\nEnter an integer: ");
   if (fgets (input, sizeof (input), stdin) != NULL) {
      errno = 0;
      number = strtol (input, &endptr, 10);
      if (endptr == input || *endptr != '\n' && *endptr != '\0' || (number == LONG_MAX || number == LONG_MIN) && errno == ERANGE 
          || number > INT_MAX || number <= INT_MIN || input[0] == ' ') {
         printf ("INVALID!!!\n");
         return INT_MIN;
      }
      else return number;
   }
   else {
      printf ("INVALID!!!\n");
      return INT_MIN;
   }
   return 0;
}

int main () {
   int arr[] = { -255,65535, 5125412, -592,859,-7587,865482,0,-1784587,-2147483648ll };
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
      "0071C688" };
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
      "00000000011100011100011010001000" };

   printf ("*****DecimaltoBinary*****\n");
   for (int i = 0; i < 10; i++) {
      char* binaryOutput = DecimalToBinary (arr[i]);
      printf ("TestCase%2d: input->%12d ", i + 1, arr[i]);
      printf ((strcmp (binaryOutput, binary[i]) == 0) ? ("%11s", "pass\n") : (" %11s", "Fail\n"));
   }
   printf ("\n*****DecimaltoHexadecimal*****\n");
   for (int i = 0; i < 10; i++) {
      char* HexOutput = DecimalToHexadecimal (arr[i]);
      printf ("TestCase%2d: input->%12d ", i + 1, arr[i]);
      printf ((strcmp (HexOutput, hex[i]) == 0) ? ("%11s", "pass\n") : (" %11s", "Fail\n"));
   }
       //To get an user input 
      while (1) {
         int dec = 0;
         dec = GetInteger ();
         if (dec != INT_MIN) {
            char* binary = DecimalToBinary (dec);
            printf ("Binary value:%s", binary);
            char* hex = DecimalToHexadecimal (dec);
            printf ("\nHexadecimal value:%s\n", hex);
            return 0;
         }
      }
      return 0;
   }