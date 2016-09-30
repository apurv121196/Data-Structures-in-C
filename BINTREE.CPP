#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<alloc.h>
struct node
{ char data;
  struct node *left;
  struct node *right;
};
char arr[]={'A','B','C','D','E','F','\0','\0','G','\0','H','\0','I'};
struct node *buildtree(int );
void display(struct node *);
void main()
{ clrscr();
  struct node *root=buildtree(0);
  display(root);
  getch();
}
struct node *buildtree(int n)
{ struct node *temp=NULL;
  if(arr[n]!='\0')
  { temp=(struct node *)malloc(sizeof(struct node));
    temp->left=buildtree(2*n+1);
    temp->data=arr[n];
    temp->right=buildtree(2*n+2);
  }
  return temp;
}
void display(struct node *root)
{ if(root!=NULL)
  { display(root->left);
    cout<<root->data<<"  ";
    display(root->right);
  }
  else
  return;
}