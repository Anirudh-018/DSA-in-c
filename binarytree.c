#include<stdio.h>
#include<stdlib.h>
struct node
{
    char data;
    struct node *left;
    struct node *right;
};
struct node *insert(struct node *root,int key)
{
    int side;
    if(root==NULL)
    {
        struct node *root=malloc(sizeof(struct node));
        if(root==NULL)
        {
            printf("no memory");
        }
        else{
            root->data=key;
            root->left=NULL;
            root->right=NULL;
            return root;
        }
    }
    else{
        printf("enter 1 for left 0 for right\nenter side:");
        scanf("%d",&side);
        if(side==1){
            root->left=insert(root->left,key);
            return root;
        }
        else{
            root->right=insert(root->right,key);
            return root;
        }
    }
}
void inorder(struct node *root)
{
    if(root== NULL)
    {
        return;
    }
    else
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
}
int main()
{
    struct node *root = NULL;
    int ch,val;
    char i;
    do
    {
        printf("\n1.Insertion\t 2.Inorder\t 3.exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("enter the value:");
                scanf("%d",&val);
                root=insert(root,val);
                break;
            case 2:
                inorder(root);
                break;
            case 3:
                exit(0);
            }
            printf("\nDo you want to continue (Type y or n)\n");  
            scanf(" %c",&i);
        }while (i == 'Y'|| i == 'y');  
   return 0;
}
