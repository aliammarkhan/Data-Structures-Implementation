#include<iostream>
using namespace std;

template<typename T>
class SLL;

template<typename T>

class Node
{
	T data;
	Node<T>*next;
   
   public:
  Node()
  {
  	data=0;
  	next=NULL;
  }
  
  Node(T n,Node<T>*ptr=0)
  {
    data=n;
	next=ptr;
  } 
  friend class SLL<T>;
  	
};
template <typename T>

class SLL
{
   Node<T>*head;
   public:
   SLL()
   {
   	 head=0;
   }
   SLL(Node<T>*ptr)
   {
   	head=ptr;
   }
   
   void insertatfront(int n)
   {
   	
   	Node<T>*newptr=new Node<T>(n);
   	Node<T>*temp;
   	
   	if(head==0)
   	{
   	    head=newptr;
	
   	}
   	else
   	{
      newptr->next=head;
     head=newptr;
   	}

   	
}
   void insertatlast(int n)
   {
   	
   	Node<T>*newptr=new Node<T>(n);
   	Node<T>*temp=0;
   	
   	if(head==0)
   	{
   	    head=newptr;
		
   	}
   	else
   	{
        temp=head;
        while(temp->next!=NULL)
        {
        	temp=temp->next;
        	
		}
		
		temp->next=newptr;
		temp=0;

   		
   		
   	}
   	
}

	SLL(const SLL <T>&rhs)
	{
		  
		  if(rhs.head==0)
		  {
		  	 head=0;
          }
          else
          {
          	
          	Node<T>*temp=rhs.head;
          	Node<T>*newptr=new Node<T>(temp->data);
          	head=newptr;
          	Node<T>*prev=newptr;
          	do
          	{
               temp=temp->next;
			   newptr=new Node<T>(temp->data);
			   prev->next=newptr;
			   prev=newptr;		
          		
          		
          }while(temp->next!=NULL);
    }
	
}

void removefromfront()
{
	
	if(head!=0)
	{
		Node<T>*temp=head;
		head=head->next;
		temp->next=0;
		delete temp;
		temp=0;
	}
	
}
void removefromlast()
{
	Node<T>*prev;
	if(head!=0)
	{
		Node<T>*temp=head;
		while(temp->next!=NULL)
		{
			prev=temp;
		temp=temp->next;
		}
		prev->next=0;
		delete temp;
		temp=0;
	}
	
}

void Reverse()
{
	
	Node<T>*current=head,*next=NULL,*prev=NULL;
	while(current!=NULL)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	head=prev;
	
}
	void print()
{
	Node<T>*temp=head;
	
	while(temp->next!=0)
	{

		cout<<temp->data<<endl;
		temp=temp->next;
		
	}
		cout<<temp->data<<endl;
}
	
};

int main()
{
	SLL<int>obj;
	for(int i=5;i>=0;i--)
	obj.insertatfront(i);
	for(int i=6;i<=10;i++)
	obj.insertatlast(i);
	
	obj.print();
	
	SLL<int>obj1(obj);
	cout<<endl;
	obj1.Reverse();
	obj1.removefromfront();
	obj1.removefromlast();
	obj1.print();

	
}



