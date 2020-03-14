//Devesh M Bhogre
//203242
//SY-BTECH CSE-B B1
//Assingment 3

#include<iostream>
using namespace std;
class node
{
 string word;
 string meaning;
 node *left;
 node *right;
 friend class tree;
 friend class queue;// friend class queue;
};

class tree
{
  node *root;
 public:
 	tree()
	{
	 root=NULL;
	}
	//create
        void bst_create_nr();
	void bst_create();
	void bst_create_R(node *,node *);
	//display
	//=============================================
 	void display_preo_btree(node *); //pre display    (root,left,right)
	void display_poso_btree(node *); //post display   (left,right,root)
	void display_ino_btree(node *);  //in display     (left,root,right)
	void predisp();
        void posdisp();
        void indisp();
	void bfs();
	//==============================================
        //height
	int height_r(node *);
	int ht();
	//search
	node * bst_search(node *,string);
	void sh(string);
        //deleting
        void bst_delete(node *);
        void dt();
	//copying
        node* copy_tree(node *);
        node* cpy(node *);
        node* getroot();
        //mirroring
        void mirror(node *);
        void glass();
        //===============================================
	
};

//=====================================================================================

class queue
{
  int f,r;
  node *d[20];
  public:
	 queue();
	 void insert(node *);
	 node* qdelete();
	 int isempty();
};

queue::queue()
{
 f=r=-1;
}

void queue::insert(node *temp)
{
 r++;
 d[r]=temp;
}

node* queue::qdelete()
{
 f++;
 return(d[f]);
}

int queue::isempty()
{
 if(f==r)
  return 0;
 else
  return 1;
}

//====================================================================================

void tree::bst_create_nr()
{
  node *temp,*curr;
  int flag=0;
  char ch;
  do
  {
    if(root==NULL)
    {
     root=new node();
     cout<<"\nEnter the root keyword & meaning:\n";
     cin>>root->word;
     cin.ignore();
     getline(cin,root->meaning);
     root->left=root->right=NULL;
    }
    else
    {
     temp=root;
     curr=new node();
     curr->left=curr->right=NULL;
     cout<<"\nEnter the keyword & meaning:\n";
     cin>>curr->word;
     cin.ignore();
     getline(cin,curr->meaning);
     while(flag==0)
     {
        if(curr->word<temp->word)
        {
	  if(temp->left==NULL)
	  {
	   flag=1;temp->left=curr;
	  }
	  else
	  {temp=temp->left;}
        }
	else if(curr->word>temp->word)
	{
	  if(temp->right==NULL)
	  {
	   flag=1;temp->right=curr;
	  }
	  else
	  {temp=temp->right;}
        }
	else
	{
	 cout<<"\n Duplicate not allow in BST";
	 flag=1;
	}
    }//inside while
   }//else
    cout<<"\nDo you want to Add more elements to Binary tree (y/n): ";
    cin>>ch;
 flag=0;
 }while(ch=='y');
}

//======================================================
void tree::bst_create()
{
 node *curr;
 char ch;
 do
 {
  if(root==NULL)
  {
   root=new node();
   cout<<"\nEnter the Keyword & Meaning:\n";
   cin>>root->word;
   cin.ignore();
   getline(cin,root->meaning);
   root->left=root->right=NULL;
  }
  else
  {
     curr=new node();
     curr->left=curr->right=NULL;
     cout<<"\nEnter the Keyword & Meaning:\n";
     cin>>curr->word;
     cin.ignore();
     getline(cin,curr->meaning);
     bst_create_R(root,curr);
  }
     cout<<"\nDo you want to Add more elements to Binary tree (y/n): ";
    cin>>ch;
 }while(ch=='y');
}

void tree::bst_create_R(node *root,node *curr)
{
        if(curr->word < root->word)
        {
	  if(root->left==NULL)
	  {
	   root->left=curr;
	  }
	  else
	  {bst_create_R(root->left,curr);}
        }
	else if(curr->word > root->word)
        {
	  if(root->right==NULL)
	  {
	   root->right=curr;
	  }
	  else
	  {bst_create_R(root->right,curr);}
        }
}
//===============================================================================
//recurcive display

