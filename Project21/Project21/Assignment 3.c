////// ------------------------------------------------------------------------------------------------
//// Assignment 3 ~ A training program for new joiners at Metamation, Batch - July 2024.
//// Copyright (c) Metamation India.
//// ------------------------------------------------------------------
//// Assignment 3
//// Decimal to Binary conversion and Decimal to HexaDecimal conversion
//// ------------------------------------------------------------------------------------------------
#include<stdio.h>
#define INT_SIZE sizeof(int) * 8
#define HEX_SIZE 8

int DecimalToBinary () {// Function to convert a decimal number to binary
   int n = 0, index = 0;// Declare variables: 'n' to store the input number
   int binary[INT_SIZE]; // Array to store the binary representation of the number
   printf ("Enter decimal number:");
   int m = scanf ("%d", &n);
   int num = n;
   index = INT_SIZE - 1;
   while (index >= 0) {
      binary[index] = n & 1;// Extract the least significant bit (LSB) from 'n' and store it in the binary array at the current index
      index--;// Decrement the index to move to the next position in the array
      n >>= 1;// Right-shift 'n' by one bit to remove the extracted bit and prepare for the next iteration
   }
   printf ("Binary value: ");
   for (int i = 0; i < INT_SIZE; i++)
      printf ("%d", binary[i]);// Print each bit of the binary array from the most significant bit to the least significant bit
   printf ("\n");
   return num;
}
void DecimalToHexadecimal (int num) {
   char hex[HEX_SIZE + 1];// Array to store the hexadecimal digits plus one extra character for the null
   unsigned int unsNum = (unsigned int)num; //Convert the input number to an unsigned integer for proper bitwise operations
   char hexChars[] = "0123456789ABCDEF";// Extract the last 4 bits (1 hex digit) and map it to the corresponding hex character
   int index = HEX_SIZE;
   for (int i = index - 1; i >= 0; i--) {
      hex[i] = hexChars[unsNum & 0xF];
      unsNum >>= 4;
   }
   hex[index] = '\0';// Null - terminate the hex string
   printf ("Hexadecimal value: %s\n\n", hex);
}

void main () {
   int input = DecimalToBinary ();
   DecimalToHexadecimal (input);
}
