#include<iostream>

using namespace std;
template <typename T>
class Queue;

template <typename T>
class Node
{
	public:
	 T data;
	 Node<T>*next;

	 

		
	Node()
	{
		data=0;
		next=0;
	}
  Node(const T n,Node *ptr=0)
  {
  	   data=n;
  	   next=ptr;

  }
  
friend class Queue<T>;
};

template <typename T>
class Queue
{
	
	Node<T> *front;
	Node<T> *rear;
	int count;
	
	public:
		
	Queue()
	{
	   front=rear=0;
	   count=0;
	}
	
	void enqueue(T n)
	{
		if(isempty())
		{
			count++;
			Node<T>*newptr=new Node<T>(n);
			rear=front=newptr;
			
			
		}
		else
		{
			count++;
			Node<T>*newptr=new Node<T>(n);
			rear->next=newptr;
			rear=newptr;
		}
		
		
		
		
	}
T Dequeue()
	{
		T var;
		
		if(isempty())
		{
			cout<<"\nQueue is empty\n";
		
		}
    else
	{
		count--;
	   Node<T>*temp;
	   temp=front;
	   front=front->next;
	   var=temp->data;
	   delete temp;
	   temp=0;	
	   if(front==0)
	   rear=0;
	   return var;
		
	}		
}

 T Front()
 {
 	if(!(isempty()))
 	{
 	   return front->data;	
 		
	}
 	
 	
 	
 }


void print()
{
			if(isempty())
		{
			cout<<"\nQueue is empty\n";
			return;
	     }
	Node<T>*temp=front;
	
	while(temp->next!=NULL)
	{
		cout<<temp->data<<endl;
		temp=temp->next;
		
		
	}
		cout<<temp->data<<endl;
	
	
	
	
	
}
	bool isempty()
	{
		if(front==0&&rear==0)
		return true;
		else 
		return false;
	}
	void Delete_negatives()
{
	Node<T>*temp=front,*prev=front;

   
	while(temp->next!=NULL)
	{
	  
	  if(front->data<0)
     {
     
     	temp=front;
     	front=front->next;
     	delete temp;
     	temp=front;
     	prev=front;
     }
     else if(temp->data<0)
     {
     	
     	Node<T>* t=temp;
     	temp=prev->next=temp->next;
        delete t;
		t=0;     	
     	
     	
	}
	else
	{
	 
	prev=temp;
	temp=temp->next;  
     }
}
	if(temp->data<0)
	{
		prev->next=0;
		delete temp;
		temp=0;
		
	}
	
}
	
  int get_count()
  {
  	return count;
  }
	
};
template <typename T>
class BST;
template<typename T>

class BTnode
{
	T data;
	BTnode<T> *left;
	BTnode<T>*right;
	
	public:
		
	BTnode(T d,BTnode<T>*ptr1=0,BTnode<T>*ptr2=0)
	{
		data=d;
	    left=ptr1;
	    right=ptr2;
		
    }
	
	friend class BST<T>;
	
	};
template<typename T>
class BST
{
	  public:
	BTnode<T> *root;
	

  	
  		BST (BTnode<T>*ptr=0)
  		{
  	      root=ptr;		
  			
	   }
	   BST( BST &rhs)
	   {
	   	 
	   	  if(rhs.root==0)
	   	  {
	   	  	
	   	  	root=0;
	   	     	
		  }
		  else
		  
		  {
		  	
	        Queue<BTnode<T>*> q1;
			Queue<BTnode<T>*> q2;
			BTnode<T>*newptr=new BTnode<T>(rhs.root->data);
			
					
	
			root=newptr;
			BTnode<T>*current;
			BTnode<T>*rhscurrent;
		     
		     q1.enqueue(rhs.root);
		     q2.enqueue(root);
		    
			while(!(q1.isempty()))
           {
         
           	   rhscurrent=q1.Dequeue();
           	   
           	   if(rhscurrent->left!=NULL)
			  	{
			  	 q1.enqueue(rhscurrent->left);
				 current=q2.Front();
				 current->left=new BTnode<T>(rhscurrent->left->data);
				}
				if(rhscurrent->right!=NULL)
				{
				 q1.enqueue(rhscurrent->right);
				 current=q2.Front();
				 current->right=new BTnode<T>(rhscurrent->right->data);
				 
				  
				
				}
				  q2.Dequeue();
				  if(rhscurrent->left!=NULL)
				  q2.enqueue(current->left);
				  if(rhscurrent->right!=NULL)
				  q2.enqueue(current->right);
				 
				 
           	
		   }				  	
		  	
		  	
		  	
		  	
		  	
		  }
		  }
	   	  
	   	
	   	
	   	
	   	
	   
	   
