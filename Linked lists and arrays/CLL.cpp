#include<iostream>
using namespace std;

template<class T>
class CLL;
template<typename T>
class Node
{
	private:
	T  data;
	Node <T>*next;
	Node <T>*prev;
	
	public:

	Node()
	{
		
		next=0;
		prev=0;
	}
	
	Node(T no,Node<T>*n=0,Node<T>*p=0)
	{
		data=no;
		next=p;
		prev=p;
		
	}
	
Node<T>* getnext()
	{
		return next;
		
	}
	Node<T>* getprev()
	{
		return prev;
		
	}
	friend class CLL<T>;
};

template<typename T>
class CLL
{


Node<T>*head;

  public:
  	
  	CLL()
  	{
  		head=0;
	}
	
	CLL(const CLL<T>&rhs)
	{
       if(head!=0)
       {
       	Node<T>*temp1=rhs.head,*temp2;
       	Node<T>*newptr=new Node<T>(head.data);
       	head=newptr;
       	temp2=head;
       	while(temp1->next!=0)
       	{
       		temp1=temp1->next;
       		newptr=newnode(temp1->data);
       		temp2->next=newptr;
       		temp2=newptr;
       	 }
       	 temp2=head;
       	
       	}
	}
	
	void insertatfront(int n)
	{
		Node<T>*newptr=new Node<T>(n);
		Node<T>*temp;
		temp=head;
		if(head==0)
		{
          head=newptr;
          newptr->next=head;
          
		}
	   
		else
		{
		  newptr->next=head;
		  while(temp->next!=head)
		  temp=temp->next;
		  
		  temp->next=newptr;
		  head=newptr;
		  	
		
		}
		
		
	
		
	}
	
	void insertatlast(int n)
	{

		Node<T>*newptr=new Node<T>(n);
		Node<T>*temp;
		temp=head;
		if(head==0)
		{
          head=newptr;
          newptr->next=head;
		}
		
		else
		{
			while(temp->next!=head)
			{
				
				temp=temp->next;
		    }
		    temp->next=newptr;
		    newptr->next=head;
		
		}
		
	}
	
	void print(int n)
	{
		
		
		int count;
		Node<T>*temp;
		temp=head;
		while(count!=n)
		{
			cout<<temp->data<<endl;
			count++;
			temp=temp->next;
		}
	}
		
	void removefromlast()
	{
		Node<T>*temp=head,*prev;
		while(temp->next!=head)
		{
			prev=temp;
			temp=temp->next;
			
			
		}
		prev->next=head;
		delete temp;
		temp=0;
	}
		
	void Reverse()
	{
		Node<T> *next=NULL,*current=head,*prev=NULL;
		while(current->next!=head)
		current=current->next;
		
		current->next=0;
	    current=head;
		
		while(current!=NULL)
		{
			 next=current->next;
			 current->next=prev;
			 prev=current;
			 current=next;
		}
		head=prev;
		current=head;
		while(current->next!=0)
		current=current->next;
		current->next=head;
		
			
	
		
		
	}
		
		
	
};
int main()
 {
 	CLL<int>obj1;
	obj1.insertatfront(3);
 	obj1.insertatfront(2);
 	obj1.insertatfront(1);
 	obj1.insertatlast(4);
 	obj1.insertatlast(5);
 //	obj1.removefromlast();
 
 	
 	cout<<"\nObject 1 :\n";
 	obj1.print(10);
 	cout<<endl<<endl;
 	obj1.Reverse();
 	obj1.print(10);
 }
 
  	
