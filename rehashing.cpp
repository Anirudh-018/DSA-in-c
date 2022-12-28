#include<stdio.h>
#include<stdlib.h>
int prime[25];
int count=0,count1=0;
int size;
int keys[100];
int *arr;
int hash(int key){
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
int primen(int l){
	int i,f=0,ex=1;
	for(i=l+1;i<100;i++){
		if(prim(i)){
			prime[count]=i;
			count++;
			count1++;
		}
	}
}
int full(){
	int i,c=0;
	
	for(i=0;i<size;i++){
		if(arr[i]!=0){
			c++;
		}
	}
	return c;
}
void rehash(int k){
	int i;
	for(i=0;i<size;i++){
		if(prime[i]>size*2){
			size=prime[i];
			break;
		}
	}
	arr=(int*)malloc(size*sizeof(int));
	for(i=0;i<size;i++){
		arr[i]=0;
	}
	for(i=0;i<size;i++){
		keys[i];
	}
	for(i=0;i<k+1;i++){
		arr[hash(keys[i])]=keys[i];	
	}
}
main(){
	int i,l,k=0;
	printf("enter depth");
	scanf("%d",&size);
	printf("enter keys no");
	scanf("%d",&l);
	primen(l);
	arr=(int*)malloc(size*sizeof(int));
	for(i=0;i<size;i++){
		arr[i]=0;
	}
	for(i=0;i<l;i++){
		if(full()<=size){
			scanf("%d",&keys[i]);
			k++;
			if(arr[hash(keys[i])]==0){
				arr[hash(keys[i])]=keys[i];
			}
			else{
				printf("coll\n");
				rehash(k);
			}
		}
		else
		printf("overflow");
	}
	printf("hashed array\n");
	for(i=0;i<size;i++){
		printf("%d\n",arr[i]);
	}
}
