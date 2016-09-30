#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<alloc.h>
struct node
{ float coeff;
  int exp;
  struct node *link;
};
void append(struct node **,float ,int );
void display(struct node *);
void polyadd(struct node *,struct node *,struct node **);
void polymul(struct node *,struct node *,struct node **);
void main()
{ clrscr();
  struct node *first,*second,*third;
  first=second=third=NULL;
  append(&first,1,2);
  append(&first,2,1);
  append(&first,3,0);
  display(first);
  append(&second,1,2);
  append(&second,2,1);
  append(&second,3,0);
  display(second);
  cout<<"-------------------\n";
  polymul(first,second,&third);
  display(third);
  getch();
}
void append(struct node **q,float c,int e)
{ if(*q==NULL)
  { (*q)=(struct node *)malloc(sizeof(struct node));
    (*q)->link=NULL;
    (*q)->coeff=c;
    (*q)->exp=e;
    return;
  }
  append(&((*q)->link),c,e);
}
void display(struct node *q)
{ if(q==NULL)
  { cout<<endl;
    return;
  }
  cout<<q->coeff<<"x^"<<q->exp;
  if(q->link!=NULL)
  { cout<<" + ";
  }
  display(q->link);
}
void polyadd(struct node *a,struct node *b,struct node **c)
{ struct node *z;
  if(a==NULL && b==NULL)
  { return;
  }
  while(a!=NULL && b!=NULL)
  { if(*c==NULL)
    { *c=(struct node *)malloc(sizeof(struct node));
      z=*c;
    }
    else
    { z->link=(struct node *)malloc(sizeof(struct node));
      z=z->link;
    }
    if(a->exp>b->exp)
    { z->coeff=a->coeff;
      z->exp=a->exp;
      a=a->link;
    }
    else
    { if(a->exp<b->exp)
      { z->coeff=b->coeff;
	z->exp=b->exp;
	b=b->link;
      }
      else
      { z->coeff=a->coeff+b->coeff;
	z->exp=a->exp;
	a=a->link;
	b=b->link;
      }
    }
  }
  while(a!=NULL)
  { if(*c==NULL)
    { *c=(struct node *)malloc(sizeof(struct node));
      z=*c;
    }
    else
    { z->link=(struct node *)malloc(sizeof(struct node));
      z=z->link;
    }
    z->coeff=a->coeff;
    z->exp=a->exp;
    a=a->link;
  }
  while(b!=NULL)
  { if(*c==NULL)
    { *c=(struct node *)malloc(sizeof(struct node));
      z=*c;
    }
    else
    { z->link=(struct node *)malloc(sizeof(struct node));
      z=z->link;
    }
    z->coeff=b->coeff;
    z->exp=b->exp;
    b=b->link;
  }
  z->link=NULL;
}
void polymul(struct node *a,struct node *b,struct node **c)
{ struct node *z;
  if(a==NULL && b==NULL)
  { return;
  }
  if(a==NULL)
  { *c=b;
    return;
  }
  else
  { if(b==NULL)
    { *c=a;
      return;
    }
    struct node *temp=b;
    while(a!=NULL)
    {
      while(b!=NULL)
      { if(*c==NULL)
	{ *c=(struct node *)malloc(sizeof(struct node));
	  z=*c;
	}
	else
	{ z->link=(struct node *)malloc(sizeof(struct node));
	  z=z->link;
	}
	z->coeff=(a->coeff)*(b->coeff);
	z->exp=(a->exp)+(b->exp);
	b=b->link;
      }
      a=a->link;
      b=temp;
    }
  }
  z->link=NULL;
}