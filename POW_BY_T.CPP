#include<iostream.h>
#include<conio.h>
long double pow(long double ,int ,int);
void main()
{ clrscr();
  cout<<pow(3,2,3);
  getch();
}
long double pow(long double num,int powr,int temp)
{ if(powr==1)
  return num;
  return pow(num*temp,powr-1,temp);
}