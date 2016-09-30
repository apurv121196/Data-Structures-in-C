#include<iostream.h>
#include<conio.h>
#include<math.h>
void main()
{ clrscr(); int a,b,c;
  cin>>a>>b>>c;
  int r1=(-b+sqrt(b*b-4*a*c))/2*a;
  int r2=c/(a*r1);
  cout<<r1<<" "<<r2;
  getch();
}


