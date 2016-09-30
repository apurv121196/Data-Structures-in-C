#include<iostream.h>
#include<conio.h>
void main()
{ clrscr();
  int days,months=0;
  cin>>days;
  int mon[]={31,28,31,30,31,30,31,31,30,31,30,31};
  for(int i=0;mon[i]<days;i++)
  { days=days-mon[i];
    months++;
    if(i>=11)
    { i=1;}
  }

  cout<<months<<" months and "<<days<<" days";
  getch();
}