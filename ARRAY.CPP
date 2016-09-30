#include<iostream.h>
#include<conio.h>
#define MAX 5
void insert(int* ,int ,int );
void display(int*);
void del(int* ,int );
void reverse(int*);
void search(int*);
void main()
{
  clrscr();
  int arr[MAX];
  insert(arr,1,1);
  insert(arr,2,2);
  insert(arr,3,3);
  insert(arr,4,4);
  insert(arr,5,5);
  display(arr);
  reverse(arr);
  display(arr);
  search(arr);
  del(arr,1);
  del(arr,2);
  display(arr);
  getch();
}
void insert(int*arr,int pos,int num)
{
  for(int i=MAX-1;i>=pos;i--)
  arr[i+1]=arr[i];
  arr[i]=num;
}
void display(int*arr)
{
  cout<<"Displaying elements:\t";
  for(int i=0;i<=MAX-1;i++)
  cout<<arr[i]<<" ";
  cout<<"\n";
}
void del(int*arr,int pos)
{          cout<<"Deleting element at "<<pos<<" position\n";
  for(int i=pos;i<MAX;i++)
  arr[i-1]=arr[i];
  arr[MAX-1]=0;
}
void reverse(int*arr)
{ for(int i=0;i<MAX/2;i++)
   { int temp=arr[i];
     arr[i]=arr[MAX-1-i];
     arr[MAX-1-i]=temp;
   }
}
void search(int*arr)
{ int num, c=0;        cout<<"Enter element to be searched:\t";cin>>num;
  for(int i=0;i<MAX;i++)
  { if(arr[i]==num)
   { cout<<"Element "<<num<<" found at "<<i+1<<"th position\n";c++;
   }}
    if(c==0)
    cout<<"Element "<<num<<" not found\n";


}

