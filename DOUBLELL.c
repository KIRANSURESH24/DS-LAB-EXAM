#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Node
{
struct Node *left;
int data;
struct Node *right;
};
typedef struct Node Node;
Node *getnode();
main()
{
Node *first;
int ch,item,pos,n,d;
InDL(&first);
clrscr();
printf("\nCreating a Doubly Linked List");
printf("\nNumber of nodes to create");
scanf("%d",&n);
DLC(&first,n);
while(1)
{
printf("Enter choice:");
printf("1.Insert in first node");
printf("2.insert in any position");
printf("3.insert at last position");
printf("4.delete in first node");
printf("5.delete at any position");
printf("6.enter the elements to display");
printf("7.enter the elements to search");
printf("8.exit");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("Enter item to be inserted:");
scanf("%d",&item);
IDLF(&first,item);
break;
case 2:
printf("Enter item to be inserted:");
scanf("%d",&item);
printf("enter the position");
scanf("%d",&pos);
IDLA(&first,item,pos);
break;
case 3:
printf("Enter the item to be inserted at last");
scanf("%d",&item);
IDLL(&first,n);
break;
case 4:
DDLF(&first);
break;
case 5:
printf("\nEnter the node number to delete:");
scanf("%d",&n);
DDLA(&first,n);
break;
case 6:
printf("enter the node number to be search");
scanf("%d",&n);
SRC(&first,n);
case 7:
TDL(first);
break;
case 8:
exit(0);
break;
}
}
}
InDL(Node **first)
{
 (*first)=NULL;
}
DLC(Node **f,int n)
 {
    Node *temp,*current;
    int i,item;
    for(i=1;i<=n;i++)
    {
       printf("Enter the data field %d:",i);
       scanf("%d",&item);
       temp=getnode();
       temp->data=item;
       temp->right=NULL;
       if(*f==NULL)
       {
	(*f)=temp;
	temp->left=NULL;
       }
       else
       {
	current->right=temp;
	temp->left=current;
       }
	current=temp;
    }
}
IDLF(Node **f,int item)
 {
   Node *temp;
   int i;
   temp=getnode();
   temp->data=item;
   temp->left=NULL;
   if(*f==NULL)
   {
     temp->right=NULL;
   }
    else
    {
     temp->right=(*f);
     (*f)->left=temp;
    }
   (*f)=temp;
}
IDLA(Node **f,int item,int pos)
{
  Node *temp,*current;
  int i;
  temp=getnode();
  temp->data=item;
  if(pos==1)
  {
  if(*f!=NULL)
  (*f)->left=temp;
  temp->right=(*f);
  temp->left=NULL;
  (*f)=temp;
  }
  else
  {
    i=2;
    current=(*f);
    while((i<pos)&&(current->right!=NULL))
    {
     i++;
     current=current->right;
    }
     temp->left=current;
     temp->right=current->right;
     if(current->right!=NULL)
     {
      temp->right->left=temp;
      current->right=temp;
     }
  }
}
IDLL(Node **f,int item)
{
 Node *temp,*current;
 temp=getnode();
 temp->data=item;
 temp->right=NULL;
 if(*f==NULL)
 {
   temp->left=NULL;
   (*f)=temp;
 }
  else
  {
   current=(*f);
   while(current->right!=NULL)
   {
    current=current->right;
   }
    temp->left=current;
    current->right=temp;
  }
}
DDLF(Node **first)
{
  Node *current;
  int item;
  if(*first==NULL)
   {
    printf("list empty");
    return;
   }
    current=(*first);
    (*first)=(*first)->right;
    if(*first!=NULL)
    {
     (*first)->left=NULL;
     item=current->data;
     freenode(current);
     printf("Deleted item is %d",item);
    }
}
DDLA(Node **first,int pos)
{
  Node *current,*prev;
  int i=1,item;
  if(*first==NULL)
  {
    printf("list empty");
    return;
  }
   current=(*first);
   while(current!=NULL)
   {
    if(i==pos)
    {
     item=current->data;
     if(current->left==NULL)
     {
      current->right->left=NULL;
      (*first)=current->right;
      freenode(current);
     }
     else if(current->right==NULL)
     {
      current->left->right=current->right;
      freenode(current);
     }
     else
     {
       current->left->right=current->right;
       current->right->left=current->left;
       freenode(current);
     }
     printf("deleted item is %d",item);
     return;
   }
     i++;
     current=current->right;
printf("No such node found");
}
TDL(Node **first)
{
 if(first==NULL)
 {
   printf("list is empty");
   return;
 }
printf("DLL is....\n");
printf("Start<->");
do
{
  printf("%d<->",first->data);
  first=first->right;
}
  while(first!=NULL);
  printf("End\n");
}
Node *getnode();
{
   Node *t;
   t=(Node *)malloc(sizeof(Node));
   return t;
}
   freenode(Node *t);
{
   free(t);
}




