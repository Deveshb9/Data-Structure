//Devesh Bhogre CSE-B 203242 B3 SY-BTECH
#include<stdio.h>

struct student
{
 int roll;
 char div,nam[30];
 float per;
};

void display(struct student S[50],int n)   //Binary search
{
 int i;
 for(i=0;i<n;i++)
 {
   printf("----------------------------------\n");
   //printf("Details of %d student:\n",i+1);
   printf("Roll no.  :%d\n",S[i].roll);
   printf("Division  :%c\n",S[i].div);
   printf("Name      :%s\n",S[i].nam);
   printf("Percentage:%.2f\n",S[i].per);
   printf("----------------------------------\n"); 
 }
}
 
void lsearch(struct student S[50],int n)   //Linear search
{
 int key,i,f=0;
 printf("\nEnter the roll no. to find the student database:");  
 scanf("%d",&key);
 for(i=0;i<n;i++)
 {
  if(key==S[i].roll)
  {
    f=1;
    printf("\nStudent data found:");
    printf("Roll no.  :%d\n",S[i].roll);
    printf("Division  :%c\n",S[i].div);
    printf("Name      :%s\n",S[i].nam);
    printf("Percentage:%.2f\n",S[i].per);
    break;	
  }
 }
 if(f==0)
  printf("\nRecord not found\n");
}

void bsearch(struct student S[50],int n)   //Binary search
{
 int key,low,high,mid;
 low=0;
 high=n-1;
 mid=(low+high)/2;
 printf("\nEnter the roll no. to find the student database:");  
 scanf("%d",&key);
 while(low<=high)
 {
  if(key==S[mid].roll)
  {
    printf("\nStudent data found at %d:\n",mid+1);
    printf("Roll no.  :%d\n",S[mid].roll);
    printf("Division  :%c\n",S[mid].div);
    printf("Name      :%s\n",S[mid].nam);
    printf("Percentage:%.2f\n",S[mid].per);
    break;	
  }	
  else if(key>S[mid].roll)
	low=mid+1;
    else
	high=mid-1; 
  mid=(low+high)/2;
 }
 if(low>high)
 {
   printf("\nNo record found\n");
 }
}

void bsort(struct student S[50],int n)   //Bubble sort
{
 int i,j;
 struct student temp;
 for(i=0;i<n;i++)
 {
  for(j=0;j<n-i-1;j++)
  {
   if(S[j].roll>S[j+1].roll)
   {
    temp=S[j];
    S[j]=S[j+1];
    S[j+1]=temp;  
   }
  }
  printf("Iteration of %dth pass is:\n",i+1);
  display(S,n);
 }
}

void ssort(struct student S[50],int n)   //Selection sort
{
 int i,j,min,pos;
 struct student temp;
 for(i=0;i<n;i++)
 {
  min=S[i].roll;
  pos=i;
  for(j=i+1;j<n;j++)
  {
    if(min>S[j].roll)
    {
	min=S[j].roll;
	pos=j;
    }
  }
  temp=S[i];
  S[i]=S[pos];
  S[pos]=temp;
  //display(S,n);
 }
}

void isort(struct student S[50],int n)   //Selection sort
{
 int i,j,ch=0;
 struct student temp;
 for(i=1;i<n;i++)
 {
  temp=S[i];
  j=i-1;
  while(S[j].roll>temp.roll && j>=0)
  {
   S[j+1]=S[j];
   j--;
  }
  S[j+1]=temp;
 }
}


void main()
{
 int n,i,ch; 
 struct student S[50];
 printf("Enter no. of students data to be entered:");
 scanf("%d",&n); 
 printf("Enter the details of students:\n");
 for(i=0;i<n;i++)
 {
   printf("----------------------------------\n");
   printf("Details of %d student:\n",i+1);
   printf("Roll no.  :");
   scanf("%d",&S[i].roll);
   printf("Division  :");
   scanf(" %c",&S[i].div);
   printf("Name      :");
   scanf("%s",S[i].nam);
   printf("Percentage:");
   scanf("%f",&S[i].per);
   printf("----------------------------------\n");
 }
 while(ch!=7)
 {
 printf("\n\nEnter choice to perform operation:\n");
 printf("1.Display all records\n");
 printf("2.Linear Search\n");
 printf("3.Binary Search\n");
 printf("4.Bubble Sort\n");
 printf("5.Insertion Sort\n");
 printf("6.Selection Sort\n");
 printf("7.Exit\n");
 printf("Choice:");
 scanf("%d",&ch);
 switch(ch)
 {
	case 1:display(S,n);
	       break;
	case 2:lsearch(S,n); //Linear search
	       break;
	case 3:bsort(S,n);
	       bsearch(S,n); //Binary search
	       break;
	case 4:bsort(S,n); //Bubble sort
	       printf("\nDetails of student in accending order:\n");
	       display(S,n);
	       break;
 	case 5:isort(S,n);
	       printf("\nDetails of student in accending order:\n");
	       display(S,n);
	       break;	
 	case 6:ssort(S,n); //selection sort
	       printf("\nDetails of student in accending order:\n");
	       display(S,n);
	       break;
 	case 7:break;
	default:printf("\nEnter correct choice!!\n");  
 }
 }            
}




 
