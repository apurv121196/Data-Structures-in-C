#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<alloc.h>
#define max1 5
#define max2 6
int *arr;
int* create(int );
void sort(int *,int );
void display(int *,int );
int* merge(int *,int *);
int* Merge(int *,int *);
void main()
{ clrscr();
  int *a,*b,*c;
  a=create(max1);
  b=create(max2);
  sort(a,5);
  sort(b,6);
  display(a,5);
  display(b,6);
  c=Merge(a,b);
  display(c,11);
  getch();
}
int* create(int size)
{ int *arr;
  arr=(int *)malloc(sizeof(int)*size);
  cout<<"Enter elements\n";
  for(int i=0;i<size;i++)
  cin>>arr[i];
  return arr;
}
void sort(int *arr,int size)
{ int temp;
  for(int i=0;i<size-1;i++)
  { for(int j=i+1;j<size;j++)
    { if(arr[i]>arr[j])
      { temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
      }
    }
  }
}
void display(int *arr,int size)
{ for(int i=0;i<size;i++)
  { cout<<arr[i]<<" ";
  }
  cout<<endl;
}
int* merge(int *a,int *b)
{ int size=max1+max2;   int i,j,k;
  i=j=k=0;
  int *arr=(int *)malloc(sizeof(int)*size);
  while(i<max1 && j<max2)
  { if(a[i]<b[j])
    { arr[k]=a[i];
      i++;k++;
    }
    else
    { if(a[i]>b[j])
      { arr[k]=b[j];
	j++;  k++;
      }
      else
      { if(a[i]==b[j])
	{ arr[k]=a[i];arr[++k]=a[i];
	  i++;
	  j++;    k++;
	}
      }
    }

  }

  if(i==max1)
  { while(k<size)
    { arr[k]=b[j];
      j++; k++;
    }
  }
  else
  { if(j==max2)
    { while(k<size)
      { arr[k]=a[i];
	i++; k++;
      }
    }
  }
  return arr;
}
int* Merge(int *a,int *b)
{ int size=max1+max2;  int i,j,k;
  int *arr=(int *)malloc(sizeof(int)*size);
  for(i=0,j=0,k=0;k<size;k++)
  { if(a[i]<b[j])
    { arr[k]=a[i];
      i++;
      if(i>=max1)
      { for(k++;k<size;k++,j++)
	{ arr[k]=b[j]; }
      }
    }
    else
    { if(a[i]>b[j])
      { arr[k]=b[j];
	j++;
	if(j>=max2)
	{ for(k++;k<size;k++,i++)
	  { arr[k]=a[i];}
	}
      }
      else
      { arr[k]=a[i]; arr[++k]=a[i];
	i++; j++;
      }
    }
  }
  return arr;
}