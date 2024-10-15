 #include"Header.h "
#include<stdbool.h>

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