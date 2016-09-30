#include<iostream.h>
#include<conio.h>
#include<alloc.h>
#include<stdio.h>
struct node
{ int data;
  struct node *link;
};
void add(struct node **,int );
void display(struct node *);
void selsort(struct node **);
void bubsort(struct node **);
void apsort(struct node **);
void main()
{ clrscr();
  struct node *p=NULL;
  add(&p,3);
  add(&p,1);
  add(&p,4);
  add(&p,2);
  add(&p,5);
  display(p);
  //bubsort(&p);
  //display(p);
  apsort(&p);
  display(p);
  getch();
}
void add(struct node **q,int num)
{ if(*q==NULL)
  { *q=(struct node *)malloc(sizeof(struct node));
    (*q)->data=num;
    (*q)->link=NULL;
  }
  else
  { struct node *temp=*q;
    while(temp->link!=NULL)
    { temp=temp->link;
    }
    temp->link=(struct node *)malloc(sizeof(struct node));
    temp->link->data=num;
    temp->link->link=NULL;
  }
}
void display(struct node *q)
{ struct node *temp=q;
  while(temp!=NULL)
  { cout<<temp->data<<"  ";
    temp=temp->link;
  }    cout<<endl;
}
void selsort(struct node **start)
{ struct node *p=*start;     struct node *temp;
  struct node *q=p->link;
  struct node *r=p;
  struct node *s=p;
  while(p->link!=NULL)
  { s=q=p->link;
    while(q!=NULL)
    { if(p->data>q->data)
      { if(p->link==q)
	{ if(p==*start)
	  { p->link=q->link;
	    q->link=p;
	    temp=p;
	    p=q;
	    q=temp;
	    r=p;
	    *start=p;
	    s=q;
	    q=q->link;
	  }
	  else
	  { p->link=q->link;
	    q->link=p;
	    r->link=q;
	    temp=p;
	    p=q;
	    q=temp;
	    s=q;
	    q=q->link;
	  }
	}
	else
	{ if(p==*start)
	  { temp=p->link;
	    p->link=q->link;
	    s->link=p;
	    q->link=temp;
	    temp=p;
	    p=q;
	    q=temp;
	    r=p;
	    *start=p;
	    s=q;
	    q=q->link;
	  }
	  else
	  { temp=p->link;
	    r->link=q;
	    p->link=q->link;
	    q->link=temp;
	    s->link=p;
	    temp=p;
	    p=q;
	    q=temp;
	    s=q;
	    q=q->link;
	  }
	}
      }
      else
      { s=q;
	q=q->link;
      }
    }
    r=p;
    p=p->link;
  }
}
void bubsort(struct node **start)
{ struct node *p,*q,*r,*s,*temp;
  s=NULL;
  while(s!=(*start)->link)
  { p=r=*start;
    q=p->link;
    while(p!=s)
    { if(p->data>q->data)
      { if(p==*start)
	{ p->link=q->link;
	  q->link=p;
	  r=q;
	  *start=q;
	}
	else
	{ p->link=q->link;
	  r->link=q;
	  q->link=p;
	  r=q;
	}
      }
      else
      { r=p;
	p=p->link;
      }
      q=p->link;
      if(q==s)
      s=p;
    }
  }
}
void apsort(struct node **start)
{ struct node *p,*q,*r,*s,*t; int c=1;
  r=p=q=*start;    struct node *temp; struct node *e;

  while(p->link!=NULL)
  {  q=*start; t=*start;  c=1;    //cout<<"r";
    while(t!=NULL)
    { if(t->data<p->data)
      { c++;
      }
      t=t->link;
    }
    if(c==1)
    { r=p;
      p=p->link;
    }
    else
    { for(int i=1;i<c;i++)
      { s=q;
	q=q->link;
      }
      if(p==q)
      return;
      if(p->link==q)
      { if(p==*start)
	{ p->link=q->link;
	  q->link=p;
	  temp=p;
	  p=q;
	  q=temp;
	  *start=p;
	  r=p;
	  //cout<<"1";
	}
	else
	{ p->link=q->link;
	  q->link=p;
	  r->link=q;
	  temp=p;
	  p=q;
	  q=temp;

	   //cout<<"2";
	}
      }
      else
      { if(p==*start)
	{   e=p->link;
	    p->link=q->link;
	    s->link=p;
	    q->link=e;

	    temp=p;
	    p=q;
	    q=temp;
	    *start=p;
	    r=p;
	  //cout<<"3";

	  }
	else
	{ e=p->link;
	  p->link=q->link;
	  s->link=p;
	  q->link=e;
	  r->link=q;
	    temp=p;
	    p=q;
	    q=temp; //cout<<"4"; return;
	}
      }
    }//c dcsn
  } //while
}









