// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Naveenkumar s Metamation India.
// ------------------------------------------------------------------
// Program.c
// c program to find the search and sort algorithm.
// ------------------------------------------------------------------------------------------------
#include"Header.h"
#include<conio.h>
#include <malloc.h>
#include<stdbool.h>
#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

static void ClrScreen () {
#ifdef _WIN32
   system ("cls");
#else
   system ("clear");
#endif 
}

/// <summary>To get the user input </summary>
static int UserInput (char* context) {
   long long int value = 0;
   while (1) {
      printf (context);
      char arr[13], * endptr = NULL;
      fgets (arr, 13, stdin);
      char* result = strchr (arr, '\n');// \n checking
      value = strtoll (arr, &endptr, 10);
      if (result == NULL) while (getchar () != '\n');
      if (result == NULL || value < INT32_MIN || value > INT32_MAX || *endptr != '\n' || arr[0] == '\n') {
         printf ("\033[31mInvalid!!! Re-enter\n\033[0m");
         continue;
      }
      break;
   }
   return (int)value;
}

/// <summary>To implement the sort and search algorithm </summary>
static int SortAndSearch () {
   int value = 0;
   do {
      value = UserInput ("\n\n\033[33mEnter the size:\033[0m"); //value varaiable pass dynamic memory allocate
      if (value <= 0) printf ("\033[31mINVALID\n\033[0m");
   } while (value <= 0);
   int* output = (int*)malloc (value * sizeof (int));
   if (output == NULL) {
      printf ("Memory allocation Failed");
      return 0;
   }
   printf ("\n\033[35mEnter the elements:\n\033[0m");
   for (int i = 0; i < value; i++) output[i] = UserInput ("");
   BubbleSort (output, value);
   printf ("\033[32mRESULT:\033[0m");
   for (int i = 0; i < value; i++)  printf ("%d ", output[i]);
   int res = BinarySearch (output, value, UserInput ("\n\033[36mEnter the element No to find the index:\033[0m "));
   printf ("\n\033[32mIndex position is: %d \033[0m", res);
   return 0;
}

/// <summary>Function to run the Sort test cases </summary>
static void SortTestCases () {
   printf ("\033[36m\n*****TestCases*****\n\n**********Sort**********\n\033[0m");
   int r0[] = { 20,19,-5,30,21,12 }, r1[] = { 55 ,54,8,4, }, r2[] = { -3,-5,2, }, r3[] = { 0,1,2,3,4 }, r4[] = { -1,-3,-2,-4, },
      r5[] = { -250,60,46,17,15 }, r6[] = { 223,2000,-287,78,-67,122 }, r7[] = { 2,3,4,5 },
      * jagged[] = { r0,r1,r2,r3,r4,r5,r6,r7 }, size[] = { 6,4,3,5,4,5,6,4 };
   for (int i = 0; i < 8; i++) {
      printf ("\n---------------------------------------------------------------------------------------------");
      printf ("\nInputArray:   ");
      for (int j = 0; j < size[i]; j++) printf ("%d ", jagged[i][j]);
      BubbleSort (jagged[i], size[i]);
      printf ("\nSorted Array:  ");
      for (int j = 0; j < size[i]; j++) printf ("%d ", jagged[i][j]);
      printf ("\nBubble Sort:   ");
      int k = 0;
      for (; k < size[i] - 1; k++)
         if (jagged[i][k + 1] < jagged[i][k]) {
            printf ("\033[31mFAIL\033[0m");
            break;
         }
      if (k == size[i] - 1) printf ("\033[32mPASS\033[0m");
   }
   printf ("\n---------------------------------------------------------------------------------------------");
}

/// <summary>Function to run the test cases </summary>
static void TestCases () {
   int r0[] = { 20,19,-5,30,21,12 }, r1[] = { 55 ,54,8,4, }, r2[] = { -3,-5,2, }, r3[] = { 0,1,2,3,4 },
      r4[] = { -1,-3,-2,-4, }, r5[] = { -250,60,46,17,15 }, r6[] = { 223,2000,-287,78,-67,122 }, r7[] = { 2,3,4,5 },
      * jagged[] = { r0,r1,r2,r3,r4,r5,r6,r7 },
      size[] = { 6,4,3,5,4,5,6,4 },
      iptarget[] = { 20,54,2,3,-2,17,78,5 },
      expectedArray[] = { 3,2,2,3,2,2,2,3 };
   printf ("\033[36m\n*****TestCases*****\n\n**********Binary Search**********\033[0m");
   for (int i = 0; i < 8; i++) {
      printf ("\n---------------------------------------------------------------------------------------------");
      BubbleSort (jagged[i], size[i]);
      int index = BinarySearch (jagged[i], size[i], iptarget[i]);
      printf ("\nKey:   %d\nIndex: %d\nBinary Search: ", iptarget[i], index);
      printf ((index == expectedArray[i]) ? "\033[32mPASS\033[0m" : "\033[31mFAIL\033[0m");
   }
   printf ("\n---------------------------------------------------------------------------------------------");
   printf ("\n");
}

int main () {
   for (;;) {
      printf ("\n*****CHOOSE*****\n1 = SortAndSearch\n2 = TestCases\n3 = ClearScreen\n4 = Exit\nChoose any option : \n");
      switch (_getch ()) {
      case '1':
         SortAndSearch ();
         break;
      case '2':
         SortTestCases ();
         TestCases ();
         break;
      case '3':
         ClrScreen ();
         break;
      case '4':
         return 0;
      default:
         printf ("\n\033[31mEnter a number between 1-4\n\033[0m");
      }
   }
   return 0;
}