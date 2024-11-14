// ------------------------------------------------------------------------------------------------
// Assignment4 ~ A training program for new joiners at Metamation, Batch - Sept 2024.
// Copyright (c) Naveenkumar S @Metamation India.
// ------------------------------------------------------------------
// Palindrome.c
// C program to Check whether string or an integer is Palindrome or not
// ------------------------------------------------------------------------------------------------


#include <ctype.h>
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VALUE 100
#define MAX_CHAR 200
#define PALINDROME 1
#define NOT_PALINDROME 0

/// <summary>Function to print result</summary>
static void PrintResult (bool value) {
   printf (value ? ("\nIt is a Palindrome\n\n") : ("\nIt is not a Palindrome\n\n"));
}

/// <summary>Clear the content on screen</summary>
static void ClrScreen () {
#ifdef _WIN32
   system ("cls");
#endif 
}
long long int NumReverse (int num) {
   long long int rev = 0; //to store reversed number exceeding int range
   while (num != 0) {
      rev = rev * 10 + num % 10;
      num /= 10;
   }
   return rev;
}

/// <summary>Function to check the given number is palindrome or not </summary>
static int IsNumPalindrome (int num, long long int* rev) {
   *rev = NumReverse (num);
   return (num < 0) ? NOT_PALINDROME : (*rev == num);
}

/// <summary>Function to check the given string is palindrome or not </summary>
static bool IsStringPalindrome (char* sentences) {
   int start = 0, isValid = 0, end = (int)strlen (sentences);
   while (start < end) {
      if (!isalnum (sentences[start])) {
         start++; continue;
      }
      if (!isalnum (sentences[end])) {
         end--; continue;
      }
      isValid = 1;
      if (toupper (sentences[start++]) != toupper (sentences[end--])) return false;
   }
   return true;
}

/// <summary>Function to get integer input from user</summary>
static void GetIntegerInput (int option) {
   errno = 0;
   char input[MAX_VALUE], * endptr, * intResult, * intInput;
   printf ("\nEnter an integer: ");
   intInput = fgets (input, sizeof (input), stdin);
   intResult = strchr (input, '\n');
   int number = strtol (input, &endptr, 10);
   if (intResult == NULL) while (getchar () != '\n');
   if (intInput == NULL || endptr == input || *endptr != '\n' || input[0] == ' ' || input[0] == '\t') printf ("INVALID!!!\n\n");
   else if (errno == ERANGE) printf ("INPUT LIMIT EXCEEDED\n");
   else {
      long long int reverse = 0;
      bool result = IsNumPalindrome (number, &reverse);
      printf ("Output: %-7lld   ", reverse);
      PrintResult (result);
   }
}

/// <summary>Function to get string input from user</summary>
static void GetStringInput (int option) {
   char sentences[MAX_CHAR], * charInput, * strResult;
   printf ("\nEnter a sentence: ");
   charInput = fgets (sentences, sizeof (sentences), stdin);
   strResult = strchr (sentences, '\n');
   if (charInput != NULL && sentences[0] != '\n' && strResult != NULL)
      PrintResult (IsStringPalindrome (sentences));
   else {
      printf ("INVALID!!!\n\n");
      while (getchar () != '\n');
   }
}

/// <summary>Function to check test cases</summary>
static void TestPalindrome () {
   printf ("\n*****PALINDROME CHECK*****\n");
   char* strInput[] = { "76567","Don't nod","Able was I ere I saw Elba","-123","666",
      "racecar","-333","Otto","Trumpf Metamation","RADAR","NASA","MALAYALAM","Kayak","LEVEL","abc!","RADAR123","121!#21","2147483648"};
   int strExpected[] = { 1,1,1,0,1,1,1,1,0,1,0,1,1,1,0,0,1,0 };
   printf ("|********************Input*************************|*********Expected**********|*****Output*****"
           "|*****Result*****\n");
   int strLength = sizeof (strInput) / sizeof (strInput[0]);
   for (int i = 0; i < strLength; i++) {
      int result = IsStringPalindrome (strInput[i]);
      char* output = NULL, * strOutput = NULL;
      (strExpected[i] == 1) ? (strOutput = "It is a Palindrome") : (strOutput = "It is not a Palindrome");
      output = result ? "Palindrome" : "Not palindrome";
      printf ("Test Case%3d: Input--> %-28s %-30s%-20s", i + 1, strInput[i], strOutput, output);
      printf (result == strExpected[i] ? "PASS\n" : " FAIL\n");
   }
}

static void TestReversal () {
   struct Mystruct {
      int resExpected;
      int  numExpected;
   }ResExpected[] = { {1,0},{0,65798},{1,121},{1,34543},{1,7777},{0,78431},{0,-1},{0,-111},{0,321},{1,12121,} };
   printf ("\n*****REVERSE A NUMBER*****\n");
   int numInput[] = { 0,89756,121,34543,7777,13487,-1,-111,123,12121, };
   printf ("|***********Input**********|******Expected******|****Output*****""|*****Result*****\n");
   int numLength = sizeof (numInput) / sizeof (numInput[0]);
   for (int i = 0; i < numLength; i++) {
      printf ("Test Case%3d: Input--> %-10d %-15d%-15d" ,i + 1, numInput[i], ResExpected[i].numExpected, ResExpected[i].resExpected);
      long long int reverse = 0;
      bool result = IsNumPalindrome (numInput[i], &reverse);
      printf ("Output: %-7lld   ", reverse);
      printf (reverse == ResExpected[i].numExpected && result == ResExpected[i].resExpected ? "PASS\n" : "FAIL\n");
   }
   printf ("\n");
}

int main () {
   while (1) {
      printf ("1-Check Palindrome\n2-Reverse a Number\n3-Test Cases\n4-Clear The Screen\n5-Exit\nEnter an option:");
      char choice[3], * ptr = fgets (choice, sizeof (choice), stdin), * result = strchr (choice, '\n');
      int num = atoi (choice);
      if (!result) while (getchar () != '\n');
      if (ptr == NULL || result == NULL || isdigit (choice[0]) == 0 || num > 5 || num < 1)
         printf ("Enter the number between 1-5\n\n");
      else {
         switch (num) {
         case 1:
            GetStringInput (num);
            break;
         case 2:
            GetIntegerInput (num);
            break;
         case 3:
            TestPalindrome ();
            TestReversal ();
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