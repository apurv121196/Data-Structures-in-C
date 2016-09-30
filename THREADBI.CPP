#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<malloc.h>
enum boolean
{ false=0,
  true=1
};
struct node
{ int data;
  struct node *left;
  struct node *right;
  enum boolean isright;
  enum boolean isleft;
};
void insert(struct node ** ,int );
void display(struct node *);
void search(struct node *,int ,struct node **,struct node **,int * );
void del(struct node **,int );
void main()
{ clrscr();
  struct node *p=NULL;
  insert(&p,3);
  insert(&p,2);
  insert(&p,5);
  insert(&p,1);
  insert(&p,4);
  display(p);
  getch();
}
void insert(struct node **q,int num)
{ struct node *z,*p=*q;
  z=(struct node *)malloc(sizeof(struct node));
  z->isleft=true;
  z->isright=true;
  z->data=num;
  if(*q==NULL)
  { *q=(struct node *)malloc(sizeof(struct node));
    (*q)->isleft=false;
    (*q)->isright=false;
    (*q)->data=-999;
    (*q)->left=z;
    (*q)->right=*q;
    z->left=z->right=*q;
    return;
  }
  else
  { p=p->left;
    while(p!=*q)
    {
     if(num<=p->data)
     { if(p->isleft==false)
       { p=p->left;
       }
       else
       { z->left=p->left;
	 z->right=p;
	 p->left=z;
	 p->isleft=false;
	 return;
       }
     }
     else
     { if(num>p->data)
       {
	 if(p->isright==false)
	 { p=p->right;
	 }
	 else
	 { z->left=p;
	   z->right=p->right;
	   p->isright=false;
	   p->right=z;
	   return;
	 }
       }
     }
    }
  }
}
void display(struct node *q)
{ struct node *temp=q->left;
  while(temp!=q)
  { while(temp->isleft==false)
    { temp=temp->left;
    }
    cout<<temp->data<<"  ";
    while(temp->isright==true)
    { temp=temp->right;
      if(temp==q)
      break;
      cout<<temp->data<<"  ";
    }
    temp=temp->right;
  }
}
void search(struct node *root,int num,struct node **parent,struct node **x,int *result)
{ if(root->isleft==true)
  { cout<<"Element not found!\n";
    *result=false;
    *parent=NULL;
    *x=NULL;
    return;
  }
  *parent=NULL; *result=false;
  struct node *temp=root->left;
  while(temp!=root)
  { if(temp->data==num)
    { *result=true;
      *x=temp;
      return;
    }
    *parent=*x;
    if(temp->data>num)
    { if(temp->isleft==true)
      { cout<<"Element not found!\n";
	x=NULL;
	return;
      }
      q=q->left;
    }
    else
    { if(temp->isright==true)
      { cout<<"Element not found!\n";
	x=NULL;
	return;
      }
      q=q->right;
    }
  }
}
void del(struct node **root,int num)
{ if((*root)->isleft==true)
  { cout<<"Nothing to delete!\n";
    return;
  }
  struct node *temp=(*root)->left;
  struct node *parent,*x,*xsucc; int *result;
  search(*root,num,&parent,&x,&result)
  if(*result==false)
  { cout<<"Element to be deleted not found!\n";
    return;
  }
  if(x->isleft!=true && x->isright!=true)
  { xsucc=x->right;
    while(xsucc->left!=true)
    { parent=xsucc;
      xsucc=xsucc->left;
    }
    x->data=xsucc->data;
    x=xsucc;
  }
  if(x->isleft==true && x->isright==true)
  {
    if(parent==NULL)
    { (*root)->left=*root;
      (*root)->isleft=true;
      free(x);
      return;
    }
    if(parent->left==x)
    { parent->left=x->left;
      parent->isleft=true;
    }
    if(parent->right==x)
    { parent->right=x->right;
      parent->isright=true;
    }
    free(x);
    return;
  }
  if(x->isleft==true && x->isright==false)
  { if(parent==NULL)
    { (*root)->left=x->left;
      free(x);
      return;
    }
    if(parent->left==x)
    { parent->isleft=true;
      parent->left=x->left;




