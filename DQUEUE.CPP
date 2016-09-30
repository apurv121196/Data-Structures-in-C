#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#define max 5
struct dqueue
{ int arr[5];
  int front;
  int rear;
};
void init(struct dqueue *);
void addatfront(struct dqueue *,int );
void addatend(struct dqueue *,int );
void display(struct dqueue *);
void delbeg(struct dqueue *);
void delend(struct dqueue *);
void main()
{ clrscr();
  struct dqueue *w;
  init(w);
  addatend(w,1);
  addatend(w,2);
  addatend(w,3);
  addatend(w,4);
  addatend(w,5);
  display(w);
  delend(w);
  addatfront(w,9);
  display(w);
  getch();
}
void init(struct dqueue *q)
{ q->front=-1;
  q->rear=-1;
}
void addatend(struct dqueue *q,int data)
{ if(q->front==0 && q->rear==max-1)
  { cout<<"Dqueue is full!\n";
    return;
  }
  if(q->front==-1)
  { q->front=q->rear=0;
    q->arr[q->rear]=data;
    return;
  }
  if(q->rear==max-1)
  { for(int i=q->front;i<=max-1;i++)
    q->arr[i-1]=q->arr[i];
    q->arr[i-1]=data;
    q->front--;
    return;
  }
  q->rear++;
  q->arr[q->rear]=data;
}
void addatfront(struct dqueue *q,int data)
{ if(q->front==0 && q->rear==max-1)
  { cout<<"Queue is full!\n";
    return;
  }
  if(q->front==-1)
  { addatend(q,data);
    return;
  }
  if(q->front==0)
  { for(int i=q->rear;i>=q->front;i--)
    q->arr[i+1]=q->arr[i];
    q->arr[0]=data;
    q->rear++;
    return;
  }
  q->front--;
  q->arr[q->front]=data;
}
void display(struct dqueue *q)
{ if(q->front==-1)
  { cout<<"Dqueue is empty!\n";
    return;
  }
  for(int i=q->front;i<=q->rear;i++)
  cout<<q->arr[i]<<"  ";
  cout<<endl;
}
void delbeg(struct dqueue *q)
{ if(q->front==-1)
  { cout<<"Dqueue is empty\n";
    return;
  }
  if(q->rear==q->front)
  { q->front=q->rear=-1;
    return;
  }
  q->arr[q->front]=0;
  q->front++;
}
void delend(struct dqueue *q)
{ if(q->front==-1)
  { cout<<"Dqueue is empty";
    return;
  }
  if(q->rear==q->front)
  { q->front=q->rear=-1;
    return;
  }
  q->arr[q->rear]=0;
  q->rear--;
}