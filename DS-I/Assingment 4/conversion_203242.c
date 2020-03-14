//Devesh M Bhogre 203242 SY-BTECH CSE-B B3 
#include<stdio.h>
#include<string.h>

char stack[20][20],stack1[20];
int top=-1;

void push(char str[20])
{
  top++;
  strcpy(stack[top],str);
}

char* pop()
{
 char *temp;
 strcpy(temp,stack[top]);
 top--;
 return temp;
}

void push1(char str)
{
  top++;
  stack1[top]=str;
}

char pop1()
{
 char temp;
 temp=stack1[top];
 top--;
 return temp;
}

void postfix_to_infix(char exp[20])
{
 char op1[20],op2[20],str[20];
  int i,l;
  top=-1;
  for(i=0;exp[i]!='\0';i++)
  {
   if(exp[i]=='+'||exp[i]=='-'||exp[i]=='/'||exp[i]=='*'||exp[i]=='^')
   {
    strcpy(str," ");
    strcpy(op1,pop());
    strcpy(op2,pop());
    str[0]='(';
    strcat(str,op2);
    l=strlen(str);
    str[l]=exp[i];
    str[l+1]='\0';
    strcat(str,op1);
    l=strlen(str);
    str[l]=')';
    str[l+1]='\0';
    push(str);
   }
   else
   {
    char str1[20];
    str1[0]='\0';
    str1[0]=exp[i];
    str1[1]='\0';
    push(str1);
   }
  }
  strcpy(str,pop());
  printf("\nThe infix expression:%s\n\n",str); 
}

void postfix_to_prefix(char exp[20])
{
  char op1[20],op2[20],str[20];
  int i,l;
  top=-1;
  for(i=0;exp[i]!='\0';i++)
  {
   if(exp[i]=='+'||exp[i]=='-'||exp[i]=='/'||exp[i]=='*'||exp[i]=='^')
   {
    strcpy(str," ");
    strcpy(op1,pop());
    strcpy(op2,pop());
    str[0]=exp[i];
    str[1]='\0';
    strcat(str,op2);
    strcat(str,op1);
    push(str);
   }
   else
   {
    char str1[20];
    str1[0]='\0';
    str1[0]=exp[i];
    str1[1]='\0';
    push(str1);
   }
  }
  strcpy(str,pop());
  printf("\nThe prefix expression:%s\n\n",str);    
}


int ISP(char ch)
{
 if(ch=='+'||ch=='-')
   return (1);
 if(ch=='*'||ch=='/')
   return (2);
 if(ch=='^')
   return (3);
 if(ch=='(')
   return (0);
 else
   return (-1);
}

int ICP(char ch)
{
 if(ch=='+'||ch=='-')
   return (1);
 if(ch=='*'||ch=='/')
   return (2);
 if(ch=='^')
   return (4);
 if(ch=='(')
   return (0);
 else
   return (-1);
}

void infix_to_postfix(char exp[20])
{
  top=-1;
  char postfix[20];
  int i,k=0,ch;
  for(i=0;exp[i]!='\0';i++)
  {
   if(exp[i]=='(')
   {
     push1(exp[i]);
   }
   else if(exp[i]==')')
   {
    while((ch=pop1())!='(' && top>=0)
    {
     postfix[k]=ch;
     k++;
    }
   }
   else if(exp[i]=='+'||exp[i]=='-'||exp[i]=='/'||exp[i]=='*'||exp[i]=='^')
   { 
    while(ISP(stack1[top])>=ICP(exp[i]) && top>=0)
    {
     postfix[k]=pop1();
     k++;
    }
     push1(exp[i]);
   }
   else
   {
    postfix[k]=exp[i];
    k++;
   }
  }//for ends 
  while(top>=0)
  {
   postfix[k]=pop1();
   k++;
  }
  postfix[k]='\0';
  printf("\nThe postfix expression:%s\n\n",postfix);
}
 


void infix_to_prefix(char exp[20])
{
  top=-1;
  char prefix[20],rexp[20],prefix1[20];
  int i,j,k=0,ch,len,l;
  len=strlen(exp);
  for(i=0;exp[i]!='\0';i++)
  {
   if(exp[i]=='(')
   {
     exp[i]=')';
   }
   else if(exp[i]==')')
   {
    exp[i]='(';
   }
  }
  for(i=len-1,j=0;i>=0;i--,j++)
  {
    rexp[j]=exp[i];
  }
  rexp[j]='\0';
  for(i=0;rexp[i]!='\0';i++)
  {
   if(rexp[i]=='(')
   {
     push1(rexp[i]);
   }
   else if(rexp[i]==')')
   {
    while((ch=pop1())!='(' && top>=0)
    {
     prefix[k]=ch;
     k++;
    }
   }
   else if(rexp[i]=='+'||rexp[i]=='-'||rexp[i]=='/'||rexp[i]=='*'||rexp[i]=='^')
   { 
    while(ICP(stack1[top])>ISP(rexp[i]) && top>=0)
    {
     prefix[k]=pop1();
     k++;
    }
     push1(rexp[i]);
   }
   else
   {
    prefix[k]=rexp[i];
    k++;
   }
  }//for ends 
  while(top>=0)
  {
   prefix[k]=pop1();
   k++;
  }
  prefix[k]='\0';
  l=strlen(prefix);
  for(i=l-1,j=0;i>=0;i--,j++)
  {
    prefix1[j]=prefix[i];
  }
  prefix1[j]='\0';
  printf("\nThe prefix expression:%s\n\n",prefix1);
}
 
