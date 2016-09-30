  //program to subtract 2 fractions
#include<iostream.h>
#include<conio.h>
void main()
{ clrscr();
  int a1,a2,b1,b2,e2,lcm=1,grtr,x,y;
  cin>>a1>>a2>>b1>>b2; x=a2;y=b2;
    if(a2>b2)
  grtr=a2;
  else
  grtr=b2;
  for(int i=2;i<=grtr;i++)
  { while(a2%i==0||b2%i==0)
    { if(a2%i==0)
      { a2=a2/i;
      }
      if(b2%i==0)
      { b2=b2/i;
      }
      lcm=lcm*i;
    }
  }
  e2=(lcm*a1)/x-(lcm*b1)/y;
  cout<<"subtraction is"<<e2<<" / "<<lcm;
  getch();
}