   BTnode<T>* insert(T d,BTnode<T>*root)
   {
   	  if(root==NULL)
   	  {
   	    root=new BTnode<T>(d);
   	    return root;
		
   	  	
	  }
	  else if(d<root->data)
	  {
	  	
	  	root->left=insert(d,root->left);
	  }
	  else
	  root->right=insert(d,root->right);
	}
	void insert(T d)
	{
		root=insert(d,root);
		
	}
	
	   
  		
void BFS_print()
{
  Queue<BTnode<T>*> q1;	
	BTnode<T>*temp;
	if(root!=NULL)
	q1.enqueue(root);
	
	while((!q1.isempty()))
	{
	  temp=q1.Dequeue();
	  if(temp!=NULL)
	  cout<<temp->data<<endl;
	  if(temp->left!=NULL)
	  q1.enqueue(temp->left);
	  if(temp->right!=NULL)
	  q1.enqueue(temp->right);	
    }
	
	
	
}
void preorder_print(BTnode<T>*current)
{
	if(current==NULL)return;
	cout<<current->data<<endl;
	preorder_print(current->left);
	preorder_print(current->right);
	
	
}
void inorder_print(BTnode<T>*current)
{
	 	if(current==NULL)return;
	
	inorder_print(current->left);
	cout<<current->data<<endl;
	inorder_print(current->right);
	
}
void postorder_print(BTnode<T>*current)
{
		if(current==NULL)return;
	
	postorder_print(current->left);
	postorder_print(current->right);
	cout<<current->data<<endl;
}

void iterative_insert(T d)
{
	
	BTnode<T>*current=root;
	if(root==NULL)
	{
		root=new BTnode<T>(d);
		
	}
	 
	else
	{
		while(current!=NULL)
		{
			if(d<=current->data)
			{
				if(current->left==NULL)
				{
				 current->left=new BTnode<T>(d);
				 return;
			    }
			    current=current->left;
				
				
				
			}
			else
			{
				if(current->right==NULL)
				{
				 current->right=new BTnode<T>(d);
				 return;
			    }
			    current=current->right;
				
				}
			
		}
}
	
}
BTnode<T>* get_root()
{
	return root;
}

int height(BTnode<T>*current)
{
	static int righth;
	static int lefth;
	
	if(current==NULL)
	{
		
		return -1;
		
		
	}
	lefth+=height(current->left);
	righth+=height(current->right);
	
	return max(height(current->left),height(current->right))+1;
	
	
}
int max(int d1,int d2)
{
	
	if(d1<d2)
	return d2;
	else
	return d1;
}

bool isBST(BTnode<T>*current,int min=INT_MIN,int max=INT_MAX)
{
	if(current==NULL)return true;
	
	if((current->data)>min&&(current->data)<max)
	{
		 if(isBST(current->left,min,current->data)&&isBST(current->right,current->data,max))
		 return true;
		else
		return false;
		
	}
	else
	return false;
	
}
int width()
{
	int width=0,maxw=0,i;
	BTnode<T>*current=root;
	

	Queue<BTnode<T>*>q1;
	Queue<BTnode<T>*>q2;

	

	if(root!=0)
	{
	  q1.enqueue(root);
	  
	  while(!(q1.isempty()))
	  {
	  	  
	  	  while(!(q1.isempty()))
	  	  {
	  	  	current=q1.Dequeue();
	  	 
	  	  	if(current->left!=NULL)
	  	  	q2.enqueue(current->left);
	  	  	if(current->right!=NULL)
	  	  	q2.enqueue(current->right);
	  	    	
	  	 }
	  	  width=q2.get_count();
	
		  if(width>maxw)
		  maxw=width;
		  width=0;
		  while(!(q2.isempty()))
		  {
		  	q1.enqueue(q2.Dequeue());
		  }

	  	
	  	
	  	
	  }
		return maxw;
		
		
		
		
	}
	else
	return 0;
	
	
	
	
	
	
	
	
	
	
	
}

