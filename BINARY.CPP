#include<iostream.h>
#include<conio.h>
#include<stdio.h>
struct node
{ char data;
  struct node *left;
  struct node *right;
};
char arr[]={'A','B','C','D','E','F','G','\0','\0','H'} ;
int lc[]={1,3,5,-1,9,-1,-1,-1,-1,-1};
int rc[]={2,4,6,-1,-1,-1,-1,-1,-1,-1};
struct node *buildtree(int index);
