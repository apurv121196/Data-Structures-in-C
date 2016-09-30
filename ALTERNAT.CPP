#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#define max 10
template<class T>
class stack
{ private:
  T arr[10];
  int top;
  public:
  stack()
  { top=-1;
  }
  void insert(T );
  T del();
  void display();
};
template<class A>
class node
{ private:
  A data;
  node* link;
  public:
  node()
  { link=NULL;
  }
  void init(node** ,A );
  void insert(A );
  A del(node** );
  void display(node* );
}

//  LINKED LIST UNDER

template<class A>
void node<A>::init(node** q,A num)
{ *q=new node;
  (*q)->data=num;
  (*q)->link=NULL;
}
template<class A>
void node<A>::insert(node* q,A num)
{ if(q==NULL)
  { node::init(&q,num)
    return;
  }
  node** temp=q;
  while(temp->link!=NULL)
  { temp=temp->link; }
  temp->link=new node;
  temp->link->data=num;
  temp->link->link=NULL;
}
template<class A>
A node<A>::del(node** q)
{ if(*q==NULL)
  { cout<<"Nothing to delete!\n";
    return;
  }
  if((*q)->link==NULL)
  { *q=NULL;
    return;
  }
  node* temp=*q;
  while(temp->link->link!=NULL)
  { temp=temp->link; }
  A dat=temp->link->data;
  temp->link=NULL;
  return dat;
}
template<class A>
void node<A>::display(node* q)
{ if(q==NULL)
  { return;
  }
  while(q!=NULL)
  { cout<<q->data<<"  ";
  }
  cout<<endl;
}

// STACK UNDER

template<class T>
void stack<T>::insert(T num)
{ if(top==max-1)
  { cout<<"Stack is full\n";
    return;
  }
  arr[++top]=num;
}
template<class T>
T stack<T>::del()
{ if(top==0)
  { cout<<"No item to delete\n";
    return NULL;
  }
  T item=arr[top];
  arr[top--]=0;
  return item;
}
template<class T>
void stack<T>::display()
{ if(top==-1)
  { cout<<"No item to display!\n";
    return;
  }
  for(int i=0;i<=top;i++)
  cout<<arr[i]<<"  ";
  cout<<endl;
}
void main()
{ clrscr();
  cout<<"Integer stack:\n";
  stack<int> integer;
  integer.insert(1);
  integer.insert(2);
  integer.insert(3);
  integer.display();
  cout<<"Float stack:\n";
  stack<float> floater;
  floater.insert(1.1);
  floater.insert(2.3);
  floater.insert(3.4);
  floater.display();
  cout<<"Character stack:\n";
  stack<char> character;
  character.insert('a');
  character.insert('b');
  character.insert('c');
  character.display();
  cout<<"Integer Linked list:\n";
  node<int> integ;
  node* head=NULL;
  integ.init(&head,1);
  integ.insert(head,2);
  integ.insert(head,3);
  integ.display(head);
  getch();
}