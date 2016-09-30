#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#define max 3
void create(int [3][3]);
void display(int [3][3]);
void matadd(int [3][3],int [3][3],int [3][3]);
void matmul(int [3][3],int [3][3],int [3][3]);
void transpose(int [3][3],int [3][3]);
void main()
{ clrscr();
  int mat1[3][3],mat2[3][3],mat3[3][3];
  create(mat1);  //create(mat2);
  display(mat1); cout<<endl;transpose(mat1,mat2);display(mat2); //display(mat2);
  //matmul(mat1,mat2,mat3);  display(mat3);
  getch();
}
void create(int mat1[3][3])
{ cout<<"Enter values:\n";
  for(int i=0;i<max;i++)
  { for(int j=0;j<max;j++)
    { cin>>mat1[i][j];
    }
  }
}
void display(int mat[3][3])
{ for(int i=0;i<max;i++)
  { for(int j=0;j<max;j++)
    { cout<<mat[i][j]<<"  ";
    }
    cout<<endl;
  }
}
void matadd(int mat1[3][3],int mat2[3][3],int mat3[3][3])
{ for(int i=0;i<3;i++)
  { for(int j=0;j<3;j++)
    { mat3[i][j]=mat1[i][j]+mat2[i][j];
    }
  }
}
void matmul(int mat1[3][3],int mat2[3][3],int mat3[3][3])
{ for(int i=0;i<3;i++)
  { for(int k=0;k<3;k++)
    { int mul=0;
      for(int j=0;j<3;j++)
      { mul+=mat1[i][j]*mat2[j][k];
      }
      mat3[i][k]=mul;
    }
  }
}
void transpose(int mat1[3][3],int mat2[3][3])
{ for(int i=0;i<3;i++)
  { for(int j=0;j<3;j++)
    mat2[i][j]=mat1[j][i];
  }
}