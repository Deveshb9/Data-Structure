//Devesh M Bhogre 
//SY-BTECH CSE-B 
//B1 203242

#include<iostream>
using namespace std;
class node
{
 char data[20];
 node *left;
 node *right;
 friend class tree;
 friend class stack;
};

class tree
{
  node *root;
 public:
 	tree();
	void create_btree_nr();               //Creating Non Recurcive Binary tree
	void create_btree_r();                //Creating Recurcive Binary tree
	void create_tr_r(node *);
	//---------------------------------------------------------
	//recurcive display
	void display_preo_btree(node *); //pre display
	void display_poso_btree(node *); //post display
	void display_ino_btree(node *);  //in display
	void predisp();
      void posdisp();
      void indisp();
      //----------------------------------------------------------
      //non-recrcive display
      void disp_ino_nr();   //in order display
      void disp_preo_nr();  //pre order display
      void disp_poso_nr();  //post order display
      void erase_nr();
      void erase_r(node *);
      void erase();
};

//==============================================================
//stack

class stack
{
 public:
 int top;
 node *DAT[20];
 stack();
 void push(node *);
 node* pop();
 int isempty();
};

stack::stack()
{
 top=-1;
}

void stack::push(node *temp)
{
 if(top!=19)
 {
  top++;
  DAT[top]=temp;
 }
}

node* stack::pop()
{
 node *temp;
 temp=DAT[top];
 top--;
 return temp;
}

int stack::isempty()
{
 if(top==-1)
 {
  return 0;
 }
 else
  return 1;
}

tree::tree()
{
 root=NULL;
}

//=================================================================================

void tree::create_btree_nr()  //Non Recurcive Binary tree
{
 node *temp,*curr;
 int flag=0;
 char ch,choice;
 do
 {
  if(root==NULL)
  {
   root=new node();
   cout<<"\nEnter the data: ";
   cin>>root->data;
   root->left=root->right=NULL;
  }
  else
  {
    temp=root;
    curr=new node();
    cout<<"\nEnter the data: ";
    cin>>curr->data;
    curr->left=curr->right=NULL;

    while(flag==0)
    {
     cout<<"\nWhere you want to attach current on "<<temp->data<<" (l/r)?: ";
     cin>>ch;
     if(ch=='l')
     {
      if(temp->left==NULL)
      {
       temp->left=curr;flag=1;
      }
      else
       temp=temp->left;
     }
     else if(ch=='r')
     {
      if(temp->right==NULL)
      {
       temp->right=curr;flag=1;
      }
      else
       temp=temp->right;
     }
   }
  flag=0;
 }
  cout<<"\nDo you want to add more elements (y/n): ";
  cin>>choice;
 }while(choice=='y');
}

void tree::create_btree_r()    //Recurcive Binary tree
{
 if(root==NULL)
 {
  root=new node();
  cout<<"\nEnter the data: ";
  cin>>root->data;
  root->left=root->right=NULL;
  create_tr_r(root);
 }
 else
  create_tr_r(root);
}

void tree::create_tr_r(node *root) //part of recurcive
{
 char ch;
 node *curr;
 cout<<"\nDo you want to attach a node on left side of "<<root->data<<" (y/n): ";
 cin>>ch;
 if(ch=='y')
 {
    curr=new node();
    cout<<"\nEnter the data: ";
    cin>>curr->data;
    curr->left=curr->right=NULL;
    if(root->left==NULL)
    {
     root->left=curr;
    }
    create_tr_r(root->left);
 }
 cout<<"\nDo you want to attach a node on right side of "<<root->data<<" (y/n): ";
 cin>>ch;
 if(ch=='y')
 {
    curr=new node();
    cout<<"\nEnter the data: ";
    cin>>curr->data;
    curr->left=curr->right=NULL;
    if(root->right==NULL)
    {
     root->right=curr;
    }
    create_tr_r(root->right);
 }
}

//===============================================================================
//recurcive display

void tree::display_preo_btree(node *root)      //preorder
{
 if(root!=NULL)
 {
  cout<<" "<<root->data<<" ";
  display_preo_btree(root->left);
  display_preo_btree(root->right);
 }
}

void tree::predisp()
{
 display_preo_btree(root);
 cout<<endl;
}

void tree::display_poso_btree(node *root)  //post order
{
 if(root!=NULL)
 {
  display_poso_btree(root->left);
  display_poso_btree(root->right);
  cout<<" "<<root->data<<" ";
 }
}

void tree::posdisp()
{
 display_poso_btree(root);
 cout<<endl;
}

