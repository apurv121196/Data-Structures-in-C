#include<iostream.h>
#include<conio.h>
#include<stdio.h>
template<class A>
class node
{ public:
  A data;
  node<A> *link;
};
template<class A>
class list
{ node<A> *head;
  public:
  list()
  { head=NULL;
  }
  void addafter();
  void addatbeg();
  A del();
  void display();
};
template<class A>
void list<A>::addafter()
{ A num,numpre;
  cout<<"Enter element to be inserted:  ";
  cin>>num;
  if(head==NULL)
  { head=new node<A>;
    head->link=NULL;
    head->data=num;
    return;
  }
  cout<<"After which element do you want to perform this operation?  ";
  cin>>numpre;
  node<A> *temp=head; node<A> *newnode;
  while(temp->data!=numpre)
  { temp=temp->link;
  }
  newnode=new node<A>;
  newnode->data=num;
  newnode->link=temp->link;
  temp->link=newnode;
}
template<class A>
void list<A>::addatbeg()
{ A num;
  node<A> *newnode;
  newnode=new node<A>;
  cout<<"Enter element to be inserted:  ";
  cin>>num;
  newnode->data=num;
  newnode->link=head;
  head=newnode;
}
template<class A>
void list<A>::display()
{ if(head==NULL)
  { cout<<"Nothing to display!\n";
    return;
  }
  cout<<"Displaying elements:\n";
  node<A> *temp=head;
  while(temp!=NULL)
  { cout<<temp->data<<"  ";
    temp=temp->link;
  }
  cout<<endl;
}
template<class A>
A list<A>::del()
{ A num;
  if(head==NULL)
  { cout<<"Nothing to delete!\n";
    return 0;
  }
  cout<<"Enter element to be deleted:  ";
  cin>>num;
  if(head->data==num)
  { node<A> *temp=head;
    head=head->link;
    delete(temp);
    return num;
  }
  node<A> *temp=head;
  while(temp->link->data!=num)
  { temp=temp->link;
  }
  node<A> *delitem=temp->link;
    temp->link=delitem->link;
    delete(delitem);
    return num;
}
void main()
{ clrscr();
  int ch;
  list<int> intlist;
  cout<<"  1.Adding node\n  2.Add node at beginning\n  3.Delete a node\n  4.Display the Linked List\n  5.Exit\n";
  do
  { cout<<"Enter your choice:  ";
    cin>>ch;
    switch(ch)
    { case 1: intlist.addafter();
	      break;
      case 2: intlist.addatbeg();
	      break;
      case 3: intlist.del();
	      break;
      case 4: intlist.display();
	      break;
      case 5: return;
      default: intlist.addafter();
	       break;
    }
  } while(ch>=1 && ch<=5);
  getch();
}






