// ------------------------------------------------------------------------------------------------
// Assignment 3 ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Metamation India.
// ------------------------------------------------------------------
// Assignment 3
// Decimal to Binary conversion and Decimal to HexaDecimal conversion
// ------------------------------------------------------------------------------------------------

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Variable to store the count of digits in the binary representation.
int mCount;
// Converts a decimal number to its binary representation
int* DecimalToBinary (int temp) {
   mCount = 0;// Initialize mCount to 0 to start counting the binary digits.
   int temp2 = temp, reminder;
   if (temp < 0)
      temp *= -1;
   int temp1 = temp;//Store the absolute value of temp in temp1
   //Counts the number of digits in the binary representation
   while (temp > 0) {
      reminder = temp % 2;
      temp /= 2;
      mCount++;
   }
   // Representing binary in multiples of 8-bits accordingly
   if (mCount % 8 != 0)
      mCount += (8 - (mCount % 8));
   int* binaryRev = NULL;
   binaryRev = (int*)malloc (mCount * sizeof (int));
   do {
      binaryRev = (int*)malloc (mCount * sizeof (int));
   } while (binaryRev == NULL);//Allocate memory for storing the binary digits in reverse order.
   /*Storing the remainders into binRev*/
   for (int i = 0; i < mCount; i++) {// Iterate through each digit in the binary representation.
      binaryRev[i] = temp1 % 2;
      temp1 /= 2;
   }
   if (temp2 >= 0) {
      int* binary;
      do {
         binary = (int*)malloc (mCount * sizeof (int));
      } while (binary == NULL);
      // Reverse storing the stored remainders
      for (int j = 0; j < mCount; j++)
         binary[j] = binaryRev[mCount - j - 1];
      return binary;
   }
   //Performing 2s compliment
   else {
      int* binary2sComp = NULL;
      do {
         binary2sComp = (int*)malloc (mCount * sizeof (int));
      } while (binary2sComp == NULL);
      //Complimenting each element of the array
      for (int k = 0; k < mCount; k++) {
         if (binaryRev[mCount - k - 1] == 0)
            binary2sComp[k] = 1;
         else
            binary2sComp[k] = 0;
      }
      free (binaryRev);// Deallocate the memory previously allocated for the binary digits array
      //Adding 1 to the the binary number (stored as individual digits)
      for (int k = mCount - 1; k >= 0; k--)
         if (binary2sComp[k] == 0) {
            binary2sComp[k] = 1;
            break;
         }
         else {
            binary2sComp[k] = 0;
         }
      return binary2sComp;
   }
}
// Converts a decimal number to its hexadecimal representation
char* DecimalToHexadecimal (int temp) {
   mCount = 0;
   int temp2 = temp, reminder;
   if (temp < 0)
      temp *= -1;
   int temp1 = temp;
   //Counting the number of digits in hex representation
   while (temp > 0) {
      reminder = temp % 16;
      temp /= 16;
      mCount++;
   }

   // Representing hex in multiples of 8-bits accordingly
   if (mCount % 8 != 0)
      mCount += (8 - (mCount % 8));

   char* hexadecimalRev = NULL;
   do {
      hexadecimalRev = (char*)malloc (mCount * sizeof (char));
   } while (hexadecimalRev == NULL);
   //Storing the remainders into hexa
   for (int i = 0; i < mCount; i++) {
      if (temp1 % 16 >= 10)
         hexadecimalRev[i] = (temp1 % 16) + 55;
      else
         hexadecimalRev[i] = (temp1 % 16) + 48;
      temp1 /= 16;
   }
   if (temp2 >= 0) {
      char* hexa = NULL;
      do {
         hexa = (char*)malloc (mCount + 1 * sizeof (char));
      } while (hexa == NULL);
      int j;
      // Reverse storing the stored reaminders
      for (j = 0; j < mCount; j++)
         hexa[j] = hexadecimalRev[mCount - j - 1];
      hexa[j] = '\0';
      free (hexadecimalRev);
      return hexa;
   }
   else {
      int* binary = DecimalToBinary (temp2);// Convert the original number to its binary representation and store in the binary array.
      int digit = 0, place = 0, icount = 0, count = mCount / 4;

      if (count % 8 != 0)
         count += (8 - (count % 8));

      char* hexaNegativeRev = NULL;
      do {
         hexaNegativeRev = (char*)malloc (count * sizeof (char));
      } while (hexaNegativeRev == NULL);

      int index = 0;
      for (int i = mCount - 1; i >= 0; i--) {
         digit += binary[i] * pow (2, place);
         place++;
         icount++;
         if (icount == 4) {
            place = 0;
            icount = 0;
            if (digit >= 10)
               hexaNegativeRev[index] = digit + 55;// Convert digits 10-15 to their corresponding hexadecimal characters
            else
               hexaNegativeRev[index] = digit + 48;// Convert digits 0 - 9 to their corresponding ASCII characters
            index++;
            digit = 0;
         }
      }

      while (index < count) {
         hexaNegativeRev[index] = 'F';
         index++;
      }

      mCount = count;

      char* hexaNegative = NULL;
      do {
         hexaNegative = (char*)malloc (mCount + 1 * sizeof (char));
      } while (hexaNegative == NULL);

      int k;
      for (k = 0; k < mCount; k++)
         hexaNegative[k] = hexaNegativeRev[mCount - k - 1];

      hexaNegative[k] = '\0';
      free (hexaNegativeRev);
      return hexaNegative;
   }
}

int main () {
   int temp;
   printf ("Enter the Number: ");
   scanf_s ("%d", &temp);

   int* binary = DecimalToBinary (temp);// Convert the input number to its binary representation and store in the binary array.

   printf ("Binary No is: ");
   for (int i = 0; i < mCount; i++)
      printf ("%d", binary[i]);

   char* hexa = DecimalToHexadecimal (temp);// Convert the input number to its hexadecimal representation and store in the hexa string.
   printf ("\nHexadecimal No is: ");
   for (int i = 0; i < mCount; i++)
      printf ("%c", hexa[i]);

   free (binary);// Deallocate the memory previously allocated for the binary digits array.
   free (hexa); // Deallocate the memory previously allocated for the hexadecimal representation string.
   return 0;
}