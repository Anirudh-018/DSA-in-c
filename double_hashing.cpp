#include<stdio.h>
int count=0;
int count1=0;
int prime[100];
int full(int arr[100],int size){
	int i,c=0;
	for(i=0;i<size;i++){
		if(arr[i]!=0){
			c++;
		}
	}
	return c;
}
int hash(int key,int size){
	return key%size;
}
int prim(int a){
	int i,f=1;
	for(i=2;i<=(a/2);i++){
		if(a%i==0){
			f=0;
			break;
		}
	}
	return f;
}
int primen(int l,int prime[100]){
	int i,f=0,ex=1;
	for(i=2;i<l;i++){
		if(prim(i)){
			prime[count]=i;
			count++;
			count1++;
		}
	}
}
void quad(int key,int arr[100],int index,int size){
	int j=0;
	while(arr[index]!=0){
		j=prime[count1-1]-(key%prime[count1-1]);
		if((j+index)>size-1){
			index=j+index-size-1;
		}
		else{
			index+=j;
		}
	}
	arr[index]=key;
}
main(){
	int arr[100];
	int keys[100];
	int i,n,l;
	printf("enter depth");
	scanf("%d",&n);
	printf("enter keys no");
	scanf("%d",&l);
	primen(l,prime);
	int j=0;
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

