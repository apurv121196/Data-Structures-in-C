#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<alloc.h>
#define MAX 10
struct stack
{ int arr[MAX];
  int top;
};
void initstack(struct stack *);
void push(struct stack *,int );
void display(struct stack *);
void pop(struct stack *);
void main()
{
 clrscr();
 struct stack s;
 initstack(&s);
 push(&s,1);
 push(&s,2);
 push(&s,3);
 push(&s,4);
 push(&s,5);
 push(&s,6);
 push(&s,7);
 push(&s,8);
 push(&s,9);
 push(&s,10);
 display(&s);
 push(&s,11);
 pop(&s);
 display(&s);
 getch();
}
void initstack(struct stack *q)
{ q->top=-1;
  cout<<"\t\t\t   ***** STACK *****\n";
}
void push(struct stack *q,int data)
{ if(q->top==MAX-1)
  { cout<<"Stack is full....operation terminated";
    return;
  }
  cout<<"Adding "<<data<<" in the stack\n";
  q->top++;
  q->arr[q->top]=data;
}
void pop(struct stack *q)
{ if(q->top==-1)
  { cout<<"\nStack is empty....operation terminated";
    return;
  }
  int data=q->arr[q->top];
  q->top--;
  cout<<"\nElement "<<data<<" removed\n";
}
void display(struct stack *q)
{ cout<<"Displaying stack\n";
  if(q->top==-1)
  { cout<<"stack is empty\n";
    return;
  }
  for(int i=0;i<=q->top;i++)
  cout<<q->arr[i]<<"\t";
}