 BTnode<T>* findmin(BTnode<T>*current)
 {
 	
 	while(current->left!=NULL)
 	{
 		
 		current=current->left;
 	}
 	return current;
}
 BTnode<T>* findmax(BTnode<T>*current)
 {
 	
 	
 	while(current->right!=NULL)
 	{
 		
 		current=current->right;
 	}
 	return current;
}
int get_data(BTnode<T>*ptr)
{
	return ptr->data;
	
}
BTnode<T>* Delete(BTnode<T>*current,int n)
{
	if(current==0)
	return current;
	else if(n<current->data)
	current->left=Delete(current->left,n);
	else if(n>current->data)
	current->right=Delete(current->right,n);
	else
	{
		if(current->left==NULL&&current->right==NULL)  //handling of case 1 if both childs are null
		{
			delete current;
			current=0;
		}
		else if(current->left==NULL)  //handling of case 2 if one child is null
		{
			BTnode<T>*temp=current;
			current=current->right;
			delete temp;
			temp=0;
		}
			else if(current->right==NULL)
		{
			BTnode<T>*temp=current;
			current=current->left;
			delete temp;
			temp=0;
		}
		else //handling of case 3 if both childs are null by reducing to case 1 and case 2
		     //by finding min in right subtree and copying it in to be deleteed tree and then deleting the 
		     //right subtree
		     //or we can find the max in left subtree and copy it the to be delete node and delete the left subtree with max value
		{
			BTnode<T>*temp=findmin(current->right);
			current->data=temp->data;
			current->right=Delete(current->right,temp->data);
		}
       return current;		
		
		
		
		
		
		
	}
	
}

void Delete(int d)
{
root=	Delete(root,d);
	
}
  		
void illegal()// this function will make a BST not a BST
  	{
  	   BTnode<T>*current=root;
		 while(current->left!=0)
		 current=current->left;
		 current->left=new BTnode<T>(INT_MAX);
		 		
  	   		
    }
    int diameter(BTnode<T>* tree) 
{ 
   /* base case where tree is empty */
   if (tree == NULL) 
     return 0; 
  
  /* get the height of left and right sub-trees */
  int lheight = height(tree->left); 
  int rheight = height(tree->right); 
  
  /* get the diameter of left and right sub-trees */
  int ldiameter = diameter(tree->left); 
  int rdiameter = diameter(tree->right); 
  
  /* Return max of following three 
   1) Diameter of left subtree 
   2) Diameter of right subtree 
   3) Height of left subtree + height of right subtree + 1 */
  return max(lheight + rheight + 1, max(ldiameter, rdiameter)); 
}  
  		
  		void Deleteall(BTnode<T>*current)
  		{
  		
  		    if(current==0)
  		     return;
  		    
  		    Delete(current->data);
  		    Deleteall(root);
  		    
  		   
  		   	
  		}
  		
  	~BST()
  	{
  	  Deleteall(root);
  		
	}
	  
	
	
	
	
};



int main()
{
//  BST<int>t1,t2;
//  BTnode<int>*ptr; 
//  cout<<"Tree 1:"<<endl<<endl;
//   t1.insert(10);
//
//   t1.insert(15);
//   t1.insert(5);
//   t1.insert(16);
//   t1.insert(7);
//   t1.insert(11);
//   t1.insert(4);
//   ptr=t1.findmax(t1.get_root());
//   cout<<"\nMAX:"<<t1.get_data(ptr);
//   ptr=t1.findmin(t1.get_root());
//   cout<<"\nMin:"<<t1.get_data(ptr);
//   //t1.illegal();
//
//   cout<<"\nBreadth First Traversal:"<<endl;
//   t1.BFS_print();
//   cout<<"\nDepth First Traversal(preorder):"<<endl;
//   t1.preorder_print(ptr);
//   cout<<"\nDepth First Traversal(inorder):"<<endl;
//   t1.inorder_print(ptr);
//   cout<<"\nDepth First Traversal(postorder):"<<endl;
//   t1.postorder_print(ptr);
//
//
//
//
//cout<<"\n\nTree 2:"<<endl<<endl;
//
//   t2.iterative_insert(10);
//   t2.iterative_insert(15);
//   t2.iterative_insert(9);
//   t2.iterative_insert(16);
//   t2.iterative_insert(7);
//   t2.iterative_insert(11);
//   t2.BFS_print();
//
//  cout<<"\n\nHeight:";
//  cout<<t1.height(ptr);
//  
//if(t1.isBST(ptr))
//cout<<" \nt1 is a BST\n";
//
//else
//cout<<" \nt1 is not a BST\n";
//
//	cout<<"\n\nWidth:";
//  cout<<t1.width();
//  
//     BST<int>t3(t2);
//      cout<<"\n\nTree 3:"<<endl<<endl;
//  cout<<"\nBreadth First Traversal:"<<endl;
//   t3.BFS_print();
//	
 BST<int>t4;
 
  t4.insert(100);
  t4.insert(90);
  t4.insert(110);
  t4.insert(80);
  t4.insert(95);
  t4.insert(105);
  t4.insert(120);
  t4.insert(79);
  t4.insert(82);
  t4.insert(94);
  t4.insert(96);
  t4.insert(104);
  t4.insert(106);
  t4.insert(119);
  t4.insert(121);
 //cout<<"\nDiameter:"<<t4.diameter(t4.get_root())<<endl;
  t4.preorder_print(t4.get_root());


}
