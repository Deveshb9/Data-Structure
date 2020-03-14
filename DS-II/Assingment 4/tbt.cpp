//Devesh M Bhogre
//203242
//SY-BTECH CSE-B B1
//Assingment 4 Threaded binary tree
#include<iostream>
using namespace std;
class node
{
 char data;
 node *left;
 node *right;
 int lbit,rbit;
 friend class tree;
 public:
  node()
	{
		lbit=rbit=1;
	}
 //friend class queue;// friend class queue;
};

class tree
{
  node *head,*root;
 public:
 	tree()
	{
	 root=NULL;
	 head=new node();
	 head->left=head->right=head;
	 head->lbit=head->rbit=0;
	 //head=NULL;
	}
	void tbt_create();
	void preodisp();
	node* ino_sucess(node *);
	void inodisp();
};

void tree::tbt_create()
{
  node *temp,*curr;
	int flag=0;
	char ch,choice;
  do
  {
    if(root==NULL)
    {
      		root=new node();
			//head=new node();
			cout<<"\nEnter root data: ";
			cin>>root->data;
			head->left=root;
			//head->right=head; //termination condition
			//head->lbit=head->rbit=0;
			root->left=root->right=head;
    }
    else
    {
			flag=0;
			temp=root;
			curr=new node();
			cout<<"\nEnter data: ";
			cin>>curr->data;
			curr->left=curr->right=NULL;
			while(flag==0)
			{
			 cout<<"\nWhere to connect the node (l/r) at '"<<temp->data<<"' : ";
			 cin>>ch;
				if(ch=='l')
				{
					if(temp->lbit==1)
					{
						curr->left=temp->left;
						curr->right=temp;
						temp->left=curr;
						temp->lbit=0;
						flag=1;
					}
					else
					 temp=temp->left;
				}
				if(ch=='r')
				{
					if(temp->rbit==1)
					{
						curr->right=temp->right;
						curr->left=temp;
						temp->right=curr;
						temp->rbit=0;
						flag=1;
					}
					else
					 temp=temp->right;
			  }
			}
		}
	flag=0;
	cout<<"\nDo you want to add more nodes (y/n): ";
	cin>>choice;	
 }while(choice=='y');
}		


void tree::preodisp()
{
	node *temp;
	cout<<"\nPreorder traversal:\n";
	temp=head->left;
	while(temp!=head)
	{
		cout<<temp->data<<" ";
		while(temp->lbit==0)
		{
			temp=temp->left;
			cout<<temp->data<<" ";
		}	
		while(temp->rbit==1)
		{
			temp=temp->right;
		}
		if(temp->rbit==0)
		  temp=temp->right;
	}
	cout<<endl;
}

node* tree::ino_sucess(node *temp)
{
	node *x;
	x=temp->right;
	if(temp->rbit==0)
	{
		while(x->lbit==0)
		{
			x=x->left;
		}
	}
	return x;
}

void tree::inodisp()
{
	node *temp;
	cout<<"\nInorder Traversal:\n";
	temp=head;
	while(1) 
	{
    temp=ino_sucess(temp);
	if(temp==head)
	 break;
	 cout<<temp->data<<" "; 
	}
	cout<<endl;
}

int main()
{
	tree T;
	int ch;
	while(ch!=4)
    {
  		cout<<"\n============================================================\n";
  		cout<<"\nEnter choice to perform operations on Threaded Binary Tree (TBT): ";
  		cout<<"\n1.Create Threaded Binary Tree";
  		cout<<"\n2.Display Preorder Traversal";
  		cout<<"\n3.Display Inorder Traversal";
		cout<<"\n4.Exit";
		cout<<"\n\nChoice: ";
  		cin>>ch;
  		switch(ch)
  		{
   		 case 1:T.tbt_create();
	  			break;
   		 case 2:T.preodisp();
	  		    break;
   		 case 3:T.inodisp();
  	 		    break;
   		 case 4:break;
	       default:cout<<"\nPls Enter the correct choice";
  		}
 	}
	return 0;
}














	
