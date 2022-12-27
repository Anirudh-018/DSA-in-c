#include<stdio.h>
void binary_ser(int *l,int key,int len){
	int le=0;
	int r=len-1;
	int mid=-1;
	while(le<r){
		mid=(le+r)/2;
		if(l[mid]==key){
			printf("found at %d",mid);
			break;
		}
		else if(l[mid]>key){
			r=mid-1;
		}
		else{
			le=mid+1;
		}
	}
	if (le>=r)
		printf("not found");
}
int main()
{
	int l[100];
	int n,i;
	printf("enter elements number :");
	scanf("%d",&n);
	printf("enter elements");
	for(i=0;i<n;i++){
		scanf("%d",&l[i]);
	}
	int key;
	printf("enter key value:");
	scanf("%d",&key);
	binary_ser(l,key,n);
	return 0;
}
