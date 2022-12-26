#include<time.h>
#include <stdio.h>
void selectionSort(int arr[], int n)
{
	int i, j, min,temp;
	for (i = 0; i<n; i++)
	{
		min = i;
		for (j = i+1; j < n; j++){
		if (arr[j] < arr[min])
			min = j;
		}
			temp=arr[min];
			arr[min]=arr[i];
			arr[i]=temp;
	}
}
void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
int main()
{
	int arr[20];
	int n,i;
	printf("enter elements number :");
	scanf("%d",&n);
	printf("enter elements");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	selectionSort(arr, n);
	printf("Sorted array: \n");
	printArray(arr, n);
	return 0;
	
}

