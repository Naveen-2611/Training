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

/// <summary>Clears the buffer values </summary>
void ClrBuffer (char option) {
   for (;;) {
      option = fgetc (stdin);
      if (option == '\n' || option == EOF) break;
   }
}

/// <summary>Functions to print result</summary>
void PrintResult (bool value) {
   printf (value ? ("\nIt is a Palindrome\n\n") : ("\nIt is not a Palindrome\n\n"));
}

/// <summary>Clears the content on screen</summary>
void ClrScreen () {
#ifdef _WIN32
   system ("cls");
#endif 
}

/// <summary>Functions to check the given number is palindrome or not </summary>
bool NumberIsPalindrome (int num) {
   if (num < 0) {
      printf ("Output:%7s", "INVALID");
      return false;
   }
   int org = num;
   long long int rev = 0; // used to store reverse number exceeding integer range
   while (num != 0) {
      rev = rev * 10 + num % 10;
      num /= 10;
   }
   printf ("Output:%7lld", rev);
   return (rev == org);
}

/// <summary>Functions to check the given string is palindrome or not </summary>
bool StringIsPalindrome (char* sentences) {
   int i = 0, j = 0, length = 0;
   length = (int)strlen (sentences);
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
   char ch = '\n';
   char sentences[MAX_CHAR];
   printf ("\nEnter a sentences: ");
   char* j = fgets (sentences, sizeof (sentences), stdin);
   char* strResult = strchr (sentences, ch);
   if (j != NULL && sentences[0] != '\n' && strResult != NULL) {
      PrintResult (StringIsPalindrome (sentences));
   }
   else {
      printf ("INVALID!!!\n\n");
      ClrBuffer (option);
   }
}

/// <summary>Function to check test cases</summary>
void OutputCheck () {
   printf ("\n*****PALINDROME CHECK*****\n");
   char* strInput[] = { "Don't nod","I did, did I?", "racecar","Was it a car or a cat I saw?","Trumpf Metamation","RADAR","NASA","MALAYALAM"," NUN","LEVEL" };
   int strLength = sizeof (strInput) / sizeof (strInput[0]);
   for (int i = 0; i < strLength; i++) {
      printf ("Test Case%3d: Input--> %-28s ", i+1 , strInput[i]);
      printf ((StringIsPalindrome (strInput[i]) == true) ? "%-25s", "PASS\n" : "FAIL\n");
   }
   printf ("\n*****REVERSE A NUMBER*****\n");
   int numInput[] = { 0,94867,121,34543,8888,12542,-1,-111,154,12121 };
   int numLength = sizeof (numInput) / sizeof (numInput[0]);
   for (int i = 0; i < numLength; i++) {
      printf ("Test Case%3d: Input--> %-6d ", i + 1, numInput[i]);
      printf ((NumberIsPalindrome (numInput[i]) == true) ? " PASS\n" : " FAIL\n");
   }
   printf ("\n");
}

int main () {
   while (1) {
      int count = 0;
      printf ("1-Check Palindrome\n2-Reverse a Number\n3-Test Cases\n4-Clear The Screen\n5-Exit\nEnter an option:");
      char option = fgetc (stdin);
      int num = option;
      if (num != 10) {
         for (;;) {
            option = fgetc (stdin);
            if (option == '\n') break;
            count++;
         }
      }
      if (count == 0 && (num < 54 && num > 48)) {
         switch (num) {
         case '1':
            StringInput (option);
            break;
         case '2':
            IntegerInput (option);
            break;
         case '3':
            OutputCheck ();
            break;
         case '4':
            ClrScreen ();
            break;
         case '5':
            return 0;
            break;
         }
      }
      else printf ("Enter the number between 1-5\n\n");
   }
}