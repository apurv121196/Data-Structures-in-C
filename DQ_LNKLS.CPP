#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<alloc.h>
struct node
{ int data;
  struct node *link;
};
struct queue
{ struct node *front;
  struct node *rear;
};
void init(struct queue *);
void addatbeg(struct queue *,int );
void addatend(struct queue *,int );
void delbeg(struct queue *);
void delend(struct queue *);
void display(struct queue *);
void main()
{ clrscr();
  struct queue *p;
  init(p);
  addatbeg(p,2);
  addatbeg(p,1);
  addatend(p,3);
  display(p);
  delend(p);
  display(p);
  delbeg(p);
  display(p);
  getch();
}
void init(struct queue *q)
{ q->rear=q->front=NULL;
}
void addatbeg(struct queue *q,int num)
{ struct node *temp=(struct node *)malloc(sizeof(struct node));
  temp->data=num;
  if(q->front==NULL)
  { q->front=q->rear=temp;
    temp->link=NULL;
    return;
  }
  temp->link=q->front;
  q->front=temp;
}
void addatend(struct queue *q,int num)
{ struct node *temp=(struct node *)malloc(sizeof(struct node));
  temp->data=num;
  temp->link=NULL;
  if(q->front==NULL)
  { q->front=q->rear=temp;
    return;
  }
  q->rear->link=temp;
  q->rear=temp;
}
void display(struct queue *q)
{ struct node *temp=q->front;
  while(temp!=NULL)
  { cout<<temp->data<<"  ";
    temp=temp->link;
  }
  cout<<endl;
}
void delbeg(struct queue *q)
{ if(q->front==NULL)
  { cout<<"Dqueue is empty\n";
    return;
  }
  if(q->front->link==NULL)
  { q->rear=q->front=NULL;
    return;
  }
  struct node *temp=q->front;
  q->front=q->front->link;
  free(temp);
}
void delend(struct queue *q)
{ if(q->front==NULL)
  { cout<<"Dqueue is empty\n";
    return;
  }
  if(q->front->link==NULL)
  { q->rear=q->front=NULL;
    return;
  }
  struct node *temp=q->front;
  while(temp->link!=q->rear)
  { temp=temp->link;
  }
  q->rear=temp;
  temp->link=NULL;
}