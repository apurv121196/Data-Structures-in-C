#include<iostream.h>
#include<conio.h>
#include<malloc.h>
int *arr;
void create(int );
void display(int );
void apurv_sort(int );
void main()
{ clrscr();
  create(5);
  display(5);
  apurv_sort(5);
  display(5);
  getch();
}
void create(int size)
{ arr=(int *)malloc(sizeof(int)*size);
  for(int i=0;i<size;i++)
  cin>>arr[i];
}
void display(int size)
{
  for(int i=0;i<size;i++)
  cout<<arr[i]<<"  ";
  cout<<endl;
}
void apurv_sort(int size)
{ int c=0;int temp;
  for(int i=0;i<size-1;c=0)
  { for(int j=i+1;j<size;j++)
    { if(arr[j]<arr[i])
      c++;
    }
    if(c!=0)
    { temp=arr[c+i];
      arr[c+i]=arr[i];
      arr[i]=temp;

    }
    else
    {i++;}
  }
}
