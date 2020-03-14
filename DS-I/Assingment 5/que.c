//Devesh M Bhogre CSE-B 203242  B3 SY-BTECH

#include<stdio.h>
#include<string.h>

int size=10,front=-1,rear=-1;

struct pp     //pizza parlour
{
 int o_id;
 char o_date[20];
 int price;
 char c_name[20];
 char mob[10];
 char piz[20];
};

struct pp P[10];

int isempty()
{
 if(rear==front)
   return 1;
 else
   return 0;
}

int isfull()
{
 if(rear==size-1)
   return 1;
 else
   return 0;
}

void accept(int i)
{
 int ch;
 printf("\nEnter Details of the Customer:");
 printf("\nEnter Name:");
 scanf("%s",P[i].c_name);
 printf("Enter Mobile:");
 scanf("%s",P[i].mob);
 do
 {
 printf("\nEnter the pizza choice:");
 printf("\n1.Corn    Pizza-100 Rs");
 printf("\n2.Cheese  Pizza-120 Rs");
 printf("\n3.Chicken Pizza-140 Rs");
 printf("\n4.Paneer  Pizza-130 Rs");
 printf("\nChoice:");
 scanf("%d",&ch);
  switch(ch)
  {
  case 1:P[i].price=100;
         strcpy(P[i].piz,"Corn Pizza");
         break;
  case 2:P[i].price=120;
         strcpy(P[i].piz,"Cheese Pizza");
         break;
  case 3:P[i].price=140;
         strcpy(P[i].piz,"Chicken Pizza");
         break;
  case 4:P[i].price=130;
         strcpy(P[i].piz,"Paneer Pizza");
         break;
  default:printf("\nPlz Enter correct choice!!");
  }
 }while(ch>4);
 printf("Enter order ID:");
 scanf("%d",&P[i].o_id); 
 printf("Enter Date:");
 scanf("%s",P[i].o_date);
}

void display(int i)
{
 printf("\nOrder ID:%d",P[i].o_id);
 printf("\nDate    :%s",P[i].o_date);
 printf("\nName    :%s",P[i].c_name);
 printf("\nMobile  :%s",P[i].mob);
 printf("\nPizza   :%s",P[i].piz);
 printf("\nPrice   :%d Rs",P[i].price);
}

void add_order()
{
 if(isfull()==0)
 {
  rear++;
  accept(rear);
 }
 else
  printf("\n Sorry Order Full");
}

void del_order()
{
 if(isempty()==0)
 {
  front++;
  printf("\nThe following order of the Customer was delivered:");
  display(front);
 }
 else
  printf("\nNo pending orders");
}

void pending()
{
 printf("\nThe following orders are still pending:");
 for(int i=front+1;i<=rear;i++)
 {
  display(i);
 }
}


void main()
{
 int ch;
 while(ch!=4)
 {
 printf("\n\n\n\nEnter the pizza choice:");
 printf("\n1.New Order");
 printf("\n2.Pending Order");
 printf("\n3.Deliver order");
 printf("\n4.Exit");
 printf("\nChoice:");
 scanf("%d",&ch);
  switch(ch)
  {
  case 1:add_order();
         break;
  case 2:pending();
         break;
  case 3:del_order();
         break;
  case 4:break;
  default:printf("\nPlz Enter correct choice!!");
  }
 }
}



