#include <stdio.h>
#include <stdlib.h>
// Linked List Node
int count=0,limit=10;
struct node {
int info;
struct node *prev, *next;
};
struct node* start = NULL;
struct node* top=NULL;
void traverse()
{
if (count == 0) {
printf("\nstack is empty\n");
return;
}
// Else print the Data
struct node* temp;
temp = top;
while (temp != NULL) {
printf("Data = %d\n", temp->info);
temp = temp->prev;
}
}
void push()
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
ptr = top;
// If start is NULL
if (start == NULL) {
start = temp;
top=temp;
count++;
}
// Changes Links
else {
while (ptr->next != NULL)
ptr = ptr->next;
temp->prev = ptr;
ptr->next = temp;
top=temp;
count++;
}
}
}
void pop()
{
struct node* temp;
if (start == NULL){
printf("\nunderflow\n");}
else{

temp = top;
if (start->next == NULL){
top = NULL;
start=NULL;
count--;}
else {
temp->prev->next = NULL;
top=temp->prev;
free(temp);
count--;
}
}
}
main()
{
int c;
while (1) { printf("\n\t1 To see list\t");
printf("\t2 For push\t");
printf("\t3 For pop\t");
printf("\nEnter Choice :\n");
scanf("%d", &c);
switch (c) {
case 1: traverse(); break;
case 2: push(); break;
case 3: pop(); break;
case 0: exit(1); break;
}
}
}
