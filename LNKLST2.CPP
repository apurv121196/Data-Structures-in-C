#include<stdio.h>
#include<conio.h>
#include<alloc.h>
struct node
{ int data;
  struct node *link;
};
void append(struct node ** ,int );
void display(struct node *);
void bubsort(struct node *);
void selsort(struct node *);
void main()
{
 clrscr(); struct node *p;
 p=NULL;
 append(&p,14);
 append(&p,10);
 append(&p,13);
 display(p);
 bubsort(p);
 display(p);
 getch();
}
void append(struct node **q,int num)
{  struct node *temp, *r;
  if(*q==NULL)
  {  temp=(struct node *)malloc(sizeof(struct node));
     temp->data=num;
     temp->link=NULL;
     *q=temp;
  }
  else
  { temp=*q;
    while(temp->link!=NULL)
      temp=temp->link;
      r=(struct node *)malloc(sizeof(struct node));
      r->data=num;
      r->link=NULL;
      temp->link=r;
  }
}
void display(struct node *q)
{  while(q!=NULL)
   { printf("%d\n",q->data);
     q=q->link;
   }
}
void selsort(struct node *q)
{ struct node *n=q;   struct node *w;  int temp;
  for(n=q;n->link!=NULL;n=n->link)
  {
    for(w=n->link;w!=NULL;w=w->link)
    { if(n->data>w->data)
      { temp=n->data;
	n->data=w->data;
	w->data=temp;
      }
    }
  }
}
void bubsort(struct node *q)
{ struct node *n=q; struct node *w; int temp;
  for(n=q;n!=NULL;n=n->link)
  { for(w=q;w->link!=NULL;w=w->link)
    { if(w->data>w->link->data)
      { temp=w->data;
	w->data=w->link->data;
	w->link->data=temp;
      }
    }
  }
}