#include<iostream.h>
#include<conio.h>
void main()
{ clrscr();
  int r;
  cin>>r;
  for(int i=0;i<r;i++)
  { for(int j=r-i-1;j>0;j--)
    { cout<<" ";}
    for(int k=0;k<i+1;k++)
    {cout<<"a";}
    cout<<endl;
  }
  getch();
}