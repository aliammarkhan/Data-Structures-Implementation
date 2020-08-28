#include<iostream>
using namespace std;
bool x=false;
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
class AVL;
template<typename T>

class BTnode
{
	T data;
	BTnode<T> *left;
	BTnode<T>*right;
	int bf;
	
	public:
		
	BTnode(T d,BTnode<T>*ptr1=0,BTnode<T>*ptr2=0,int n=0)
	{
		data=d;
	    left=ptr1;
	    right=ptr2;
	    bf=n;
		
    }
	
	friend class AVL<T>;
	
	};
	
	
template<typename T>
class AVL
{
	private:
		BTnode<T>*root;
		
		public:
			
		AVL(BTnode<T>*ptr=0)
		{
		   root=ptr;	
		}
		
      	   
   BTnode<T>* insert(T d,BTnode<T>*current)
   {
   	
   	  if(current==NULL)
   	  {
   	    current=new BTnode<T>(d);
   	    return current;
		
   	  	
	  }
	  else if(d<current->data)
	  {
	  	
	  	current->left=insert(d,current->left);
	  }
	  else if(d>current->data)
	  current->right=insert(d,current->right);
	  
	 
	  current->bf=(height(current->left)-height(current->right));
	  
	
	  if(current->bf>1 || current->bf<-1 )
	  {
	  	 cout<<current->data<<endl;
	  	 
		  if(current->right!=NULL)	
	  	  if(check(current->right->right,d))  //for right right case
	  	  {
	  	  		 	

	  	  	  BTnode<T>*B=current->right;
	  	  	  
	  	  	  if(B->left!=NULL)
	  	  	  {
	  	  	      BTnode<T>*temp=B->left;
				  B->left=current;
				  current->right=temp;	
				   current->bf=(height(current->left)-height(current->right));
				  current=B;
	  	  	  	
			  }
			  else
			  {
			   B->left=current;
			   current->right=0;
			   current->bf=(height(current->left)-height(current->right));
			  
			   current=B;
			  }
			current->bf=(height(current->left)-height(current->right));
			 x=false;
			    return current;
	  	        	
	  	   }
	  	   
		  
	  	if(current->left!=NULL)
	  	if(check(current->left->left,d))  //for left left case
	  	  {
	  
	  	  	  BTnode<T>*B=current->left;
	  	  	  
	  	  	  if(B->right!=NULL)
	  	  	  {
	  	  	      BTnode<T>*temp=B->right;
				  B->right=current;
				  current->left=temp;	
				   current->bf=(height(current->left)-height(current->right));
				   current=B; 
	  	  	  	
			  }
			  else
			  {
			   B->right=current;
			   current->left=0;
			   current->bf=(height(current->left)-height(current->right));
			   current=B; 
			  }
			current->bf=(height(current->left)-height(current->right));
			x=false;
		   return current;
	  	}
	  	if(current->left!=NULL)//LR case
	  	if(current->left->right!=NULL)
	  	if(check(current->left->right,d))
	  	{
	  		
	  		BTnode<T>*A=current;
	  		BTnode<T>*B=current->left;
	  		BTnode<T>*C=current->left->right;
	  	  
		 if(C->left!=NULL)
	  	  B->right=C->left;
		  else
		  B->right=0;
		  if(C->right!=NULL)
	  	  A->left=C->right;
		  else
		  A->left=0;
	  		
	  		C->left=B;
	  		C->right=A;
	  	
	  		A->bf=(height(A->left)-height(A->right));
	  		B->bf=(height(B->left)-height(B->right));
	  		C->bf=(height(C->left)-height(C->right));
	  		current=C;
	  		
	  		x=false;
	  	     return current;
		}
		if(current->right!=NULL)//RL case
	  	if(current->right->left!=NULL)
	  	if(check(current->right->left,d))
	  	{
	 
	  		BTnode<T>*A=current;
	  		BTnode<T>*B=current->right;
	  		BTnode<T>*C=current->right->left;
	  	  
		  if(C->left!=NULL)
		  {
	  	  
	  	  A->right=C->left;
		  }
		  else
		  A->right=0;
		  
		  if(C->right!=NULL)
	  	  B->left=C->right;
		  else
		  B->left=0;
	  		
	  		C->left=A;
	  		C->right=B;
	  	    current=C;
	  		
	        A->bf=(height(A->left)-height(A->right));
	  		B->bf=(height(B->left)-height(B->right));
	  		C->bf=(height(C->left)-height(C->right));
	
	  	
	  		x=false;
	  		  return current;
		}
       
	}
		
	  	else
	  	return current;
	  	
	  	
	  	
	
	}
	
	void insert(T d)
	{
	
		root=insert(d,root);
		
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
		    
		     
		     
		{
			BTnode<T>*temp=findmin(current->right);
			current->data=temp->data;
			current->right=Delete(current->right,temp->data);
		}
    }
    
