// DOUBLE LINKED LIST OPERATIONS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
int data;
struct node* left;
struct node* right;
};
struct node* head=NULL;
int len;
void append(void);
void addatbegin(void);
void display(void);
int length(void);
void addatafter(void);
void delete(void);
void main()
{
int choice;
while(1)
{
printf("Double Linked List Operations:\n");
printf("1. Append\n");
printf("2. Add At Begin\n");
printf("3. Add At After\n");
printf("4. Length\n");
printf("5. Display\n");
printf("6. Delete\n");
printf("7. Quit\n");
printf("\nEnter Your Choice\n");
scanf("%d",&choice);
switch(choice)
{
case 1 : append();
 break;

 case 2 : addatbegin();
break;
case 3 : addatafter();
 break;
case 4 : len = length();
 printf("\n\n\nLength : %d\n\n",len);
 break;
case 5 : display();
 break;
case 6 : delete();
 break;
case 7 : exit(1);
break;
default : printf("INVALID INPUT\n\n");
}
}
}
void append()
{
struct node* temp;
temp = (struct node*)malloc(sizeof(struct node));
printf("ENTER NODE DATA : ");
scanf("%d",&temp->data);
temp->left = NULL;
temp->right=NULL;
if(head == NULL) //list is empty
{
head = temp;
}
else
{
struct node* p;
p=head;
while(p->right != NULL)
{
p = p->right ;
}
p->right=temp;
temp->left=p;
}
}
void addatbegin()
{
struct node* temp;
temp=(struct node*)malloc(sizeof(struct node));
printf("ENTER NODE DATA : ");
scanf("%d",&temp->data);
temp->left=NULL;
temp->right=NULL;
if(head==NULL)
{
head=temp;
}
else
{
temp->right=head;
head->left=temp;
head=temp;
}
}
int length()
{
struct node* temp;
int count=0;
temp=head;
while(temp!=NULL)
{
count++;
temp=temp->right;
}
return count;
}
void display()
{
struct node* temp;
temp=head;
if(temp==NULL)
{
printf("THE LIST IS EMPTY");
}
else
{
printf("THE NODES[S] ARE AS FOLLOWS : ");
while(temp!=NULL)
{
printf("%d <=> ",temp->data);
temp=temp->right;
}
}
}
void addatafter()
{
struct node* temp, *p;
int pos, i=1;
printf("ENTER THE POSITION AFTER WHICH THE NEW NODE IS TO BE
INSERTED : ");
scanf("%d",&pos);
if(pos>length())
{
printf("INVALID LOCATION. \nTHERE ARE ONLY %d
NODES.",length());
}
else
{
temp=(struct node*)malloc(sizeof(struct node));
printf("ENTER NODE DATA : ");
scanf("%d",&temp->data);
temp->left=NULL;
temp->right=NULL;
p=head;
while(i<pos)
{
p=p->right;
i++;
}
temp->right=p->right;
p->right->left=temp;
temp->left=p;
p->right=temp;
}
}
void delete()
{
struct node* temp;
int pos;
printf("ENTER THE POSTION TO BE DELETED : ");
scanf("%d",&pos);
if(pos>length())
{
printf("THERE ARE ONLY %d NODES",length());
}
else if(pos==1)
{
temp=head;
head=head->right;
head->left=NULL;
temp->right=NULL;
free(temp);
}
else
{
struct node* p;
int i=1;
p=head;
while(i<pos)
{
p=p->right;
i++;
}
p->left->right=p->right;
p->right->left=p->left;
p->right=NULL;
p->left=NULL;
free(p);
}
}