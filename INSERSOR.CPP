#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#define max 10
void create(int *);
void display(int *);
void insersort(int *);
void main()
{ clrscr();
  int arr[10];
  create(arr);
  display(arr);
  insersort(arr);
  display(arr);
  getch();
}
void create(int *arr)
{ cout<<"Enter elements:\n";
  for(int i=0;i<max;i++)
  cin>>arr[i];
  cout<<endl;
}
void display(int *arr)
{ cout<<"Displaying elements:\n";
  for(int i=0;i<max;i++)
  cout<<arr[i]<<"  ";
  cout<<endl;
}
void insersort(int *arr)
{ int val,i,j,k;
  for(i=1;i<max;i++)
  { val=arr[i];
    for(j=0;j<i;j++)
    { if(arr[i]<arr[j])
      { for(k=i;k>j;k--)
	{ arr[k]=arr[k-1];
	}
	arr[j]=val;
      }
    }
  }
}