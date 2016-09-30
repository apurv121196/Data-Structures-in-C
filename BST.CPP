#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<alloc.h>
#define TRUE 1
#define FALSE 0
struct node
{ int data;
  struct node *left;
  struct node *right;
};
void insert(struct node **,int );
void inorder(struct node *);
void search(struct node *,int ,struct node **,struct node **,int *);
void del(struct node **,int );
void main()
{ clrscr();
  struct node *root=NULL;
  insert(&root,4);insert(&root,5);insert(&root,1);insert(&root,3);insert(&root,2);
  inorder(root);
 // struct node *par;struct node *n;int *res;
 // search(root,93,&par,&n,res);
 // cout<<*res;
  del(&root,4);
  inorder(root);
  getch();
}
void insert(struct node **root,int num)
{ if(*root==NULL)
  { *root=(struct node *)malloc(sizeof(struct node));
    (*root)->left=NULL;
    (*root)->right=NULL;
    (*root)->data=num;
    return;
  }
  else
  { if(num<=(*root)->data)
    insert(&((*root)->left),num);
    else
    insert(&((*root)->right),num);
  }
}
void inorder(struct node *root)
{ if(root!=NULL)
  { inorder(root->left);
    cout<<root->data<<"  ";
    inorder(root->right);
  }
}
void search(struct node *root,int num,struct node **par,struct node **x,int *result)
{ struct node *q=root;
  *result=FALSE;
  *par=NULL;
  while(q!=NULL)
  { if(q->data==num)
    { *x=q;
      *result=TRUE;
      cout<<"\nElement "<<num<<" found\n";
      return;
    }
    *par=q;
    if(q->data<=num)
      q=q->right;
    else
      q=q->left;
  }
  cout<<"\nElement "<<num<<" not found\n";
}
void del(struct node **root,int num)
{ if(root==NULL)
  { cout<<"Nothing to delete\n";
    return;
  }
  struct node *par,*x,*xsucc;
  int res;
  search(*root,num,&par,&x,&res);
  if(res==FALSE)
  { cout<<"Element to be deleted not found\n";
    return;
  }
  if(x->left!=NULL && x->right!=NULL)
  { par=x;
    xsucc=x->right;
    while(xsucc->left!=NULL)
    { par=xsucc;
      xsucc=xsucc->left;
    }
    x->data=xsucc->data;
    x=xsucc;
  }
  if(x->left==NULL && x->right==NULL)
  { if(par->left==x)
      par->left=NULL;
    else
      par->right=NULL;
    free(x);
    return;
  }
  if(x->left==NULL && x->right!=NULL)
  { if(par->left==x)
    par->left=x->right;
    else
    par->right=x->right;
    free(x);
    return;
  }
  if(x->right==NULL && x->left!=NULL)
  { if(par->left==x)
    par->left=x->left;
    else
    par->right=x->left;
    free(x);
    return;
  }
}