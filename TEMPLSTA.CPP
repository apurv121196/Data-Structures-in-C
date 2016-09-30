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
  node<A>* link;

  public:
  node<A> *q;
  node()
  { q=NULL;
  }
  void init(A );
  void insert(A );
  A del();
  void display();
}

//  LINKED LIST UNDER

template<class A>
void node<A>::init(A num)
{ q=new node<A>;
  (q)->data=num;
  (q)->link=NULL;
}
template<class A>
void node<A>::insert(A num)
{ if(q==NULL)
  { node<A>::init(num);
    return;
  }
  node<A> *temp=q;
  while(temp->link!=NULL)
  { temp=temp->link; }
  temp->link=new node<A>;
  temp->link->data=num;
  temp->link->link=NULL;
}
template<class A>
A node<A>::del()
{ if(q==NULL)
  { cout<<"Nothing to delete!\n";
    return 0;
  }
  if((q)->link==NULL)
  { A dat=q->data;
    q=NULL;
    return dat;
  }
  node<A> *temp=q;
  while(temp->link->link!=NULL)
  { temp=temp->link; }
  A dat=temp->link->data;
  temp->link=NULL;
  return dat;
}
template<class A>
void node<A>::display()
{ if(q==NULL)
  { return;
  }

  while(q!=NULL)
  { cout<<q->data<<"  ";
    q=q->link;
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
  //node<A>* head=NULL;
  integ.init(1);
  integ.insert(2);
  integ.insert(3);
  integ.display();
  cout<<"Float Linked list:\n";
  node<float> floating;
  floating.init(1.1);
  floating.insert(2.3);
  floating.insert(3.4);
  floating.display();
  cout<<"Character Linked list:\n";
  node<char> charac;
  charac.init('a');
  charac.insert('b');
  charac.insert('c');
  charac.display();
  getch();
}