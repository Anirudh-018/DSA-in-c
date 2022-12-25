#include <stdio.h>

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ",arr[i]);
	printf("\n");
}


int partition (int arr[], int low, int h)
{
	int pivot = arr[h]; 
	int i = (low - 1); 
	for (int j = low; j <= h - 1; j++)
	{
		
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
		printArray(arr,6);
	}
	swap(&arr[i + 1], &arr[h]);
	return (i + 1);
}

void quickSort(int arr[], int low, int h)
{
	if (low < h)
	{
		int p = partition(arr, low, h);
		printf("p:%d\n",p);
		quickSort(arr, low, p - 1);
		quickSort(arr, p + 1, h);
		printf("2\n");
	}
}

int main()
{
	int arr[100];
	int n,i;
	printf("enter elements number :");
	scanf("%d",&n);
	printf("enter elements");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}

	quickSort(arr, 0, n - 1);
	printf("sorted array\n");
	printArray(arr, n);
	return 0;
}


