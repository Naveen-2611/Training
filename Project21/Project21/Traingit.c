// ------------------------------------------------------------------------------------------------
// Training ~ A training program for new joiners at Metamation, Batch - July 2024.
// Copyright (c) Naveenkumar s Metamation India.
// ------------------------------------------------------------------
// Program.c
// c program to find the search and sort algorithm.
// ------------------------------------------------------------------------------------------------
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include"Header.h"
#include<conio.h>


void ClrScreen () {
#ifdef _WIN32
   system ("cls");
#else
   system ("clear");
#endif 
}


/// <summary>To get the user input </summary>
int UserInput (char* context) {
   long long int value = 0;
   while (1) {
      printf (context);
      char arr[13];
      char* endptr = NULL;
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
int SortAndSearch () {
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
   for (int i = 0; i < value; i++) {
      output[i] = UserInput ("");
   }
   BubbleSort (output, value);
   printf ("\033[32mRESULT:\033[0m");
   for (int i = 0; i < value; i++) {
      printf ("%d ", output[i]);
   }
   int res = BinarySearch (output, value, UserInput ("\n\033[36mEnter the element No to find the index:\033[0m "));
   printf ("\n\033[32mIndex position is: %d \033[0m", res);
   return 0;
}

/// <summary>Function to run the test cases </summary>
void TestCases () {
   printf ("\033[36m\n*****TestCases*****\n\033[0m");
   int ipArray[][6] = { {20,19,-5,30,21,12 },
                          {55 ,-214748,47,54,8,4,},
                          {-3,25,-7,-5,2,-21},
                          {0,1,2,3,4,5},
                          {0,-1,-3,-2,-4,-5 },
                          {-250,60,46,17,15,20},
                          {223,2000,-287,78,-67,122},
                          {2,3,4,5,6,7} },
      OutArray[][6] = { {-5,12,19,20,21,30 },
                          { -214748 ,4,8,47,54,55},
                          {-21,-7,-5,-3,2,25},
                          {0,1,2,3,4,5},
                          {-5,-4,-3,-2,-1,0},
                          {-250,15,17,20,46,60},
                          {-287,-67,78,122,223,2000 },
                          {2,3,4,5,6,7} },
      arraySize = sizeof (ipArray) / sizeof (ipArray[0]), //array sizes
      iptarget[] = { 20,4,-7,2,-3,46,78,6, }, outIndex[] = { 3,1,1,2,2,4,2,4 }, result = 1;//sizes no of elements
   for (int i = 0; i < arraySize; i++) {
      int size = sizeof (ipArray[i]) / sizeof (ipArray[i][0]);
      printf ("\nInputArray:   ");
      for (int j = 0; j < size; j++) printf ("%d ", ipArray[i][j]);
      BubbleSort (ipArray[i], size);
      printf ("\nSorted Array:  ");
      for (int j = 0; j < size; j++) printf ("%d ", ipArray[i][j]);
      printf ("\nBubble Sort:   ");
      for (int j = 0; j < size; j++)
         if (ipArray[i][j] != OutArray[i][j])  result = 0;
      printf ((result) ? "\033[32mPass\033[0m" : "\033[31mfail\033[0m");
      int index = BinarySearch (ipArray[i], size, iptarget[i]);
      printf ("\nKey:   %d\nIndex: %d\nBinary Search: ", iptarget[i], index);
      printf ((index == outIndex[i]) ? "\033[32mPASS\033[0m" :
              "\033[31mFAIL\033[0m");
   }
   printf ("\n");
}

int main () {
   for (;;) {
      printf ("\n*****CHOOSE*****\n1 = SortAndSearch\n2 = TestCases\n3 = ClearScreen\n4 = Exit\nChoose any option : ");
      char choice = _getch ();
         switch (choice) {
         case '1':
            SortAndSearch ();
            break;
         case '2':
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