void prefix_to_infix(char exp[20])
{
 char op1[20],op2[20],str[20],str1[20];
  int i,j,l,len;
  top=-1;
  len=strlen(exp);
  for(i=len-1;i>=0;i--)
  {
   if(exp[i]=='+'||exp[i]=='-'||exp[i]=='/'||exp[i]=='*'||exp[i]=='^')
   {
    strcpy(str," ");
    strcpy(op1,pop());
    strcpy(op2,pop());
    str[0]='(';
    strcat(str,op2);
    l=strlen(str);
    str[l]=exp[i];
    str[l+1]='\0';
    strcat(str,op1);
    l=strlen(str);
    str[l]=')';
    str[l+1]='\0';
    push(str);
   }
   else
   {
    char str1[20];
    str1[0]='\0';
    str1[0]=exp[i];
    str1[1]='\0';
    push(str1);
   }
  }
  strcpy(str,pop());
  len=strlen(str);
  for(i=len-1,j=0;i>=0;i--,j++)
  {
   str1[j]=str[i];
  }
  str1[j]='\0';
   for(i=0;i<len;i++)
  {
   if(str1[i]=='(')
   {
     str1[i]=')';
   }
   else if(str1[i]==')')
   {
    str1[i]='(';
   }
  }
  printf("\nThe infix expression:%s\n\n",str1); 
}

void prefix_to_postfix(char exp[20])
{
  char op1[20],op2[20],str[20],str1[20];
  int i,l,len,j;
  top=-1;
  len=strlen(exp);
  for(i=len-1;i>=0;i--)
  {
   if(exp[i]=='+'||exp[i]=='-'||exp[i]=='/'||exp[i]=='*'||exp[i]=='^')
   {
    strcpy(str," ");
    strcpy(op1,pop());
    strcpy(op2,pop());
    str[0]=exp[i];
    str[1]='\0';
    strcat(str,op2);
    strcat(str,op1);
    push(str);
   }
   else
   {
    char str1[20];
    str1[0]='\0';
    str1[0]=exp[i];
    str1[1]='\0';
    push(str1);
   }
  }
  strcpy(str,pop());
  len=strlen(str);
  for(i=len-1,j=0;i>=0;i--,j++)
  {
   str1[j]=str[i];
  }
  str1[j]='\0';
   for(i=0;i<len;i++)
  {
   if(str1[i]=='(')
   {
     str1[i]=')';
   }
   else if(str1[i]==')')
   {
    str1[i]='(';
   }
  }
  printf("\nThe postfix expression:%s\n\n",str1); 
}


void main()
{
  char exp[20];
  int ch;
  while(ch!=7)
  {
  strcpy(exp,"");
  printf("Enter the choice to perform conversion:\n");
  printf("1.Postfix to Infix\n");
  printf("2.Postfix to Prefix\n");
  printf("3.Infix to Postfix\n");
  printf("4.Infix to Prefix\n");
  printf("5.Prefix to Postfix\n");
  printf("6.Prefix to Infix\n");
  printf("7.Exit\n");
  printf("Choice:");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:printf("\nEnter the Postfix expression:\n");
 	  scanf("%s",exp);
 	  postfix_to_infix(exp);
          break;
   case 2:printf("\nEnter the Postfix expression:\n");
 	  scanf("%s",exp);
 	  postfix_to_prefix(exp);
          break;
   case 3:printf("\nEnter the Infix expression:\n");
 	  scanf("%s",exp);
 	  infix_to_postfix(exp);
          break;
   case 4:printf("\nEnter the Infix expression:\n");
 	  scanf("%s",exp);
 	  infix_to_prefix(exp);
          break;  
   case 5:printf("\nEnter the Prefix expression:\n");
 	  scanf("%s",exp);
 	  prefix_to_postfix(exp);
          break;
   case 6:printf("\nEnter the Prefix expression:\n");
 	  scanf("%s",exp);
 	  prefix_to_infix(exp);
          break; 
   case 7:break;
   default:printf("\nPls Enter correct choice!!!\n");
 }
 }
}







