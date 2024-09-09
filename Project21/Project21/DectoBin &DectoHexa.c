// ------------------------------------------------------------------------------------------------
// Assignment 3 ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.Naveenkumar s
// ------------------------------------------------------------------
// Assignment 3
// Decimal to Binary conversion and Decimal to HexaDecimal conversion
// ------------------------------------------------------------------------------------------------
#define INT_SIZE sizeof(int)*8
#define HEX_SIZE 8

char binary[INT_SIZE + 1];
char hex[HEX_SIZE + 1];

/// <summary>Converts a decimal number to binary</summary>
char* DecimalToBinary (int n) {
   int index = INT_SIZE - 1;
   while (index >= 0) {
      binary[index--] = (n & 1) + '0';// Extract the least significant bit (LSB) from 'n' 
      n >>= 1;// Right-shift 'n' by one bit to remove the extracted bit 
   }
   binary[INT_SIZE] = '\0';
   return binary;
}

/// <summary>Converts a decimal number to Hexadecimal</summary>
char* DecimalToHexadecimal (int num) {
   // Array to store the hexadecimal digits  //Convert the input number to an unsigned integer 
   char hexChars[] = "0123456789ABCDEF";// Extract the last 4 bits (1 hex digit) 
   int index = HEX_SIZE;
   for (int i = index - 1; i >= 0; i--) {
      hex[i] = hexChars[num & 0xF];
      num >>= 4;
   }
   hex[index] = '\0';// Null - terminate the hex string
   return hex;
}