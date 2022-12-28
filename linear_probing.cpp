#include<stdio.h>
#include<stdlib.h>
int hash(int key,int size){
	return key%size;
}
void next(int pos,int arr[100],int len,int key){
	int f=0,s=0;
	for(int i=pos+1;i<len;i++){
		if(arr[i]==0){
			arr[i]=key;
			f=1;s=1;
			break;
		}
	}
	if(f==0){
		for(int i=pos+1;i>=0;i--){
		if(arr[i]==0){
			arr[i]=key;
			f=1;s=1;
			break;
		}
	}
	}
	if(s==0){
		printf("overflow\n");
	}
}
main(){
	int arr[100];
	int keys[100];
	int i,n,l;
	printf("enter depth");
	scanf("%d",&n);
	printf("enter keys no");
	scanf("%d",&l);
	for(i=0;i<n;i++){
		arr[i]=0;
	}
	printf("enter keys :");
	for(i=0;i<l;i++){
			scanf("%d",&keys[i]);
			if(arr[hash(keys[i],n)]==0){
				arr[hash(keys[i],n)]=keys[i];
			}
			else{
				next(hash(keys[i],n),arr,n,keys[i]);
				}
			}
	printf("hashed array\n");
	for(i=0;i<n;i++){
		printf("%d\n",arr[i]);
	}
	}
