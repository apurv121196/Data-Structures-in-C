#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<malloc.h>
struct node
{ int data;
  struct node *link;
};
struct queue
{ struct node *front;
  struct node *rear;
};
void addatbeg(struct queue *,int );
void addatend(struct queue *,int );
void init(struct queue *);
void display(struct queue *);
void main()
{ clrscr();
  struct queue *p;
  init(p);
  addatbeg(p,2);
  addatend(p,3);
  addatbeg(p,1);
  display(p);
  getch();
}
void init(struct queue *q)
{ q->front=NULL;
  q->rear=NULL;
}
void addatend(struct queue *q,int num)
{ struct node *temp=(struct node *)malloc(sizeof(struct node));
  if(temp==NULL)
  { cout<<"Queue is full!\n";
    return;
  }
  temp->link==NULL;
  temp->data=num;
  if(q->front==NULL)
  { q->front=temp;
    q->rear=temp;
    return;
  }
  q->rear->link=temp;
  q->rear=temp;
}
void addatbeg (struct queue *q,int num)
{ struct node *temp=(struct node *)malloc(sizeof(struct node));
  if(temp==NULL)
  { cout<<"Queue is full!\n";
    return;
  }
  temp->data=num;
  if(q->front==NULL)
  { q->rear=temp;
  }
  temp->link=q->front;
  q->front=temp;
}
void display(struct queue *q)
{ if(q->front==NULL)
  { cout<<"Queue is empty!\n";
    return;
  }
  struct node *temp=q->front;
  while(temp!=NULL)
  { cout<<temp->data<<"  ";
    temp=temp->link;
  }
}
