#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<malloc.h>
#define max 10
void mergesort(int *,int );
void display(int *);
void create(int *);
void merge(int *,int ,int *,int ,int *);
void main()
{ clrscr();
  int arr[max];
  //int one[5]={ 5,4,3,2,1 };
  //int two[5]={ 9,8,7,6,0 };
  //merge(one,two,arr);
  //display(arr);
  create(arr);
  display(arr);
  mergesort(arr,10);
  display(arr);
  getch();
}
void create(int *arr)
{ cout<<"Enter elements:\n";
  for(int i=0;i<max;i++)
  cin>>arr[i];
}
void display(int *arr)
{ cout<<"Displaying elements:\n";
  for(int i=0;i<max;i++)
  { cout<<arr[i]<<"  ";
  }
  cout<<endl;
}
void mergesort(int *arr,int size)
{ int mid=size/2;
  if(mid==0)
  { return; }
  else
  {
  int *left=(int *)malloc(sizeof(int)*mid);
  int *right=(int *)malloc(sizeof(int)*(size-mid));
  for(int i=0;i<mid;i++)
  { left[i]=arr[i];
  }
  for(int j=0;i<size;i++,j++)
  { right[j]=arr[i];
  }
  mergesort(left,mid);
  mergesort(right,size-mid);
  merge(left,mid,right,size-mid,arr);
  }
}
void merge(int *one,int size1,int *two,int size2,int *three)
{ int i,j,k;
  i=j=k=0;
  while(i<size1 && j<size2)
  { if(one[i]<two[j])
    { three[k++]=one[i++];
    }
    if(one[i]>two[j])
    { three[k++]=two[j++];
    }
    if(one[i]==two[j])
    { three[k++]=one[i++];
      three[k++]=two[j++];
    }
  }
  while(i<size1)
  { three[k++]=one[i++];
  }
  while(j<size2)
  { three[k++]=two[j++];
  }
}