#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<alloc.h>
struct node
{ int data;
  struct node *left;
  struct node *right;
};
void addatend(struct node **,int );
void addatbeg(struct node **,int );
void addafter(struct node *,int ,int );
void display(struct node *);
void del(struct node **,int );
void main()
{ clrscr();
  struct node *p=NULL;
  addatend(&p,1);
  addatend(&p,3);
  addatbeg(&p,0);
  display(p);
  addafter(p,3,2);
  display(p);
  del(&p,3);
  display(p);
  getch();
}
void addatend(struct node **q,int num)
{
  if(*q==NULL)
  { *q=(struct node *)malloc(sizeof(struct node));
    (*q)->data=num;
    (*q)->right=NULL;
    (*q)->left=NULL;
    return;
  }
  struct node *r=*q;
  while(r->right!=NULL)
  { r=r->right;
  }
  struct node *temp=(struct node *)malloc(sizeof(struct node));
  temp->data=num;
  temp->right=NULL;
  temp->left=r;
  r->right=temp;
}
void display(struct node *q)
{ while(q!=NULL)
  { cout<<q->data<<"  ";
    q=q->right;
  }
  cout<<endl;
}
void addatbeg(struct node **q,int num)
{
  if(*q==NULL)
  { (*q)=(struct node *)malloc(sizeof(struct node));
    (*q)->data=num;
    (*q)->left=NULL;
    (*q)->right=NULL;
    return;
  }
  struct node *temp=(struct node *)malloc(sizeof(struct node));
  temp->data=num;
  temp->left=NULL;
  temp->right=*q;
  (*q)->left=temp;
  (*q)=temp;
}
void addafter(struct node *q,int loc,int num)
{ if(q==NULL)
  { addatbeg(&q,num);
    return;
  }
  for(int i=1;i<loc;i++)
  { q=q->right;
  }
  q=q->left;
  addatbeg(&(q->right),num);
  struct node *temp=q;
  temp=temp->right;
  temp->left=q;
}
void del(struct node **q,int num)
{ struct node *temp=*q;
  while(temp!=NULL)
  { if(temp->data==num)
    { if(temp==*q)
      { (*q)=(*q)->right;
	(*q)->left=NULL;

      }
      else
      { if(temp->right==NULL)
	{ temp->left->right=NULL;

	}
	else
	{ temp->left->right=temp->right;
	  temp->right->left=temp->left;

	}
      free(temp);
      }
      return;
    }
    temp=temp->right;
  }
  printf("Element %d not foundn",num);
}
