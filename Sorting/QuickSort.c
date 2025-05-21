#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
};

void prtArr(int arr[], int n)
{
    printf("\n");

    for (int i = 0; i < n; i++)
    {
        printf("%i ", arr[i]);
    }
};

int Partiton(int *arr, int low, int high)
{
    int pivot = arr[high];
    int i = low;

    for (int j = i; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            swap(arr + j, arr + i);
            i++;
        }
    }
    swap(arr + high, arr + i);
    return i;
};

void QuickSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int pivot = Partiton(arr, low, high);
        QuickSort(arr, low, pivot - 1);
        QuickSort(arr, pivot + 1, high);
    }
}

int main()
{

    int arr[] = {10, 7, 7, 8, 9, 1, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    prtArr(arr, size); // Before

    QuickSort(arr, 0, size - 1);

    prtArr(arr, size); // After Sorting

    return 0;
}