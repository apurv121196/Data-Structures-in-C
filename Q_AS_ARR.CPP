#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<alloc.h>
#define max 5
struct queue
{ int arr[5];
  int rear;
  int front;
};
void insert(struct queue *);
void del(struct queue *);
void initq(struct queue *);
void display(struct queue *);
void main()
{ clrscr();
  struct queue *p;p=NULL;
  initq(p);
  insert(p);
  display(p);
  del(p);
  display(p);
  getch();
}
void initq(struct queue *q)
{ q->rear=max-1;
  q->front=max-1;
}
void insert(struct queue *q)
{ char ch=0;
  int data;
  do
  { cout<<"Enter element to be inserted in queue:  ";
    cin>>data;
    q->arr[q->rear]=data;
    cout<<"Do you want to insert more elements:(y/n)  ";
    cin>>ch;
    if(ch=='y')
     q->rear--;
    if((q->rear)==-1)
     cout<<"Queue is full\n";

  }while(ch=='y' && (q->rear)!=-1);
  if(q->rear==-1)
  (q->rear)++;
}
void del(struct queue *q)
{ cout<<"Element deleted:  "<<q->arr[max-1]<<endl;
  for(int i=max-2;i>=(q->rear);i--)
  { q->arr[i+1]=q->arr[i];
  }
  (q->rear)++;
}
void display(struct queue *q)
{ cout<<"Displaying elements in queue:\nRear:---   ";
  for(int i=(q->rear);i<=(q->front);i++)
  cout<<q->arr[i]<<"  ";
  cout<<"---:Front"<<endl;
}