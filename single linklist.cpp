#include <stdio.h>
#include <stdlib.h>
//Node
struct node {
int info;
struct node* link;
};
struct node* start = NULL;
//create list 
void createList()
{
if (start == NULL) {
int data;
struct node* newnode;
struct node* temp;
newnode = (node*)(struct node*)malloc(sizeof(struct node));
start = newnode;
temp = start;
printf("\nEnter number to be inserted : ");
scanf("%d", &data);
start->info = data;
printf("\nThe list is created\n");
start->link=0;
}
else{

printf("\nThe list is already created\n");}
}//traverse 
void traverse()
{
	struct node* temp; 
	if (start == NULL)
		printf("\nList is empty\n");
	else {
		temp = start;
		while (temp != NULL) {
			printf("Data = %d\n", temp->info);
			temp = temp->link;
		}
	}
}
//insert at front 
void insertAtFront()
{
	int data;
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter number to be inserted : ");
	scanf("%d", &data);
	temp->info = data;
	temp->link = start;
	start = temp;
}
//insert at the end
void insertAtEnd()
{
	int data;
	struct node *temp, *ptr;
	temp = (node*)(struct node*)malloc(sizeof(struct node));
	printf("\nEnter number to be inserted : ");
	scanf("%d", &data);
	temp->link = 0; 
	temp->info = data;
	ptr = start;
	while (ptr->link != NULL) {
		ptr = ptr->link;
	}
	ptr->link = temp;
}
//insert at pos
void insertAtPosition()
{
	struct node *temp, *newnode;
	int pos, data, i = 1;
	newnode = (node*)(struct node*)malloc(sizeof(struct node));
	printf("\nEnter position and data :"); 
	scanf("%d %d", &pos, &data);
	temp = start; 
	newnode->info = data;
	newnode->link = 0;
	while (i < pos - 1) {
		temp = temp->link;
		i++;
	}
	newnode->link = temp->link;
	temp->link = newnode;
}
//delete at front
void deleteFirst()
{
	struct node* temp;
	if (start == NULL)
	printf("\nList is empty\n");
	else {
		temp = start;
		start = start->link;
		free(temp);
	}
}
//delete at end
void deleteEnd()
{
	struct node *temp, *prevnode;
	if (start == NULL)
		printf("\nList is Empty\n");
	else {
		temp = start;
		while (temp->link != 0) {
			prevnode = temp;
			temp = temp->link;
		}
		free(temp);
		prevnode->link = 0;
	}
}
//delete at pos
void deletePosition()
{
	struct node *temp;
	int i = 1, pos;
	if (start == NULL) 
		printf("\nList is empty\n");
	else { 
		printf("\nEnter index : ");
		scanf("%d", &pos); 
		temp = start;
		while (i < pos - 1)
		{
		temp = temp->link;
		i++;
		} 
		temp->link = temp->link->link; 
	}
}
// Driver Code
main()
{ 
	int choice;
	createList();
	while (1) { 
		printf("\n\t1 To see list\t");
		printf("\t2 For insertion at starting\t");
		printf("\t3 For insertion at end\t");
		printf("\t4 For insertion at any position\t");
		printf("\t5 For deletion of first element\t");
		printf("\t6 For deletion of last element\t");
		printf("\t7 For deletion of element at any position\t");
		printf("\nEnter Choice :\t");
		scanf("%d", &choice);
		switch (choice)
		{ 
			case 1: traverse(); break;
			case 2: insertAtFront(); break;
			case 3: insertAtEnd(); break;
			case 4: insertAtPosition(); break;
			case 5: deleteFirst(); break;
			case 6: deleteEnd(); break;
			case 7: deletePosition(); break;
			default: printf("Incorrect Choice\n");
		}
	}
}
