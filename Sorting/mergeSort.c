#include <stdio.h>
#include <stdlib.h>

void mergeSortedArray(int *arr, int initialIndex, int m, int finalIndex)
{
	int *temp_arr = (int *)malloc((finalIndex - initialIndex + 1) * sizeof(int));

	int i_index = m, j_index = finalIndex;
	int i = initialIndex, j = m + 1, k = 0;

	while (i <= i_index && j <= j_index)
	{
		if (arr[i] <= arr[j])
		{
			temp_arr[k] = arr[i];
			k++;
			i++;
		}
		else
		{
			temp_arr[k] = arr[j];
			k++;
			j++;
		}
	}
	while (i <= i_index)
	{
		temp_arr[k] = arr[i];
		k++;
		i++;
	}
	while (j <= j_index)
	{
		temp_arr[k] = arr[j];
		k++;
		j++;
	}

	for (int i = initialIndex, k = 0; i <= finalIndex; i++)
	{
		arr[i] = temp_arr[k++];
	}
	printf("\n");

	free(temp_arr);
}

void mergeSort(int *arr, int initialIndex, int finalIndex)
{
	if (initialIndex < finalIndex)
	{
		const int m = initialIndex + (finalIndex - initialIndex) / 2;
		mergeSort(arr, initialIndex, m);
		mergeSort(arr, m + 1, finalIndex);

		mergeSortedArray(arr, initialIndex, m, finalIndex);
	}
}

int main()
{
	int arr[] = {11, 10, 9, 1, 5, 2, 6, 7, 3, 4, 8};
	int len = sizeof(arr) / sizeof(arr[0]);

	mergeSort(arr, 0, len - 1);
	printf("\n");
	for (int i = 0; i < len; i++)
	{
		printf("%i ", arr[i]);
	}

	return 0;
}