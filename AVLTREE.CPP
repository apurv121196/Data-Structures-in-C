#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<alloc.h>
struct node
{ int data;
  struct node *left,*right;
  int balfact;
};
struct node *buildtree(struct node *,int ,int* );
void display(struct node *);
void main()
{ clrscr();
  struct node *root=NULL;
  int *h;

  getch();
}
struct node *buildtree(struct node *root,int num,int *h)
{ if(root=NULL)
  { root=(struct node *)malloc(sizeof(struct node));
    root->data=num;
    root->right=root->left=NULL;
    root->balfact=0;
    *h=TRUE;
    return(root);
  }
  if(num<root->data)
  { root->left=buildtree(root->left,num,h);
    if(*h)
    { switch(root->balfact)
      { case 1:  struct node *node1=root->left;
		 if(node1->balfact==1)
		 { cout<<"LL rotation along"<<root->data<<endl;
		   root->left=node1->right;
		   node1->right=root;
		   root->balfact=0;
		   root=node1;
		 }
		 else
		 { cout<<"implementing LR rotation"<<endl;
		   struct node *node2=node1->right;
		   node1->right=node2->left;
		   node2->left=node1;
		   root->left=node2->right;
		   node2->right=root;
		   if(node->balfact==1)
		   { root->balfact=-1;
		   }
		   else
		   { root->balfact=0;
		   }
		   if(node2->balfact==-1)
		   { node1->balfact=1;
		   }
		   else
		   { node1->balfact=0;
		   }
		   root=node2;
		 }
		 root->balfact=0;
		 *h=FALSE;
		 break;
      case:0 root->balfact=1;
	     break;
      case:-1 root->balfact=0;
	      *h=FALSE;
	      //break;
      }
    }
  }
  if(data>=root->data)
  { root->right=buildtree(root->right,num,h);
    if(*h)
    { switch(root->balfact)
      { case:1 root->balfact=0;
	       *h=FALSE;
	       break;
	case:0 root->balfact=-1;
	       break;
	case:-1 node1=root->right;
		if(node1->balfact==-1)
		{ cout<<"RR rotation along "<<root->data<<endl;
		  root->right=node1->left;
		  node1->left=root;
		  root->balfact=0;
		  root=node1;
		}
		else
		{ cout<<"RL rotation\n";
		  node2=node1->left;
		  node1->left=node2->right;
		  node2->right=node1;
		  root->right=node2->left;
		  node2->left=root;
		  if(node2->balfact==-1)
		  { root->balfact=1;
		  }
		  else
		  { root->balfact=0;
		  }
		  if(node2->balfact==1)
		  { node1->balfact=-1;
		  }
		  else
		  { node1->balfact=0;
		  }
		  root=node2;
		}
		root->balfact=0;
		*h=FALSE;
      }
    }
  }
  return (root);
}

