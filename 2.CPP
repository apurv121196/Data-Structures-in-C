#include<iostream.h>
#include<conio.h>
#include<alloc.h>
enum boolean
{ true=1,false=0
};
struct node
{ int data;
  struct node *left,*right;
  enum boolean isleft,isright;
};
void insert(struct node **,int );
void display(struct node *);
void search(struct node **,int ,struct node **,struct node **,int *);
void del(struct node **,int );
void main()
{ clrscr();
  struct node *r=NULL;
  insert(&r,11);insert(&r,12);insert(&r,14);insert(&r,13);insert(&r,15);display(r);
 // del(&r,12);display(r);
  struct node *par,*x;int *found;
 search(&r,12,&par,&x,found);
  getch();
}
void insert(struct node **root,int num)
{
  struct node *z=(struct node *)malloc(sizeof(struct node));
  z->isleft=z->isright=true;
  z->data=num;
  if((*root)==NULL)
  { (*root)=(struct node *)malloc(sizeof(struct node));
    (*root)->left=z;
    (*root)->isleft=false;
    (*root)->isright=false;
    (*root)->right=(*root);
    (*root)->data=-999;
    z->left=z->right=(*root);
    return;
  }
  struct node *q=(*root)->left;
  while(true)
  { if(num<=q->data)
    { if(q->isleft==false)
      q=q->left;
      else
      { z->left=q->left;
	z->right=q;
	q->left=z;
	q->isleft=false;
	return;
      }
    }
    else
    { if(q->isright==false)
      q=q->right;
      else
      { z->left=q;
	z->right=q->right;
	q->isright=false;
	q->right=z;
	return;
      }
    }
  }
}
void display(struct node *root)
{ struct node *temp=root->left;
  while(temp!=root)
  { while(temp->isleft==false)
    { temp=temp->left;
    }
    cout<<temp->data<<"  ";
    if(temp->isright==true)
    { temp=temp->right;
      if(temp==root)
      { break;
      }
      cout<<temp->data<<"  ";
    }
    temp=temp->right;
  }
}
void search(struct node **root,int num,struct node **par,struct node **x,int *result)
{ cout<<"function search called\n";
  struct node *p;    struct node *t=*root;
  p=t->left;
  cout<<"p on the head";
  *par=NULL; *result=false;
  while(p!=t)
  { cout<<"entered while loop\n";
    if(num==p->data)
    { cout<<"number found\n";
      *x=p;cout<<" 1st statement done\n";
      *result=true;cout<<"2nd statement done\n";
      return;
    }
    *par=p;
    if(num<p->data)
    { if(p->isleft==true)
      { *result=false;
	*x=NULL;
	return;
      }
      p=p->left;
    }
    else
    { cout<<"searching inside";
      if(p->isright==true)
      { *result=false;
	*x=NULL;
	return;
      }
      cout<<"p=p->right";
      p=p->right;
    }
  }
}
void del(struct node **root,int num)
{ struct node *parent,*x,*xsucc;
  int *found;    parent=x=NULL;
  cout<<"searching now\n";
  search(root,num,&parent,&x,found);
  cout<<"search done\n";
  if(*found==false)
  { cout<<"Element to be deleted not found!\n";
    return;
  }
  cout<<"working!\n";
  if(x->isleft==false && x->isright==false)
  { parent=x;
    xsucc=x->right;
    while(xsucc->isleft==false)
    { parent=xsucc;
      xsucc=xsucc->left;
    }
    x->data=xsucc->data;
    x=xsucc;
  }
  if(x->isleft==true && x->isright==false)
  { if(parent==NULL)
    { xsucc=x->right;
      while(xsucc->isleft==false)
      { xsucc=xsucc->left;
      }
      xsucc->left=x->left;
      (*root)->left=x->right;
      free(x);
      return;
    }
    if(parent->left==x)
    { xsucc=x->right;
      while(xsucc->isleft==false)
      { xsucc=xsucc->left;
      }
      xsucc->left=x->left;
      parent->left=x->right;
    }
    else
    { cout<<"its working too!\n";
      xsucc=x->right;
      while(xsucc->isleft==false)
      { xsucc=xsucc->left;
      }
      xsucc->left=parent;
      parent->right=x->right;
    }
    free(x);
    return;
  }
  if(x->isleft==false && x->isright==true)
  { if(parent==NULL)
    { xsucc=x->left;
      while(xsucc->isright==false)
      { xsucc=xsucc->right;
      };
      xsucc->right=x->right;
      (*root)->left=x->left;
    }
    if(parent->left==x)
    { xsucc=x->left;
      while(xsucc->isright==false)
      { xsucc=xsucc->right;
      }
      xsucc->right=parent;
      parent->left=x->left;
    }
    else
    { xsucc=x->left;
      while(xsucc->isleft==false)
      { xsucc=xsucc->right;
      }
      xsucc->right=x->right;
      parent->right=x->left;
    }
  }
  if(x->isleft==true && x->isright==true)
  { if(parent==NULL)
    { (*root)->isleft=true;
      (*root)->left=*root;
      free(x);
      return;
    }
    if(parent->left==x)
    { parent->isleft=true;
      parent->left=x->left;
    }
    else
    { parent->right=x->right;
      parent->isright=true;
    }
    free(x);
    return;
  }
}







