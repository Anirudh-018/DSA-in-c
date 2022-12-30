#include <stdio.h>
#include <stdlib.h>
// Linked List Node
int count=0,limit=10;
struct node {
int info;
struct node *prev, *next;
};
struct node* front = NULL;
struct node* rear=NULL;
void traverse()
{
if (count == 0) {
printf("\nqueue is empty\n");
return;
}
// Else print the Data
struct node* temp;
temp = front;
while (temp != NULL) {
printf("Data = %d\n", temp->info);
temp = temp->next;
}
}
void enqueue()
{if (limit==count)
printf("overflow");
else{
int data;
struct node *temp, *ptr;
temp = (struct node*)malloc(sizeof(struct node));
temp->prev = NULL;
temp->next = NULL;
printf("\nEnter number to be inserted: ");
scanf("%d", &data);
temp->info = data;
temp->next = NULL;
ptr = rear;
// If start is NULL
if (front == NULL) {
front = temp;
rear=temp;
count++;
}
// Changes Links
else {
while (ptr->next != NULL)
ptr = ptr->next;
temp->prev = ptr;
ptr->next = temp;
rear=temp;
count++;
}
}
}
void dequeue()
{
if (front == NULL)
printf("\nunderflow\n");
else {
front=front->next;
}
}
main()
{
int c;
while (1) { printf("\n\t1 display\t");
printf("\t2 For enqueue\t");
printf("\t3 For dequeue\t");
printf("\nEnter Choice :\n");
scanf("%d", &c);
switch (c) {
case 1: traverse(); break;
case 2: enqueue(); break;
case 3: dequeue(); break;
case 0: exit(1); break;
}
}
}

