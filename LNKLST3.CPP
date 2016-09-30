#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<alloc.h>
struct node
{ int data;
  struct node *link;
};
void append(struct node * ,int );
void display(struct node *);
void cnode(struct node **,int );
void count(struct node *);
void addatbeg(struct node **,int );
void addafter(struct node *,int ,int );
void delnode(struct node **,int );
void ascnode(struct node **,int );
void reverse(struct node **);
void reverse2(struct node **);
void main()
{
 clrscr();
 cout<<"\t\t\t  ***** LINKED-LIST *****\n";
 struct node *p;p=NULL;
 cnode(&p,1);
 append(p,2);
 append(p,4);
 append(p,5);
 display(p);
 count(p);
 addatbeg(&p,0);
 display(p);
 addafter(p,2,3);
 display(p);
 delnode(&p,5);
 display(p);
 reverse2(&p);
 display(p);
 getch();
}
void cnode(struct node **q,int num)
{
   struct node *temp=(struct node *)malloc(sizeof(struct node));
   temp->data=num;
   temp->link=NULL;
   *q=temp;
}
void append(struct node *q,int num)
{  struct node *temp,*r;
    //adding node at end
    temp=q;
    while(temp->link!=NULL)
    {temp=temp->link;}
    r=(struct node *)malloc(sizeof(struct node));
    r->data=num;
    r->link=NULL;
    temp->link=r;
}
void display(struct node *q)
{
  cout<<"\nNODES  :";
   while(q!=NULL)
   { cout<<">  "<<q->data<<"  -";
    q=q->link;
   }
}
void count(struct node *q)
{
  int c=0;
   while(q!=NULL)
   { c++;
     q=q->link;
   }
  cout<<"\nThere are "<<c<<" nodes present";
}
void addatbeg(struct node **q,int num)
{
  cout<<"\n\nAdding a node at beginning with data "<<num<<":";
  struct node *temp=(struct node *)malloc(sizeof(struct node));
  temp->data=num;
  temp->link=*q;
  *q=temp;
}
void addafter(struct node *q,int a,int b)
{
  struct node *temp; cout<<"\n\nAdding a node with data "<<b<<" after "<<a<<":";
  while(q->data!=a)
   { q=q->link;}
  temp=(struct node *)malloc(sizeof(struct node));
  temp->data=b;
  temp->link=q->link;
  q->link=temp;
}
void delnode(struct node **q,int num)
{ struct node *temp; struct node *old; cout<<"\n\nDeleting a node with data "<<num<<":";
  temp=*q;
  while(*q!=NULL)
  { if(temp->data==num)
    { if(temp==*q)
      { *q=temp->link;
	free(temp);
	return;
      }
      else
      { old->link=temp->link;
	free(temp);
	return;
      }
    }
    else
    { old=temp;
      temp=temp->link;
    }
  }
}
void ascnode(struct node **q,int num)
{ ;
}
void reverse(struct node **q)
{ struct node *pre=*q;
  struct node *rev=NULL;
  struct node *brk=*q;
  while(pre!=NULL)
  { pre=pre->link;
    brk->link=rev;
    rev=brk;
    brk=pre;
  }
  *q=rev;
}
void reverse2(struct node **q)
{ int c=0;
  struct node *e=*q;
  while(e!=NULL)
  { e=e->link;
    c++;
  };
  const a=c;
  struct node *w=*q;
  int arr[5];
  for(int i=0;i<c;i++)
  { arr[i]=w->data;
    w=w->link;
  }
  w=*q;
  for(i=c-1;i>=0;i--)
  { w->data=arr[i];
    w=w->link;
  }
}
