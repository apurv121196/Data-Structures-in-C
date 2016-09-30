#include<iostream.h>
#include<conio.h>
#include<alloc.h>
#define FALSE 0
#define TRUE 1
struct node
{ int data,balfact;
  struct node *left,*right;
};
struct node *buildtree(struct node *,int ,int *);
void inorder(struct node *);
void main()
{ clrscr();
  struct node *root=NULL;int h;
  root=buildtree(root,1,&h);
  root=buildtree(root,2,&h);
  root=buildtree(root,3,&h);
  root=buildtree(root,4,&h);
  root=buildtree(root,5,&h);
  cout<<root->data;inorder(root);
  getch();
}
struct node *buildtree(struct node *root,int num,int *h)
{ struct node *node1,*node2;
  if(root==NULL)
  { root=(struct node *)malloc(sizeof(struct node));
    root->left=root->right=NULL;
    root->data=num;
    root->balfact=0;
    *h=TRUE;
    return (root);
  }
  if(num<root->data)
  { root->left=buildtree(root->left,num,h);
    if(*h)
    { switch(root->balfact)
      { case 1: node1=root->left;
	       if(node1->balfact==1)
	       { cout<<"Implementing LL rotation along "<<root->data<<endl;
		 root->left=node1->right;
		 node1->right=root;
		 root->balfact=0;
		 root=node1;
	       }
	       else
	       { cout<<"Implementing LR rotation along "<<root->data<<endl;
		 node2=node1->right;
		 node1->right=node2->left;
		 node2->left=node1;
		 root->left=node2->right;
		 node2->right=root;
		 if(node2->balfact==1)
		 { root->balfact=0;
		 }
		 else
		 { root->balfact=1;
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
      case 0:   root->balfact=1;
	       break;
      case -1:  root->balfact=0;
	       *h=FALSE;
      }
    }
  }

   if(num>root->data)
    { root->right=buildtree(root->right,num,h);
      if(*h)
      { switch(root->balfact)
	{ case 1:  root->balfact=0;
		  *h=FALSE;
		  break;
	  case 0:  root->balfact=-1;
		  break;
	  case -1: node1=root->right;
		  if(node1->balfact==-1)
		  { cout<<"Implementing RR rotation along "<<root->data<<endl;
		    root->right=node1->left;
		    node1->left=root;
		    root->balfact=0;
		    root=node1;
		  }
		  else
		  { cout<<"Implementing RL rotation along "<<root->data<<endl;
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
      return(root);
}
void inorder(struct node*root)
{ if(root!=NULL)
  { inorder(root->left);
    cout<<root->data;
    inorder(root->right);
  }
}
