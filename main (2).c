#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a=*b;
    *b=temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low-1;
    for(int j=low;j<=high-1;j++)
    {
        if (arr[j]<=pivot)
        {
            i++;
            swap(&arr[j],&arr[i]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return (i+1);
}

void quicksort(int arr[], int low, int high)
{
    if (high>low)
    {
        int pi = partition(arr,low,high);
        quicksort(arr,low,pi - 1);
        quicksort(arr,pi+1,high);
    }
}

void printArray(int A[], int size) 
{
int i;
for (i = 0; i < size; i++)
printf("%d ", A[i]);
printf("\n"); 
}

int main()
{
    int arr[] = {18,1,69,3,5,14};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Given array is \n");
    printArray(arr, n);
    quicksort(arr, 0, n - 1);
    printf("\nSorted array is \n");
    printArray(arr, n);
    return 0; 
}