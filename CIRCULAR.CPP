#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#define max 5
struct cqueue
{ int arr[5];
  int front;
  int rear;
};
void init(struct cqueue *);
void insert(struct cqueue *,int );
void display(struct cqueue *);
void del(struct cqueue *);

void main()
{ clrscr();
  struct cqueue *w;
  init(w);
  insert(w,1);
  insert(w,2);
  insert(w,3);
  display(w);
  insert(w,4);
  insert(w,5);
  display(w);
  del(w);
  del(w);
  display(w);
  insert(w,6);
  display(w);
  insert(w,7);
  display(w);
  getch();
}
void init(struct cqueue *q)
{ q->front=q->rear=-1;
}
void insert(struct cqueue *q,int data)
{ if(q->front==-1)
  { cout<<"Inserting new element:   "<<data<<endl;
    (q->front)++;
    (q->rear)++;
    q->arr[q->rear]=data;
    return;
  }
  if((q->front==0 && q->rear==max-1) || q->rear+1==q->front)
  { cout<<"Circular queue is full\n";
    return;
  }
  else if(q->front!=0 && q->rear==max-1)
  { cout<<"Inserting new element:   "<<data<<endl;
    q->rear=0;
    q->arr[q->rear]=data;
    return;
  }
  cout<<"Inserting new element:   "<<data<<endl;
  (q->rear)++;
  q->arr[q->rear]=data;
}
void del(struct cqueue *q)
{ if(q->front==-1)
  { cout<<"Circular queue is empty\n";
    return;
  }
  cout<<"Element deleted:   "<<q->arr[q->front]<<endl;
  q->arr[q->front]=0;
  if(q->front==q->rear)
  { q->front=q->rear=-1;
    return;
  }
  else if(q->front==max-1)
  { q->front=0;
    return;
  }
  else
  { q->front++;
    return;
  }
}
void display(struct cqueue *q)
{ if(q->front==-1)
  { cout<<"Queue is empty!\n";
    return;
  }
  if(q->rear>=q->front)
  { for(int i=q->front;i<=q->rear;i++)
    cout<<q->arr[i]<<"  ";
    cout<<endl;
    return;
  }
  if(q->rear<q->front)
  { for(int i=q->front;i<=max-1;i++)
    cout<<q->arr[i]<<"  ";
    for(int j=0;j<=q->rear;j++)
    cout<<q->arr[j]<<"  ";
    cout<<endl;
    return;
  }
}