#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<alloc.h>
struct node
{ int data;
  struct node *link;
};
struct queue
{ struct node *front;
  struct node *rear;
};
void initq(struct queue *);
void insert(struct queue *);
void del(struct queue *);
void display(struct queue *);
void main()
{ clrscr();
  struct node *p;  struct queue *w;
  initq(w);
  insert(w);

  display(w);
  del(w);
  display(w);
  getch();
}
void initq(struct queue *q)
{ q->rear=NULL;
  q->front=NULL;
}
void insert(struct queue *q)
{ int data;char ch;
  do
  {
    struct node *p=(struct node *)malloc(sizeof(struct node));
    cout<<"Enter element to be inserted:  ";
    cin>>data;
    p->data=data;

    if(q->front==NULL)
    { p->link=NULL;
      q->rear=p;
      q->front=p;
    }
    else
    { p->link=q->rear;
      q->rear=p;
    }
    cout<<"do u anna insert more elements";
    cin>>ch;
    }while(ch=='y');
}
void display(struct queue *q)
{ if(q->rear==NULL)
  {cout<<"Empty queue\n";
   return;
   }
  cout<<"Displaying queue:  ";
  struct node *e;
  e=q->rear;
  while(e!=NULL)
  { cout<<e->data<<"  ";
    e=e->link;
  }
  cout<<endl;
}
void del(struct queue *q)
{ struct node *t=q->rear;
  if(q->front==NULL)
  { cout<<"Queue is empty\n";
  return;
  }
  if(q->rear->link==NULL)
  { q->rear=NULL;
    q->front=NULL;
    cout<<"Displaying elements:  ";
  return;
  }
  else
  { while(t->link!=q->front)
    { t=t->link;
    }
  cout<<"Element deleted:   "<<q->front->data<<endl;
  t->link=NULL;
  return;
  }
}