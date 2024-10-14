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

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

#define MAX 13
#define SIZE 6

void ClrScreen () {
#ifdef _WIN32
   system ("cls");
#endif 
}


void BubbleSort (int arr[], int n) {
   for (int i = 0; i < n - 1; i++) {
      bool swapped = false;
      for (int j = 0; j < n - i - 1; j++) {
         if (arr[j] > arr[j + 1]) {
            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
            swapped = true;
         }
      }
      if (swapped == false)
         break;
   }
}

int BinarySearch (int arr[], int n, int key) {
   int left = 0;
   int right = n - 1, result = -1;
   while (left <= right) {
      int mid = (left + right) / 2;
      if (arr[mid] == key) {
         result = mid;
         right = mid - 1;
      }
      else if (arr[mid] < key) {
         left = mid + 1;
      }
      else {
         right = mid - 1;
      }
   }return result;
}

int UserInput (char* context) {
   long long int value = 0;
   while (1) {
      printf (context);
      char arr[MAX];
      char* endptr = NULL;
      fgets (arr, MAX, stdin);
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

int SortAndSearch () {
   int value = UserInput ("\033[33mEnter the size:\033[0m"); //value varaiable pass dynamic memory allocate
   int* output = (int*)malloc (value * sizeof (int));
   if (output == NULL) {
      printf ("Memory allocation Failed");
      return;
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

void TestCases () {
   printf ("\033[36m\n*****TestCases*****\n\033[0m");
   int IpArray[][SIZE] = { {20,19,-5,30,21 }, 
                          {55 ,-214748,47,54,8,4,},
                          {-3,25,-7,-5,2,-21},
                          {0,1,2,3},
                          {0,-1,-3,-2 },
                          {-250,60,46,17},
                          {223,2000,-287,78,-67},
                          {2,3,4,5,6,7} },
      OutArray[][SIZE] = { {-5,19,20,21,30 },
                          { -214748 ,4,8,47,54,55},
                          {-21,-7,-5,-3,2,25},
                          {0,1,2,3},
                          {-3,-2,-1,0},
                          {-250,17,46,60},
                          {-287,-67,78,223,2000 },
                          {2,3,4,5,6,7} },
      arraySize = sizeof (IpArray) / sizeof (IpArray[0]), //array sizes
      sizes[] = { 5,6,6,4,4,4,5,6 }, iptarget[] = { 20,4,-7,2,-3,46,78,6, }, outIndex[] = { 2,1,1,2,0,2,2,4 }, result = 1;//sizes no of elements
   for (int i = 0; i < arraySize; i++) {
      int size = sizes[i];
      printf ("\nInputArray:   ");
      for (int j = 0; j < size; j++) printf ("%d ", IpArray[i][j]);
      BubbleSort (IpArray[i], size);
      printf ("\nSorted Array:  ");
      for (int j = 0; j < size; j++) printf ("%d ", IpArray[i][j]);
      printf ("\nBubble Sort:   ");
      for (int j = 0; j < size; j++)
         if (IpArray[i][j] != OutArray[i][j])  result = 0;
      printf ((result) ? "\033[32mPass\033[0m" : "\033[31mfail\033[0m");
      int index = BinarySearch (IpArray[i], size, iptarget[i]);
      printf ("\nKey:   %d\nIndex: %d\nBinary Search: ", iptarget[i], index);
      printf ((index == outIndex[i]) ? "\033[32mPASS\033[0m" :
              "\033[31mFAIL\033[0m");
   }
   printf ("\n");
}

int main () {
   for (;;) {
      printf ("\n*****CHOOSE*****\n");
      char* context = "1=SortAndSearch\n2=TestCases\n3=ClearScreen\n4=Exit\nChoose any option:";
      int number = UserInput (context);
      if (number > 4 || number < 1)
         printf ("\033[31mEnter a number between 1-4\n\033[0m");
      else {
         switch (number) {
         case 1:
            SortAndSearch ();
            break;
         case 2:
            TestCases ();
            break;
         case 3:
            ClrScreen ();
            break;
         case 4:
            return 0;
         }
      }
   }
   return 0;
}