void tree::display_ino_btree(node *root) //in order
{
 if(root!=NULL)
 {
  display_ino_btree(root->left);
  cout<<" "<<root->data<<" ";
  display_ino_btree(root->right);
 }
}

void tree::indisp()
{
 display_ino_btree(root);
 cout<<endl;
}


void tree::erase_r(node *root)      //preorder
{
 node *temp;
 if(root!=NULL)
 {
  temp=root;
  delete (temp);
  erase_r(root->left);
  erase_r(root->right);
 }
}

void tree::erase()
{
 erase_r(root);
 cout<<endl;
}
//===============================================================================
//non-recurcive display

void tree::disp_ino_nr()   //in order
{
 node *temp;
 temp=new node();
 stack st;
 temp=root;
 while(1)
 {

  while(temp!=NULL)
  {
   st.push(temp);
   temp=temp->left;
  }
  if(st.isempty()==0)
    break;
  temp=st.pop();
  cout<<" "<<temp->data<<" ";
  temp=temp->right;
 }
}


void tree::disp_preo_nr()  //pre order
{
 node *temp;
 stack st;
 temp=new node();
 temp=root;
 while(1)
 {
  while(temp!=NULL)
  {
   cout<<" "<<temp->data<<" ";
   st.push(temp);
   temp=temp->left;
  }
  if(st.isempty()==0)
    break;
  temp=st.pop();
  temp=temp->right;
 }
}

void tree::disp_poso_nr()    //post order
{
	node *temp;
	stack st;
	temp=new node();
	temp=root;
	while(1)
	{
		while(temp!=NULL)
		{
			st.push(temp);
			temp=temp->left;
		}
		if(st.DAT[st.top]->right==NULL)
		{
			temp=st.pop();
			cout<<" "<<temp->data<<" ";
		}

		while(st.isempty()!=0 && st.DAT[st.top]->right==temp)
		{
			temp=st.pop();
			cout<<" "<<temp->data<<" ";
		}
		if(st.isempty()==0)
			break;
		temp=st.DAT[st.top]->right;
	}
}

void tree::erase_nr()
{
  	node *temp,*temp1;
	stack st;
	temp=new node();
	temp=root;
	while(1)
	{
		while(temp!=NULL)
		{
			st.push(temp);
			temp=temp->left;
		}
		if(st.DAT[st.top]->right==NULL)
		{
			temp=st.pop();
			temp1=temp;
			delete (temp1);
		}

		while(st.isempty()!=0 && st.DAT[st.top]->right==temp)
		{
			temp=st.pop();
			temp1=temp;
			delete (temp1);
		}
		if(st.isempty()==0)
			break;
		temp=st.DAT[st.top]->right;
	}
}

//==========================================================================
//main
int main()
{
 tree T;
 int ch;
 while(ch!=7)
 {
  cout<<"\n============================================================\n";
  cout<<"\nEnter choice to perform operations on Binary Tree: ";
  cout<<"\n1.Create Binary Tree using Non-Recursive Method";
  cout<<"\n2.Create Binary Tree using Recursive Method";
  cout<<"\n3.Displaying Binary tree Using Recurcive Methods in all orders (pre/post/in)";
  cout<<"\n4.Displaying Binary tree Using Non-Recurcive Methods in all orders (pre/post/in)";
  cout<<"\n5.Erase tree (non-recursive)";
  cout<<"\n6.Erase tree (Recursive)";
  cout<<"\n7.Exit";
  cout<<"\nChoice:";
  cin>>ch;
  switch(ch)
  {
   case 1:T.create_btree_nr();
	  break;
   case 2:T.create_btree_r();
	  break;
   case 3:cout<<"\n\nPreordered Binary tree is  : ";
   	  T.predisp();
   	  cout<<"\nPostordered Binary tree is : ";
   	  T.posdisp();
   	  cout<<"\nInordered Binary tree is   : ";
   	  T.indisp();
   	  cout<<"\n\n============================================================\n";
  	  break;
   case 4:cout<<"\n\nPreordered Binary tree is  : ";
   	  T.disp_preo_nr();
   	  cout<<"\nPostordered Binary tree is : ";
   	  T.disp_poso_nr();
   	  cout<<"\nInordered Binary tree is   : ";
   	  T.disp_ino_nr();
   	  cout<<"\n\n============================================================\n";
  	  break;
   case 5:T.erase_nr();
	  cout<<"\nBinary tree Deleted Successfully\n";
	  break;
   case 6:T.erase();
	  cout<<"\nBinary tree Deleted Successfully\n";
	  break;
   case 7:break;
   default:cout<<"\nPls Enter the correct choice";
  }
 }
 return 0;
}

