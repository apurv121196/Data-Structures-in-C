#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define max 5
struct data
{ char job[max];
  int order;
  int prno;
};
struct queue
{ struct data d[max];
  int front;
  int rear;
};
void init(struct queue *);
void insert(struct queue *,struct data );
void del(struct queue *);
void display(struct queue *);
void main()
{ clrscr();
  struct queue *p;
  struct data dt,temp;
  init(p);
  for(int i=0;i<max;i++)
  { cout<<"Job   Priority\n";
    gets(dt.job);
    cout<<"      ";
    cin>>dt.prno;
    dt.order=i+1;
    insert(p,dt);
  }
  cout<<"\nJob  Priority\n";
  for(i=0;i<max;i++)
  {
    cout<<p->d[i].job<<"  "<<p->d[i].prno<<endl;
  }

  getch();
}
void init(struct queue *q)
{ q->front=q->rear=-1;
  for(int i=0;i<max;i++)
  { q->d[i].order=q->d[i].prno=0;
    strcpy(q->d[i].job,'\0');
  }
}
void insert(struct queue *q,struct data dt)
{ struct data temp;
  if(q->rear==max-1)
  { cout<<"Queue is full!\n";
    return;
  }
  if(q->front==-1)
  { q->front=0;
  }
  q->rear++;
  q->d[q->rear]=dt;
  for(int i=q->front;i<=q->rear;i++)
  { for(int j=i+1;j<=q->rear;j++)
    { if(q->d[i].prno>q->d[j].prno)
      { temp=q->d[i];
	q->d[i]=q->d[j];
	q->d[j]=temp;
      }
      else
      { if(q->d[i].prno==q->d[j].prno)
	{ if(q->d[i].order>q->d[i].order)
	  { temp=q->d[i];
	    q->d[i]=q->d[j];
	    q->d[j]=temp;
	  }
	}
      }
    }
  }
}
void del(struct queue *q)
{ if(q->front==-1)
  { cout<<"Queue is empty";
    return;
  }
  if(q->front==q->rear)
  { q->front=q->rear=-1;
    return;
  }
  struct data t;
  strcpy(t.job,"");
  t.prno=0;
  t.order=0;
  q->d[q->front]=t;
  q->front++;
}