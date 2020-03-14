//Devesh Bhogre 203242 SY-BTECH CSE-B B3
#include<stdio.h>

void accept(int A[20][20],int r,int c) //accept
{
 int i,j;
 printf("Enter elements of matrix:\n");
 for(i=0;i<r;i++)
  for(j=0;j<c;j++)
   scanf("%d",&A[i][j]);
}

int create_compact(int B[20][20],int r,int c,int sp[20][3])    //compact matrix
{
 int i,j,k; 
 k=1;
 for(i=0;i<r;i++)
 {
  for(j=0;j<c;j++)
  {
   if(B[i][j]!=0)
   {
    sp[k][0]=i;
    sp[k][1]=j;
    sp[k][2]=B[i][j];
    k++;
   }
  }
 }
 sp[0][0]=r;
 sp[0][1]=c;
 sp[0][2]=k-1;
 return k;
}

int simple_trans(int sp[20][3],int spt[20][3],int A[20][20],int r,int c)   // transpose of matrix
{
 create_compact(A,r,c,sp);
 int i,j,k=1;

  for(i=0;i<sp[0][1];i++)
  {
   for(j=1;j<=sp[0][2];j++)
   {
     if(sp[j][1]==i)
     {
	spt[k][1]=sp[j][0];
	spt[k][0]=sp[j][1];
	spt[k][2]=sp[j][2];
        k++;
     }
   }
  }
  spt[0][0]=sp[0][1];
  spt[0][1]=sp[0][0];
  spt[0][2]=sp[0][2];  
// printf("k=%d\n",k); 
  return k;
}

int fast_trans(int sp[20][3],int fst[20][3],int A[20][20],int r,int c)
{
 create_compact(A,r,c,sp);
 int i,j;
 int rterm[10],rpos[10],loc;

  fst[0][0]=sp[0][1];
  fst[0][1]=sp[0][0];
  fst[0][2]=sp[0][2]; 

  for(i=0;i<sp[0][1];i++)
    {rterm[i]=0;}

  for(i=1;i<=sp[0][2];i++)
    {rterm[sp[i][1]]++;}

  rpos[0]=1;

  for(i=1;i<sp[0][1];i++)   
    {rpos[i]=rterm[i-1]+rpos[i-1];}

  for(j=1;j<=sp[0][2];j++)
  {
    loc=rpos[sp[j][1]];
    fst[loc][0]=sp[j][1];
    fst[loc][1]=sp[j][0]; 
    fst[loc][2]=sp[j][2];
    rpos[sp[j][1]]++;
  }
  return (loc+1);
}

int matadd(int comp1[20][3],int comp2[20][3],int comp3[20][3])
{
   int i,j,k; 
   i=1,j=1,k=1;
   if(comp1[0][0]==comp2[0][0] && comp1[0][1]==comp2[0][1])
   {
    while(i<=comp1[0][2] && j<=comp2[0][2])
    {
     if(comp1[i][0]==comp2[j][0])     
     {
     if(comp1[i][1]==comp2[j][1])
     {
	comp3[k][0]=comp1[i][0];
	comp3[k][1]=comp1[i][1];
	comp3[k][2]=comp1[i][2]+comp2[j][2];
        i++;j++;k++;
     }
     else if(comp1[i][1]<comp2[j][1])
     {
	comp3[k][0]=comp1[i][0];
	comp3[k][1]=comp1[i][1];
	comp3[k][2]=comp1[i][2];
        i++;k++;
     }
     else
     {
	comp3[k][0]=comp2[j][0];
	comp3[k][1]=comp2[j][1];
	comp3[k][2]=comp2[j][2];
        j++;k++;
     }
    }
    else if(comp1[i][0]<comp2[j][0])
     {
	comp3[k][0]=comp1[i][0];
	comp3[k][1]=comp1[i][1];
	comp3[k][2]=comp1[i][2];
        i++;k++;
     }
     else
     {
	comp3[k][0]=comp2[j][0];
	comp3[k][1]=comp2[j][1];
	comp3[k][2]=comp2[j][2];
        j++;k++;
     }                                                                    
  }
  while(i<=comp1[0][2])
   {
	comp3[k][0]=comp1[i][0];
	comp3[k][1]=comp1[i][1];
	comp3[k][2]=comp1[i][2];
        i++;k++;
   }
   while(j<=comp2[0][2])
   {
	comp3[k][0]=comp2[j][0];
	comp3[k][1]=comp2[j][1];
	comp3[k][2]=comp2[j][2];
        j++;k++;
   }
  	comp3[0][0]=comp2[0][0];
	comp3[0][1]=comp2[0][1];
	comp3[0][2]=k-1;
	return k;
 }
  else
    printf("\n Addition not possible!!\n");
}


void display(int A[20][20],int r,int c)  //display
{
 int i,j;
 printf("\nDisplaying matrix:\n");
 for(i=0;i<r;i++)
 {
  for(j=0;j<c;j++)
  {
   printf("%d ",A[i][j]);
  }
  printf("\n");
 }
}

void comp_display(int A[20][3],int r,int c)  //comp_display
{
 int i,j;
 //printf("\nDisplaying matrix:\n");
 for(i=0;i<r;i++)
 {
  for(j=0;j<c;j++)
  {
   printf("%d ",A[i][j]);
  }
  printf("\n");
 }
}


void main()   
{
 int ch,r,c,k,l,m,A[20][20],B[20][20],r1,c1,sp[20][3],sp1[20][3],sp2[20][3],spt[20][3],fst[20][3];//sp is compact matrix
 printf("Enter the no. of rows and colomn for matrix:\n");
 scanf("%d %d",&r,&c);
 accept(A,r,c);
 while(ch!=6)
 {
  printf("\n\nEnter the choice to perform operation:\n");
  printf("1.Display matrix\n");
  printf("2.Compact matrix\n");
  printf("3.Simple transpose\n");
  printf("4.Fast transpose\n");
  printf("5.Addition of matrices\n");
  printf("6.Exit\n");
  printf("Choice:");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:display(A,r,c);
	  break;     
   case 2:k=create_compact(A,r,c,sp);
  	  printf("\nThe compact matrix is:\n");
  	  printf("i j k\n");
  	  comp_display(sp,k,3);
	  break;
   case 3:l=simple_trans(sp,spt,A,r,c);
  	  printf("\nThe transpose of compact matrix is:\n");
  	  printf("i j k\n");
  	  comp_display(spt,l,3);
	  break;
   case 4:m=fast_trans(sp,fst,A,r,c);
  	  printf("\nThe transpose of compact matrix is:\n");
  	  printf("i j k\n");
  	  comp_display(fst,m,3);
	  break;
   case 5:printf("Enter the no. of rows and colomn for 2nd matrix:\n");
    	  scanf("%d %d",&r1,&c1);
          accept(B,r1,c1);
	  int z;
 	  k=create_compact(A,r,c,sp);
  	  printf("\n1st compact matrix is:\n");
  	  printf("i j k\n");
  	  comp_display(sp,k,3);
	  k=create_compact(B,r1,c1,sp1);
  	  printf("\n2nd compact matrix is:\n");
  	  printf("i j k\n");
  	  comp_display(sp1,k,3);
	  z=matadd(sp,sp1,sp2);
 	  printf("\nThe Addition of 2 matrices is:\n");
  	  printf("i j k\n");
  	  comp_display(sp2,z,3);
	  break;
   case 6:break;
   default:printf("\nPls Enter correct choice!!");
  }
 }
} 
 

