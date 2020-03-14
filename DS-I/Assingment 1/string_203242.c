//Devesh Bhogre CSE-B 203242 B3 SY-BTECH
#include<stdio.h>

int strlength(char *str)  //Length Calculation using *pointer
{
 int cnt=0;
 while(*str!='\0')
 {
  cnt++;
  str++;
 }
 return cnt;
}

void strcopy(char *dest,char *src)  //copy string using *pointer
{
 while(*src!='\0')
 {
  *dest=*src;
  dest++;
  src++;
 }
 *dest='\0';
}

void strconcat(char *dest,char *src)	//Concatinate strings using *pointer
{
 while(*dest!='\0')
 {
  dest++;
 }
 while(*src!='\0')
 {
  *dest=*src;
  dest++;
  src++;
 }
 *dest='\0';
}

void strrev(char str2[30],char str1[30])  //String reverse
{ 
 int i,j,k;
 for(i=0;str1[i]!='\0';i++);
 for(k=0,j=i-1;j>=0;k++,j--)
 {
  str2[k]=str1[j];
 }
 str2[k]='\0';
}

void streq(char str1[30],char str2[30])  //string equality
{
 int i,j,f;
 for(i=0,j=0;str1[i]!='\0';i++,j++)
 {
  if(str1[i]!=str2[j])
  {
    f=1;break;
  }
 }
 if(f==1)
  printf("\nStrings are not equal");
 else
  printf("\nStrings are Equal");
}

void strpalan(char str1[30],char str2[30]) //string palandrome
{
 strrev(str1,str2);
 int i,j,f;
 for(i=0,j=0;str1[i]!='\0';i++,j++)
 {
  if(str1[i]!=str2[j])
  {
    f=1;break;
  }
 }
 if(f==1)
  printf("\nString is not Palandrome");
 else
  printf("\nStrings is Palandrome");
}

void strsub(char str1[30],char str2[30])
{
 int i=0,j,k,cnt=0;
 //or(k=0;str2[k]!='\0';k++);
 while(str1[i]!='\0')
 {
  j=0;	
  while(str2[j]!='\0' && str1[i]!='\0')
  {
   if(str1[i]==str2[j])
   {i++;j++;}
   else
   {j=0;i++;}
  }
  if(str2[j]=='\0')
  {
   printf("\nSubString is found!\n");
   cnt=1;
   break;
  }
 }
 if(cnt==0)
  {
   printf("\nNo such Substring exist\n");
  } 
}
 /*for(k=0;str2[k]!='\0';k++);
 for(i=0;str1[i]!='\0';i++)
 {
  for(j=0;str2[j]!='\0';j++)
  {
   if(str2[j]==str1[i])
     {cnt++;break;}	
  }
 }
 if(cnt!=k)
  printf("\nNo such Substring exist");  
 else
  printf("Sub String found!");*/


int main()   //main
{
 int len,ch,z;
 char str1[10],str2[10],rev[10],emp[10];
 while(ch!=8)
 {	
  printf("\n\nEnter the choice to perform operation from the following:\n");
  printf("1:String Length");
  printf("\n2:String Copy");
  printf("\n3:String Concatinate");
  printf("\n4:String reverse");
  printf("\n5:String Pallindrome");
  printf("\n6:String equality");
  printf("\n7:Substring of String");
  printf("\n8:Exit");
  printf("\nChoice:");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:printf("\nEnter the string:");
 	  scanf("%s",str1);
	  len=strlength(str1);
	  printf("String Length : %d\n",len);
	  break;
   case 2:printf("\nEnter string to be copied:");
	  scanf("%s",str1);
	  strcopy(str2,str1);
	  printf("Copied String : %s\n",str2);
	  break;
   case 3:printf("\nEnter first string:");
 	  scanf("%s",str1);
	  printf("Enter second string:");
 	  scanf("%s",str2);
	  strconcat(str1,str2);
	  printf("Concatinated String : %s\n",str1);
	  break;
   case 4:printf("\nEnter the string:");
 	  scanf("%s",str1);
	  strrev(rev,str1);
	  printf("Reversed String : %s\n",rev);
	  break;
   case 5:printf("\nEnter the string:");
 	  scanf("%s",str1);
	  strpalan(str1,emp);
 	  break;
   case 6:printf("\nEnter first string:");
 	  scanf("%s",str1);
	  printf("Enter second string:");
 	  scanf("%s",str2);
	  streq(str1,str2);
	  break;
   case 7:printf("\nEnter main string:");
 	  scanf("%s",str1);
	  printf("Enter substring to search:");
 	  scanf("%s",str2);
	  strsub(str1,str2);
	  break;
   case 8:break;
   default:printf("\n Enter correct choice!!!!!");
   }
 }
 return 0;
}