void tree::display_preo_btree(node *root)      //preorder
{
 if(root!=NULL)
 {
  cout<<root->word<<" => "<<root->meaning<<"\n";
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
  cout<<root->word<<" => "<<root->meaning<<"\n";
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
  cout<<root->word<<" => "<<root->meaning<<"\n";
  display_ino_btree(root->right);
 }
}

void tree::indisp()
{
 display_ino_btree(root);
 cout<<endl;
}

//============================================================================

void tree::bfs()
{
 queue q;
 node *temp;
 temp=root;
 q.insert(temp);
 cout<<endl;
 while(q.isempty()!=0)
 {
  temp=q.qdelete();
  cout<<endl<<temp->word<<" => "<<temp->meaning;
  if(temp->left!=NULL)
  {
     q.insert(temp->left);
     //cout<<endl<<"/"<<endl;
  }
  if(temp->right!=NULL)
  {
     q.insert(temp->right);
     //cout<<endl<<"\\"<<endl;
  }
 }
}
 
//===============================================================
//height

int tree::height_r(node *root)
{
 int t1,t2;
 if(root == NULL)
  return 0;
 t1=height_r(root->left);
 t2=height_r(root->right);
 if(t1>t2)
  return (t1+1);
 else
  return (t2+1);
}

int tree::ht()
{
 int h;
 h=height_r(root);
 return h;
}

//===============================================================
//search
node* tree::bst_search(node *root,string key)
{
 while(root!=NULL)
 {
    if(key==root->word)
      return (root);
    else if(key<root->word)
      root=root->left;
    else
      root=root->right;  
 }
 return (NULL);
}

void tree::sh(string key)
{
  node *temp;
  temp=bst_search(root,key);
  if(temp!=NULL)
  {
    cout<<"\nKey found!!\n\n";
    cout<<temp->word<<"=>"<<temp->meaning<<"\n";      
  }
  else
    cout<<"\nKey not found!!\n";
}

//===============================================================
//Delete
void tree::bst_delete(node *root)
{
  int flag=0;
  string key;
  cout<<"Enter the key to delete: ";
  cin>>key;
  node *curr,*temp,*temp1,*temp2,*s,*p; //p=parent
  p=NULL;
  //as root is modified in b/w so using curr to traverse
  curr=root;
  while(curr!=NULL)
  {
  if(key==curr->word)
  {  
        if(curr==root)
        {      
          if(curr->left==NULL && curr->right==NULL)
          {
           delete (curr);
          }
          else if(curr->left!=NULL && curr->right==NULL)
          {
           root=curr->left;
           curr->left=curr->right=NULL;
           delete (curr);
          }
          else if(curr->left==NULL && curr->right!=NULL)
          {
            root=curr->right;
            curr->left=curr->right=NULL;
            delete (curr);
          }
          else if(curr->left!=NULL && curr->right!=NULL)
          {
           temp=curr->left;
           root=curr->right;
           s=root;
           while(s->left!=NULL)
           {s=s->left;}
           s->left=temp;
           curr->left=curr->right=NULL;
           delete (curr);
          }    
        }//if end
        else
        {      
          if(curr->left==NULL && curr->right==NULL)
          {
           if(curr==p->left)
            p->left=NULL;
           else
            p->right=NULL;     
           delete (curr);
          }
          else if(curr->left!=NULL && curr->right==NULL)
          {
           if(curr==p->left)
            p->left=curr->left;
           else
            p->right=curr->left;
           curr->left=curr->right=NULL;
           delete (curr);
          }
          else if(curr->left==NULL && curr->right!=NULL)
          {
           if(curr==p->left)
            p->left=curr->right;
           else
            p->right=curr->right;
           curr->left=curr->right=NULL;
            delete (curr);
          }
          else if(curr->left!=NULL && curr->right!=NULL)
          {
           temp1=curr->right;
           temp2=curr->left;
           s=temp1;
           if(curr==root->left)
            p->left=temp1;
           else
            p->right=temp1;
           while(s->left!=NULL)
           {s=s->left;}
           s->left=temp2;
           curr->left=curr->right=NULL;
           delete (curr);
          }
        }
   flag=1;     
   cout<<"\nKey deleted!!";
   break;
   }
   else if(key<curr->word)
   {
     p=curr;      
     curr=curr->left;
   }
   else if(key>curr->word)
   {  
     p=curr;    
     curr=curr->right;
   } 
  }
  if(flag==0)
   cout<<"\nKey not found";
}

