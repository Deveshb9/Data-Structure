//Devesh Bhogre 203242 CSE-B SY-BTECH B1
#include<iostream>
#include<math.h>
using namespace std;

class term
{
 int exp;
 int cof;
 term *next;
 friend class poly;
};

class poly
{
 term *h;
 public:
 	poly();
	void create_poly();
	void display_poly();
	void add_poly(poly,poly);
	void eva_poly();
};

poly::poly()
{
 h=new term();
 h->exp=-1;
 h->next=h;
}

void poly::create_poly()
{
 term *last,*ptr;
 int n,i;
 last=h;
 cout<<"\nEnter size of expression:";
 cin>>n;
 for(i=0;i<n;i++)
 {
  ptr=new term();
  ptr->next=h;
  cout<<"\nEnter cofficient & exponent of "<<i+1<<" place:\n";
  cin>>ptr->cof>>ptr->exp;
  last->next=ptr;
  last=ptr;
 }
}

void poly::display_poly()
{
 term *temp;
 temp=h->next;
 while(temp->exp!=-1)
 {
  cout<<"("<<temp->cof<<"x^"<<temp->exp<<")"<<"+";
  temp=temp->next;
 }
 cout<<"0"<<endl;
}

void poly::add_poly(poly p1,poly p2)
{
 term *t1,*t2,*t3,*temp;
 t1=p1.h->next;
 t2=p2.h->next;
 t3=h;
 while(t1->exp!=-1||t2->exp!=-1)
 {
  temp=new term();
  if(t1->exp==t2->exp)
  {
   temp->cof=t1->cof+t2->cof;
   temp->exp=t1->exp;
   t3->next=temp;
   t3=t3->next;
   t1=t1->next;
   t2=t2->next;	
  }
  else if(t1->exp>t2->exp)
  {
   t3->next=t1;
   t3=t3->next;
   t1=t1->next;
  }
  else
  {
   t3->next=t2;
   t3=t3->next;
   t2=t2->next;
  }
 }
 t3->next=h;
 cout<<"\n1st Expresion is:";
 p1.display_poly();
 cout<<"\n2nd Expression is:";
 p2.display_poly();
 cout<<"\nAddition of Expression is:";
 }

void poly::eva_poly()
{
 term *temp;
 temp=h->next;
 int n,sum=0;
 cout<<"\nEnter value of x to evalute expression:";
 cin>>n;
 while(temp->exp!=-1)
 {
  sum=sum+temp->cof*(pow(n,temp->exp));
  temp=temp->next;
 }
 cout<<"\nEvalutation of polynomial is:"<<sum;
}




int main()
{
 poly p1,p2,p3;
 int ch;
 while(ch!=5)
 {
 cout<<"\n\nEnter choice to perform operation:\n";
 cout<<"1.Create Polynomial\n";
 cout<<"2.Display Polynomial\n";
 cout<<"3.Addition of Polynomials\n";
 cout<<"4.Evaluate the Polynomial\n";
 cout<<"5.Exit\n";
 cout<<"choice:";
 cin>>ch;
 switch(ch)
 {
  case 1:p1.create_poly();
	 break;
  case 2:cout<<"\nThe Expression is:";
	 p1.display_poly();
	 break;
  case 3:cout<<"\nEnter 2nd Polynoimal:";
 	 p2.create_poly();
 	 p3.add_poly(p1,p2);
 	 p3.display_poly();
	 break;
  case 4:p1.eva_poly();
 	 break;
  case 5:break;
  default:cout<<"\nPls. Enter correct choice";
 }
 }
 return 0;
}
	
