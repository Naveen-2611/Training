// ------------------------------------------------------------------------------------------------
// Assignment 3 ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// Assignment 3
// Decimal to Binary conversion and Decimal to HexaDecimal conversion
// ------------------------------------------------------------------------------------------------
#include<stdio.h>
#define INT_SIZE sizeof(int)*8
#define HEX_SIZE 8

/// <summary>Function to convert a decimal number to binary</summary>
int DecimalToBinary (int n) {
   int index = 0;
   int binary[INT_SIZE];
   int num = n;
   index = INT_SIZE - 1;
   while (index >= 0) {
      binary[index--] = n & 1;// Extract the least significant bit (LSB) from 'n' 
      n >>= 1;// Right-shift 'n' by one bit to remove the extracted bit 
   }
   printf ("Binary value: ");
   for (int i = 0; i < INT_SIZE; i++)
      printf ("%d", binary[i]);
   printf ("\n");
   return num;
}

/// <summary>Function to convert a decimal number to Hexadecimal</summary>
void DecimalToHexadecimal (int num) {
   char hex[HEX_SIZE + 1];// Array to store the hexadecimal digits 
   unsigned int unsNum = (unsigned int)num; //Convert the input number to an unsigned integer 
   char hexChars[] = "0123456789ABCDEF";// Extract the last 4 bits (1 hex digit) 
   int index = HEX_SIZE;
   for (int i = index - 1; i >= 0; i--) {
      hex[i] = hexChars[unsNum & 0xF];
      unsNum >>= 4;
   }
   hex[index] = '\0';// Null - terminate the hex string
   printf ("Hexadecimal value: %s\n\n", hex);
}

int main () {
   int dec;
   char term;
   printf ("Enter decimal number: ");
   if (scanf_s ("%d%c", &dec, &term, 1) != 2 || term != '\n') {
      printf ("Invalid Number!\n");
      for (;;) {
         term = fgetc (stdin);
         if (term == EOF || term == '\n')
            break;
      }
   }
   else {
      int input = DecimalToBinary (dec);
      DecimalToHexadecimal (input);
   }
   return 0;
}
