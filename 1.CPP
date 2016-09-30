#include<iostream.h>
#include<conio.h>
#define MAX 5
int* insert(int* ,int ,int )
int main()
{ clrscr();
  int arr[4];
  arr[4]={1,2,3,4,5};
  insert(arr,6,2);
  cout<<"done";
  getch();
  return 0;
}
int* insert(int* arr,int num,int pos)
{ for(int i=MAX-1;i>pos;i++)
  arr[i+1]=arr[i];
  arr[pos]=num;
  return arr;
}

