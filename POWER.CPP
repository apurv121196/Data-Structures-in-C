#include<iostream.h>
#include<conio.h>
int power(int,int,int);
void main()
{ clrscr();
  int x,y;cin>>x>>y;
  cout<<power(x,y,x);
  getch();
}
int power(int x,int y)
{ int temp=x;
  while(y>1)
  { x*=temp;
    y--;
  }
  return x;
}
int power(int x,int pow,int temp)
{ pow==1?return x:return power(x*temp,--pow,temp);
  //if(pow==1)
  //return x;
  //return power(x*temp,--pow,temp);
}

