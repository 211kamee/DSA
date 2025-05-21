#include <stdio.h>

void bubbleSort(int *arr, int size)
{
    // Keep bubbling the largest to the end
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1])
            {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
};

void insertionSort(int *arr, int size)
{
    // Take one and insert it at the right spot
    for (int i = 1; i < size; i++)
    {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
};

void selectionSort(int *arr, int size)
{
    // Select the smallest and put it in place
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
            if (arr[j] < arr[min])
                min = j;
        int t = arr[i];
        arr[i] = arr[min];
        arr[min] = t;
    }
};

int main()
{

    int arr1[] = {9, 9, 8, 7, 6, 5, 5, 4, 3, 2, 1, 1};
    int arr2[] = {9, 9, 8, 7, 6, 5, 5, 4, 3, 2, 1, 1};
    int arr3[] = {9, 9, 8, 7, 6, 5, 5, 4, 3, 2, 1, 1};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int size3 = sizeof(arr3) / sizeof(arr3[0]);

    for (int i = 0; i < size1; i++)
    {
        printf("%i ", arr1[i]);
    }
    printf("\n");

    bubbleSort(arr1, size1);
    for (int i = 0; i < size1; i++)
    {
        printf("%i ", arr1[i]);
    }
    printf("\n");

    insertionSort(arr2, size2);
    for (int i = 0; i < size2; i++)
    {
        printf("%i ", arr2[i]);
    }
    printf("\n");

    selectionSort(arr3, size3);
    for (int i = 0; i < size3; i++)
    {
        printf("%i ", arr3[i]);
    }
    printf("\n");

    return 0;
}