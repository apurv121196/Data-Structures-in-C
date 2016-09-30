#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#define max 5
struct node
{ int data;
  struct node *link;
};
struct queue
{ struct node *front;
  struct node *rear;
};
void insert(struct queue *,int );
int del(struct queue *);
void display(struct queue *);
void init(struct queue *);
void main()
{ clrscr();
  struct queue a;
  init(&a);
  insert(&a,1);
  insert(&a,2);
  insert(&a,3);
  display(&a);
  del(&a);
  display(&a);
  getch();
}
void insert(struct queue *q,int num)
{ struct node *temp=(struct node *)malloc(sizeof(struct node));
  if(temp==NULL)
  { cout<<"Queue is full";
    return;
  }
  temp->data=num;
  temp->link=NULL;
  if(q->front==NULL)
  { q->front=q->rear=temp;
    return;
  }
  q->rear->link=temp;
  q->rear=temp;
}
void init(struct queue *q)
{ q->front=q->rear=NULL;
}
int del(struct queue *q)
{ if(q->front==NULL)
  { cout<<"Queue is empty!\n";
    return NULL;
  }
  int num=q->front->data;
  q->front->data=0;
  if(q->front==q->rear)
  { q->front=q->rear=NULL;
    return num;
  }
  q->front=q->front->link;
  return num;
}
void display(struct queue *q)
{ if(q->front==NULL)
  { cout<<"Queue is empty\n";
    return;
  }
  struct node *w;
  for(w=q->front;w!=NULL;w=w->link)
  { cout<<w->data<<"  ";
  } cout<<endl;
}