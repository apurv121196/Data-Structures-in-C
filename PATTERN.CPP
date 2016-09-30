#include<iostream.h>
#include<conio.h>
#include<stdio.h>


void main()
{ clrscr();
  int i,n;
  cout<<"Enter number of rows:\n";
  cin>>n;
  for(i=0;i<n;i++)
  { for(int j=1;j<=i;j++)
    cout<<"0";
    for(int k=0;k<n-i;k++)
    cout<<"1";
    cout<<endl;
   }
 getch();
}