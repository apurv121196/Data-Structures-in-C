#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<alloc.h>
struct node
{ int data;
  struct node *link;
};
void cnode(struct node **,int );
void push(struct node *,int );
void pop(struct node *);
void display(struct node *);
void main()
{ clrscr();
  struct node *p;
  p=NULL;
  cnode(&p,1);
  push(p,2);
  push(p,3);
  push(p,4);
  push(p,5);
  display(p);
  pop(p);
  display(p);
  getch();
}
void cnode(struct node **q,int num)
{ struct node *r=(struct node *)malloc(sizeof(struct node));
  r->data=num;
  r->link=NULL;
  cout<<"Adding "<<num<<" to the stack\n";
  *q=r;
}
void push(struct node *q,int num)
{ struct node *temp;
  temp=(struct node *)malloc(sizeof(struct node));
  temp->data=num;
  temp->link=NULL;
  cout<<"Adding "<<num<<" to the stack\n";
  while(q!=NULL)
  { if(q->link==NULL)
    { q->link=temp;
      return;
    }
    else
    { q=q->link;
    }
  }
}
void pop(struct node *q)
{ struct node *old;
  while(q!=NULL)
  { if(q->link==NULL)
    { old->link=NULL;
      cout<<"Element "<<q->data<<" deleted\n";
      return;
    }
    else
    { old=q;
      q=q->link;
    }
  }
}
void display(struct node *q)
{ if(q==NULL)
  { cout<<"No elements to display\n";
    return;
  }
  cout<<"Stack elements:\t";
  while(q!=NULL)
  { cout<<"\t"<<q->data;
    q=q->link;
  }
  cout<<"\n";
}