#include<iostream>
using namespace std;
template <typename T>
class Queue;

template <typename T>
class Node
{
	public:
	 int data;
	 Node<T>*next;

	 

		
	Node()
	{
		data=0;
		next=0;
	}
  Node(const int n,Node *ptr=0)
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
	
	public:
		
	Queue()
	{
		front=rear=0;
	}
	
	void enqueue(T n)
	{
		if(isempty())
		{
			
			Node<T>*newptr=new Node<T>(n);
			rear=front=newptr;
			
			
		}
		else
		{
			
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
	
	
	
};


	




int main()
{

  Queue <int>q1;

  q1.enqueue(2);
  q1.enqueue(1);
    
q1.print();

q1.Dequeue();
q1.Dequeue();

q1.print();
	

	
	
}
