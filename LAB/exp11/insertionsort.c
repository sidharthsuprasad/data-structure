#include <stdio.h>
void insertionSort(int arr[], int n)
 {
    for (int i = 1; i < n; ++i)
     {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
 }
  void printArray(int arr[], int n)
   {
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
   }
    int main()
     {
      int arr[100];
      int size;
      printf("Enter the number of elements: ");
      scanf("%d", &size);
      if (size > 100 || size <= 0)
       {
        printf("Please enter a valid number of elements (1-100).\n");
        return 1; // Exit if invalid size
       }
        printf("Enter %d elements: ", size);
        for (int i = 0; i < size; i++)
         {
          scanf("%d", &arr[i]);
         }
         insertionSort(arr, size);
         printArray(arr, size);
         return 0;
     }
