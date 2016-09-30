#include<iostream.h>
#include<conio.h>
#define max 5
void bubsort(int *);
void selsort(int *);
void display(int *);
void main()
{ clrscr();
  int arr[max]={3,2,5,1,4};
  bubsort(arr);
  display(arr);
  getch();
}
void display(int *arr)
{ for(int i=0;i<max;i++)
   cout<<arr[i]<<"  ";
}
void bubsort(int *arr)
{ int temp;
  for(int i=0;i<max-1;i++)
  { for(int j=1;j<max-i;j++)
    { if(arr[j-1]>arr[j])
      { temp=arr[j-1];
	arr[j-1]=arr[j];
	arr[j]=temp;
      }
    }
  }
}
void selsort(int *arr)
{ int temp;
  for(int i=0;i<max-1;i++)
  { for(int j=i+1;j<max;j++)
    { if(arr[i]>arr[j])
      { temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
      }
    }
  }
}