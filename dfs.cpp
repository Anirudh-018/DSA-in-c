#include<stdio.h>
int size;
int arr[100][100];
int visited[100];
void DFS(int);
void display(int arr[100][100]){
	int i,j;
	printf("\nmatrix is \n");
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	printf("DFS order of nodes\n :");
	DFS(0);
}
void directedw(int arr[100][100],int n){
	int i,a,b,weight;
	for(i=0;i<n;i++){
		printf("enter starting node :");
		scanf("%d",&a);
		printf("enter ending node :");
		scanf("%d",&b);
		printf("enter weight :");
		scanf("%d",&weight);
		arr[a][b]=weight;
	}
	display(arr);
}
void undirected(int arr[100][100],int n){
	int i,a,b;
	for(i=0;i<n;i++){
		printf("enter starting node :");
		scanf("%d",&a);
		printf("enter ending node :");
		scanf("%d",&b);
		arr[a][b]=1;
		arr[b][a]=1;
	}
	display(arr);
}
void undirectedw(int arr[100][100],int n){
	int i,a,b,weight;
	for(i=0;i<n;i++){
		printf("enter starting node :");
		scanf("%d",&a);
		printf("enter ending node :");
		scanf("%d",&b);
		printf("enter weight :");
		scanf("%d",&weight);
		arr[a][b]=weight;
		arr[b][a]=weight;
	}
	display(arr);
}
void directed(int arr[100][100],int n){
	int i,a,b;
	for(i=0;i<n;i++){
		printf("enter starting node :");
		scanf("%d",&a);
		printf("enter ending node :");
		scanf("%d",&b);
		arr[a][b]=1;
	}
	display(arr);
}
main(){
	int i,n,j;
	printf("enter value no of vertices :");
	scanf("%d",&size);
	for(i=0;i<size;i++){
		visited[i]=0;
	}
	printf("1.undirected\t2.directed\t3.undirected weighted\t4.directed weighted\t :");
	scanf("%d",&i);
	switch(i){
		case 1:
			printf("enter number of edges :");
			scanf("%d",&j);
			undirected(arr,j);
			break;
		case 2:
			printf("enter number of edges :");
			scanf("%d",&j);
			directed(arr,j);
			break;
		case 3:
			printf("enter number of edges :");
			scanf("%d",&j);
			undirectedw(arr,j);
			break;
		case 4:
			printf("enter number of edges :");
			scanf("%d",&j);
			directedw(arr,j);
			break;
	}
}
void DFS(int i)
{
    int j;
printf("\n%d",i);
    visited[i]=1;
for(j=0;j<size;j++)
       if(!visited[j]&&arr[i][j]>=1)
            DFS(j);
}
