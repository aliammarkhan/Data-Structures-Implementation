#include<iostream>
using namespace std;

#include<iostream>
using namespace std;
template<typename T>
class DLL;

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
	friend class DLL<T>;
};

template<typename T>
class DLL{


private:
	Node<T>*head;
	Node<T>*tail;
	
public:
	
	DLL()
	{
		head=tail=0;
	}
	
	DLL(const DLL<T> &rhs)
	{
      Node<T>*newptr=new Node<T>(rhs.head->data);
      head=newptr;
      tail=head;
      Node<T>*temp=rhs.head;
      Node<T>*prev=head;
      
      do
      {
      	
      	temp=temp->next;
      	newptr=new Node<T>(temp->data);
      	newptr->prev=prev;
      	prev->next=newptr;
      	prev=tail=newptr;
      	} while(temp->next!=NULL);
      
		
	}
	void insertatfront(T n)
	{
		Node<T>*newptr=new Node<T>(n);
		
		if(head==0)
		{
			head=newptr;
			tail=newptr;
		}
		else
		{
			 head->prev=newptr;
             newptr->next=head;
             head=newptr;		 
	   }
	   
	  
		
		}
		
void insertatlast(T n)
{
	Node<T>*newptr=new Node<T>(n);
	Node<T>*temp=head;
	
	if(head==0)
	{
		head=newptr;
		tail=head;
		
   }
   
   else{
   	
   	   newptr->prev=tail;
		tail->next=newptr;
		tail=newptr;
   	   
}

	
	
	
	
}
	void printfromhead()
	{
		
		Node<T>*temp;
		temp=head;
		
		while(temp->next!=0)
		{
			
		cout<<temp->data<<endl;
			temp=temp->next;
			
		}
		
		cout<<temp->data<<endl;
	}
	void printfromtail()
	{
			Node<T>*temp;
		temp=tail;
		
		while(temp->prev!=0)
		{
			
		cout<<temp->data<<endl;
			temp=temp->prev;
			
		}
		
		cout<<temp->data<<endl;
	}
	
	
void removefromfront()
{
	if(head!=0)
	{
	  Node<T>*temp=head;
      head=head->next;
      head->prev=0;
	  temp->next=0;
	  temp->prev=0;
	  delete temp;
	  temp=0;
}
	
}
void removefromlast()
{
	if(head!=0)
	{
		Node<T>*temp=head;
		while(temp->next!=NULL)
		temp=temp->next;
		
		tail=temp->prev;
		tail->next=0;
		temp->next=0;
		temp->prev=0;
		delete temp;
		temp=0;
		
	}
	}
	
	void reverse()
	{
		Node<T>*temp=NULL,*current=head;
		
		while(current!=NULL)
		{
			temp=current->prev;
			current->prev=current->next;
			current->next=temp;
			current=current->prev;
		
			
		}
			
		if(temp!=0)
		head=temp->prev;
	   temp=head;
		while(temp->next!=NULL)
		{
	
		temp=temp->next;
		}
			
		
		
		
		tail=temp;		
	}
	



	
	
	
	
	

};
int main()
{
	DLL<int>obj;
	for(int i=5;i>=0;i--)
	obj.insertatfront(i);
	for(int i=6;i<=10;i++)
	obj.insertatlast(i);
    
    DLL<int>obj1(obj);
    obj.removefromfront();
    obj.removefromlast();
    obj.removefromlast();
    obj.reverse();
    obj.printfromtail();
    
    
	
}




