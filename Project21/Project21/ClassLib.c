#include"Header.h "
#include<stdbool.h>

int Swap (int* a, int* b) {
   if (*a > *b) {
      int temp = *a;
      *a = *b;
      *b = temp;
      return 1;
   }
   return 0;
}

void BubbleSort (int arr[], int n) {
   for (int i = 0; i < n - 1; i++) {
      int isSwapped = 0;
      for (int j = 0; j < n - i - 1; j++)
         isSwapped = Swap (&arr[j], &arr[j + 1]);
      if (!isSwapped) break;
   }
}


int BinarySearch (int arr[], int n, int key) {
   int left = 0, right = n - 1, result = -1;
   while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] == key) {
         result = mid;
         right = mid - 1;
      }
      else if (arr[mid] < key) left = mid + 1;
      else right = mid - 1;
   } return result;
}
