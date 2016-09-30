#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#define max 18
struct term
{ int coeff;
  int exp;
};
struct poly
{ struct term objs[18];
  int noofterms;
};
void init(struct poly *);
void polyappend(struct poly *,int ,int );
void display(struct poly);
struct poly polyadd(struct poly ,struct poly );
struct poly polymul(struct poly,struct poly);
void main()
{ clrscr();
  struct poly p1,p2,p3;
  init(&p1);init(&p2);init(&p3);
  polyappend(&p1,1,4);polyappend(&p1,2,3);polyappend(&p1,2,2);polyappend(&p1,2,1);
  display(p1);
  polyappend(&p2,2,3);polyappend(&p2,3,2);polyappend(&p2,4,1);
  display(p2);
  p3=polymul(p1,p2);
  display(p3);
  getch();
}
void init(struct poly *p)
{ for(int i=0;i<max;i++)
  { p->objs[i].exp=0;
    p->objs[i].coeff=0;
  }
  p->noofterms=0;
}
void polyappend(struct poly *p,int c,int e)
{ p->objs[p->noofterms].coeff=c;
  p->objs[p->noofterms].exp=e;
  (p->noofterms)++;
}
void display(struct poly p)
{ for(int i=0;i<p.noofterms;i++)
  { if(p.objs[i].exp!=0)
    { cout<<p.objs[i].coeff<<"x^"<<p.objs[i].exp;
    }
    else
    { cout<<p.objs[i].coeff;
    }
    if(i+1!=p.noofterms)
    cout<<" + ";
  }
  cout<<endl;
}
struct poly polyadd(struct poly p1,struct poly p2)
{ int c; int i=0;int j=0; int k=0;
  struct poly p3;
  init(&p3);
  while(i!=p1.noofterms && j!=p2.noofterms)
  { if(p1.objs[i].exp>=p2.objs[j].exp)
    { p3.objs[k].exp=p1.objs[i].exp;
       if(p1.objs[i].exp==p2.objs[j].exp)
       { p3.objs[k].coeff=p1.objs[i].coeff+p2.objs[j].coeff;
	 j++;
       }
       else
       { p3.objs[k].coeff=p1.objs[i].coeff;}
       i++;k++;
    }
    else
    { if(p1.objs[i].exp<p2.objs[j].exp)
      { p3.objs[k].exp=p2.objs[j].exp;
	p3.objs[k].coeff=p2.objs[j].coeff;
	j++;
	k++;
      }
    }
  }
  while(i!=p1.noofterms)
  { p3.objs[k].exp=p1.objs[i].exp;
    p3.objs[k].coeff=p1.objs[i].coeff;
    i++;
    k++;
  }
  while(j!=p2.noofterms)
  { p3.objs[k].exp=p2.objs[j].exp;
    p3.objs[k].coeff=p2.objs[j].coeff;
    j++;
    k++;
  }
  p3.noofterms=k;
  return p3;
}
struct poly polymul(struct poly p1,struct poly p2)
{ int k=0;  struct poly p3;init(&p3);   p3.noofterms=0;  int exp,coeff;  struct poly temp;

  for(int i=0;i<p1.noofterms;i++)
  { struct poly p;init(&p);
    for(int j=0;j<p2.noofterms;j++)
    { exp=p1.objs[i].exp+p2.objs[j].exp;
      coeff=p1.objs[i].coeff*p2.objs[j].coeff;
      polyappend(&p,coeff,exp);
    }
    if(i==0)
    { temp=p; }
    else
    { p3=polyadd(temp,p);
      temp=p3;
    }
  }
  return p3;
}





