#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<alloc.h>
struct node
{ int data;
  struct node *link;
};
void add(struct node **,int );
void display(struct node *);
void merge(struct node *,struct node *,struct node **);
void main()
{ clrscr();
  struct node *p=NULL; struct node *q=NULL; struct node *w=NULL;
  add(&p,2);
  add(&p,6);
  add(&p,3);
  add(&q,4);
  add(&q,5);
  add(&q,1);
  display(p);
  display(q);
  merge(p,q,&w);
  display(w);
  getch();
}
void add(struct node **q,int num)
{ struct node *temp=(struct node *)malloc(sizeof(struct node));
  temp->data=num;
  if(*q==NULL)
  { *q=temp;
    temp->link=NULL;
    return;
  }

  if((*q)->data>num)
  { temp->link=*q;
    *q=temp;
    return;
  }
  struct node *ahead=*q;struct node *old;
  while(old!=NULL)
  { if(old->data<num && (ahead->data>num || ahead==NULL))
    { temp->link=ahead;
      old->link=temp;
      return;
    }
    else
    { old=ahead;
      ahead=ahead->link;
    }
  }
}
void display(struct node *q)
{ struct node *w=q;
  while(w!=NULL)
  { cout<<w->data<<"  ";
    w=w->link;
  }          cout<<endl;
}
void merge(struct node *a,struct node *b,struct node **c)
{ struct node *r=NULL;
  while(a!=NULL && b!=NULL)
  { if(*c==NULL)
    { *c=(struct node *)malloc(sizeof(struct node));
      r=*c;
    }
    else
    { r->link=(struct node *)malloc(sizeof(struct node));
      r=r->link;
    }
    if(a->data<b->data)
    { r->data=a->data;
      a=a->link;
    }
    else
    { if(a->data>b->data)
       { r->data=b->data;
	 b=b->link;
       }
      else
       { if(a->data==b->data)
	 { r->data=a->data;
	  a=a->link;
	  b=b->link;
	 }
       }
    }
  }

  while(a!=NULL)
  { r->link=(struct node *)malloc(sizeof(struct node));
    r=r->link;
    r->data=a->data;
    a=a->link;
  }
  while(b!=NULL)
  { r->link=(struct node *)malloc(sizeof(struct node));
    r=r->link;
    r->data=b->data;
    b=b->link;
  }
  r->link=NULL;
}
