#include<stdio.h>
void bubblesort(int* l,int n){
	int i,j,a;
	for(i=0;i<n;i++){
		for(j=1;j<n;j++){
			if(l[j-1]>l[j]){
				a=l[j];
				l[j]=l[j-1];
				l[j-1]=a;
			}
		}
	}
}
main(){
	int arr[100];
	int n,i;
	printf("enter elements number :");
	scanf("%d",&n);
	printf("enter elements");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	bubblesort(arr, n);
	printf("Sorted array: \n");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
