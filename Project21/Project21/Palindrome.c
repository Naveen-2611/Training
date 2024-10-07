// ------------------------------------------------------------------------------------------------
// Assignment4 ~ A training program for new joiners at Metamation, Batch - Sept 2024.
// Copyright (c) Naveenkumar S @Metamation India.
// ------------------------------------------------------------------
// Palindrome.c
// C program to Check whether string or an integer is Palindrome or not
// ------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_VALUE 100
#define MAX_CHAR 200

/// <summary>Clear the buffer values </summary>
void ClrBuffer (char option) {
   for (;;) {
      option = fgetc (stdin);
      if (option == '\n' || option == EOF) break;
   }
}

/// <summary>Function to print result</summary>
void PrintResult (bool value) {
   printf (value ? ("\nIt is a Palindrome\n\n") : ("\nIt is not a Palindrome\n\n"));
}

/// <summary>Clear the content on screen</summary>
void ClrScreen () {
#ifdef _WIN32
   system ("cls");
#endif 
}

/// <summary>Function to check the given number is palindrome or not </summary>
bool NumberIsPalindrome (int num) {
   int org = num;
   long long int rev = 0; // used to store reverse number exceeding integer range
   while (num != 0) {
      rev = rev * 10 + num % 10;
      num /= 10;
   }
   if (org < 0) {
      printf ("Output: %-7lld", rev);
      rev = -rev;
   }
   else printf ("Output: %-7lld", rev);
   return (rev == org);
}

/// <summary>Function to check the given string is palindrome or not </summary>
bool StringIsPalindrome (char* sentences) {
   int i = 0, j = 0, length = (int)strlen (sentences);
   char temp[MAX_CHAR];
   while (i < length) {
      if (isalnum (sentences[i]) != 0)
         temp[j++] = sentences[i];
      i++;
   }
   temp[j] = '\0';
   if (j == 0) return false;
   for (int n = 0; n < (j / 2); n++) {
      if (toupper (temp[n]) != toupper (temp[j - n - 1])) return false;
   }
   return true;
}

/// <summary>Function to get integer input from user</summary>
void IntegerInput (int option) {
   errno = 0;
   char input[MAX_VALUE];
   char* endptr;
   printf ("\nEnter an integer: ");
   char* i = fgets (input, sizeof (input), stdin);
   char* intResult = strchr (input, '\n');
   int number = strtol (input, &endptr, 10);
   if (intResult == NULL) ClrBuffer (option);
   if (i == NULL || endptr == input || *endptr != '\n' || input[0] == ' ' || input[0] == '\t') printf ("INVALID!!!\n\n");
   else if (errno == ERANGE) printf ("INPUT LIMIT EXCEEDED\n");
   else PrintResult (NumberIsPalindrome (number));
}

/// <summary>Function to get string input from user</summary>
void StringInput (int option) {
   char sentences[MAX_CHAR];
   printf ("\nEnter a sentence: ");
   char* j = fgets (sentences, sizeof (sentences), stdin);
   char* strResult = strchr (sentences, '\n');
   if (j != NULL && sentences[0] != '\n' && strResult != NULL)
      PrintResult (StringIsPalindrome (sentences));
   else {
      printf ("INVALID!!!\n\n");
      ClrBuffer (option);
   }
}

/// <summary>Function to check test cases</summary>
void OutputCheck () {
   printf ("\n*****PALINDROME CHECK*****\n");
   char* strInput[] = { "Don't nod","Able was I ere I saw Elba", "racecar","Otto","Trumpf Metamation","RADAR","NASA","MALAYALAM","Kayak","LEVEL" };
   int strExpected[] = { 1,1,1,1,0,1,0,1,1,1 };
   int strLength = sizeof (strInput) / sizeof (strInput[0]);
   for (int i = 0; i < strLength; i++) {
      int result = StringIsPalindrome (strInput[i]);
      printf ("Test Case%3d: Input--> %-28s ", i + 1, strInput[i]);
      printf ((result == strExpected[i]) ? " PASS\n" : " FAIL\n");
   }
   printf ("\n*****REVERSE A NUMBER*****\n");
   int NumInput[] = { 0,89756,121,34543,7777,13487,-1,-111,123,12121 };
   int NumExpected[] = { 1,0,1,1,1,0,0,0,0,1 };
   int numLength = sizeof (NumInput) / sizeof (NumInput[0]);
   for (int i = 0; i < numLength; i++) {
      int result1 = NumberIsPalindrome (NumInput[i]);
      printf ("Test Case%3d: Input--> %-6d ", i + 1, NumInput[i]);
      printf ((result1 == NumExpected[i]) ? " PASS\n" : " FAIL\n");
      //printf ((NumberIsPalindrome (NumInput[i]) == true) ? " PASS\n" : " FAIL\n");
   }
   printf ("\n");
}

int main () {
   while (1) {
      char choice[3];
      printf ("1-Check Palindrome\n2-Reverse a Number\n3-Test Cases\n4-Clear The Screen\n5-Exit\nEnter an option:");
      char* ptr = fgets (choice, sizeof (choice), stdin);
      char* result = strchr (choice, '\n');
      int num = atoi (choice);
      if (result == NULL)
         while (getchar () != '\n');
      if (ptr == NULL || result == NULL || isdigit (choice[0]) == 0 || num > 5 || num < 1)
         printf ("Enter the number between 1-5\n\n");

      else {
         switch (num) {
         case 1:
            StringInput (num);
            break;
         case 2:
            IntegerInput (num);
            break;
         case 3:
            OutputCheck ();
            break;
         case 4:
            ClrScreen ();
            break;
         case 5:
            return 0;
         }
      }
   }
   return 0;
}
