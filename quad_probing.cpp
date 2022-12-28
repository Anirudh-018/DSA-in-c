#include<stdio.h>
int hash(int key,int size){
	return key%size;
}
void quad(int key,int arr[100],int index,int size){
	int j=1;
	while(arr[hash(index+(j*j),size)]!=0){
		j++;
	}
	arr[hash(index+(j*j),size)]=key;
}
int full(int arr[100],int size){
	int i,c=0;
	
	for(i=0;i<size;i++){
		if(arr[i]!=0){
			c++;
		}
	}
	return c;
}
main(){
	int arr[100];
	int keys[100];
	int i,n,l;
	printf("enter depth");
	scanf("%d",&n);
	printf("enter keys no");
	scanf("%d",&l);
	printf("enter keys: ");
	for(i=0;i<n;i++){
		arr[i]=0;
	}
	for(i=0;i<l;i++){
		if(full(arr,n)<=n){
			scanf("%d",&keys[i]);
			if(arr[hash(keys[i],n)]==0){
				arr[hash(keys[i],n)]=keys[i];
			}
			else{
				printf("coll\n");
				quad(keys[i],arr,hash(keys[i],n),n);
			}
		}
		else
		printf("overflow");
	}
	printf("hashed array\n");
	for(i=0;i<n;i++){
		printf("%d\n",arr[i]);
	}
}
