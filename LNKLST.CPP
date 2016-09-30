#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<alloc.h>
struct node
{ int data;
  struct node *link;
};
void cnode(struct node * ,int );
void display(struct node *);
void main()
{
 clrscr();
 struct node *p; p=NULL;
 cnode(p,3);
 display(p);
 getch();
}
void cnode(struct node *q,int num)
{   struct node *temp;
   //temp=(struct node *)malloc(sizeof(struct node));
   temp->data=num;
   temp->link=NULL;
   q=temp;
}
void display(struct node *q)
{
   cout<<q->data;

}