         if(current==0)
         return current;
		
		current->bf=(height(current->left)-height(current->right));
	
		if(current->bf>1)
		{
		
			current->left->bf=(height(current->left->left)-height(current->left->right));
			if(current->left->bf>=0)//left left
			{
				
	  	  	  BTnode<T>*B=current->left;
	  	  	  
	  	  	  if(B->right!=NULL)
	  	  	  {
	  	  	      BTnode<T>*temp=B->right;
				  B->right=current;
				  current->left=temp;	
				   current->bf=(height(current->left)-height(current->right));
				   current=B; 
	  	  	  	
			  }
			  else
			  {
			   B->right=current;
			   current->left=0;
			   current->bf=(height(current->left)-height(current->right));
			   current=B; 
			  }
			current->bf=(height(current->left)-height(current->right));
				
			}
			else //left right
			{

			BTnode<T>*A=current;
	  		BTnode<T>*B=current->left;
	  		BTnode<T>*C=current->left->right;
	  	  
		 if(C->left!=NULL)
	  	  B->right=C->left;
		  else
		  B->right=0;
		  
		  if(C->right!=NULL)
	  	  A->left=C->right;
		  else
		  A->left=0;
		  
	  		C->left=B;
	  		C->right=A;
	  	
	  
	  		A->bf=(height(current->left)-height(current->right));
	  		B->bf=(height(current->left)-height(current->right));
	  		C->bf=(height(current->left)-height(current->right));
	  		current=C;

			}
			
			
		}
		else if(current->bf<-1)
		{
				
			 
			current->right->bf=(height(current->right->left)-height(current->right->right));
			if(current->right->bf<=0)//RR
			{
				
	  	  	  BTnode<T>*B=current->right;
	  	  	  
	  	  	  if(B->left!=NULL)
	  	  	  {
	  	  	  	;
	  	  	      BTnode<T>*temp=B->left;
				  B->left=current;
				  current->right=temp;	
				   current->bf=(height(current->left)-height(current->right));
				  current=B;
	  	  	  	
			  }
			  else
			  {
			   B->left=current;
			   current->right=0;
			   current->bf=(height(current->left)-height(current->right));
			 
			   current=B;
			  }
			  
			current->bf=(height(current->left)-height(current->right));
			
			}
			else //RL
			{
			
	  		BTnode<T>*A=current;
	  		BTnode<T>*B=current->right;
	  		BTnode<T>*C=current->right->left;
	  		  
			  if(C->left!=NULL)
		  {
	  	  
	  	  A->right=C->left;
		  }
		  else
		  A->right=0;
		  
		  if(C->right!=NULL)
	  	  B->left=C->right;
		  else
		  B->left=0;
	  		
	  		C->left=A;
	  		C->right=B;
	  	
	  		
	        A->bf=(height(current->left)-height(current->right));
	  		B->bf=(height(current->left)-height(current->right));
	  		C->bf=(height(current->left)-height(current->right));
	  		current=C;
			}
			
		}
	return current;
}
	
void Delete(int d)
{
  root=Delete(root,d);	
}	
	bool check(BTnode<T>*current,int d)
	{


	  	if(current==NULL)
		{
		  return x;
		}
		else if(current->data==d)
		{
			x=true;
			return x;
		}
		else if(current->data>d)
		check(current->left,d);
		else
		check(current->right,d);
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
	  cout<<"bf:"<<temp->bf<<endl;
	  if(temp->left!=NULL)
	  q1.enqueue(temp->left);
	  if(temp->right!=NULL)
	  q1.enqueue(temp->right);	
    }
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


BTnode<T>* get_root()
{
	return root;
}	
};






int main()
{
AVL<int>t4;
 
//t4.insert(100);
//t4.insert(90);
//t4.insert(110);
//t4.insert(80);
//t4.insert(95);
//t4.insert(105);
//t4.insert(120);
//t4.insert(79);
//t4.insert(82);
//t4.insert(94);
//t4.insert(96);
//t4.insert(104);
//t4.insert(106);
//t4.insert(119);
//t4.insert(121);
//t4.insert(78);
//t4.insert(77);
//t4.insert(122);
//t4.insert(123);
//t4.insert(5);
//t4.insert(7);
//t4.insert(19);
//t4.insert(12);
//t4.insert(10);
//t4.insert(15);
//t4.insert(18);
//t4.insert(20);
//t4.insert(25);
//t4.insert(23);
//
//t4.Delete(10);
//t4.Delete(5);
//t4.Delete(23);
t4.insert(2);
t4.insert(54);
t4.insert(9);
t4.insert(26);
t4.insert(65);
t4.insert(16);
t4.insert(7);
t4.insert(3);

t4.Delete(16);
t4.BFS_print();

}
	