void tree::dt()
{
  bst_delete(root);
}

//======================================================================
//copy

node* tree::copy_tree(node *root)
{
  node *temp;
  temp=NULL;
  if(root!=NULL)
  {
    temp=new node();
    temp->word=root->word;
    temp->meaning=root->meaning;
    temp->right=copy_tree(root->right);
    temp->left=copy_tree(root->left);    
  }
  return (temp);
}

node* tree::cpy(node* t)
{
  root=copy_tree(t);   //copying in the t2's root
}

node* tree::getroot()
{
  return (root);
}
//======================================================================
//mirror image

void tree::mirror(node *root)
{
  node *temp;
  if(root!=NULL)
  {
  temp=root->left;
  root->left=root->right;
  root->right=temp;
  mirror(root->left);
  mirror(root->right);
  }
}

void tree::glass()
{
  mirror(root);
}

//============================================================================

void bst_disp(tree T)
{
  cout<<"\n\nPreordered BST is  :\n\n";
  T.predisp();
  cout<<"\nPostordered BST is : \n\n";
  T.posdisp(); 	  
  cout<<"\nInordered BST is   : \n\n";
  T.indisp();
  cout<<"\n\n============================================================\n";
}

//========================================================


int main()
{
 tree T,T2;
 int ch,h;
 string key;
 node *croot;
 while(ch!=10)
 {
  cout<<"\n============================================================\n";
  cout<<"\nEnter choice to perform operations on Binary Search Tree (BST): ";
  cout<<"\n1. Create BST using Non-Recursive Method";
  cout<<"\n2. Create BST using Recursive Method";
  cout<<"\n3. Displaying BST Using Recurcive Methods in all orders (pre/post/in)";
  cout<<"\n4. Displaying BST Using Breath first Traversal (BFS)";
  cout<<"\n5. Height of BST";
  cout<<"\n6. Search in BST";
  cout<<"\n7. Delete from BST";
  cout<<"\n8. Copy BST in to Another";
  cout<<"\n9. Mirroring tree";
  cout<<"\n10.Exit";
  cout<<"\n\nChoice:";
  cin>>ch;
  switch(ch)
  {
   case 1:T.bst_create_nr();                           //bst_disp() is a "outside function" not a funtion of tree or node
          bst_disp(T);
	  break;
   case 2:T.bst_create();
          bst_disp(T);
	  break;
   case 3:bst_disp(T);
  	  break;
   case 4:cout<<"\nBFS BST is : ";
	  T.bfs();
	  cout<<"\n\n============================================================\n";
	  break;
   case 5:h=T.ht();
	  cout<<"\nHeight of BST is : "<<h;
          break;
   case 6:cout<<"\nEnter the key to search:";
          cin>>key;
          T.sh(key);
          break;
   case 7:T.dt();
          bst_disp(T);
          break;
   case 8:croot=T.getroot();
          T2.cpy(croot);
          cout<<"\nCopied tree is:";
          bst_disp(T2);
          break;        
   case 9:T.glass();
          cout<<"\nMirror image of BST is:";
          bst_disp(T);      
          break;
  case 10:break;
   default:cout<<"\nPls Enter the correct choice";
  }
 }
 return 0;
}
  	 
      
     
     
		
