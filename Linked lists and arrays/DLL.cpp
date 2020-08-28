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
 class DLL
 {
 	
 	Node<T>*head;
 	Node<T>*tail;
 	
 	
 	
 	public:
 		deleteall()
 		{
 			int i=1;
 			Node<T>* temp=head;
 			
 			while(head!=0)
 			{
 				temp=temp->next;
 				cout<<"Deleting node "<<i<<endl;
 				delete head;
 				head=temp;
 				i++;
 			}
 			head=0;
 			tail=0;
 			
 			
		 }
 		DLL()
 		{
 			head=0;
 			tail=0;
		 
		 }
		 
		 DLL(const DLL<T>&rhs)
		 {
		 	head=0;
	       Node<T>*temp1,*temp2;
	       temp1=head;
		   Node<T>*newptr=new Node<T>(rhs.head->data);
		   temp1=rhs.head;
		   head=newptr;
		   temp2=newptr;
		     
		 	while(temp1->next!=0)
		 	{
		 	  temp1=temp1->next;
		 	  newptr=new Node<T>(temp1->data);
		 	  newptr->prev=temp2;
		 	  temp2->next=newptr;
		 	  temp2=temp2->next;
		 	}
		 	tail=temp2;
		 	
		 }
	void insertatfront(int n)
	{
		
		Node<T>*newptr=new Node<T>(n);
		if(head==0)
		{
			head=newptr;
			tail=newptr;
			
		}
		else
		{
			
			newptr->next=head;
			head->prev=newptr;
			head=newptr;
			
		}
	}
	
	void insertatlast(int n)
	{
		Node<T>*newptr=new Node<T>(n);
		
		if(tail==0)
		{
			
			tail=newptr;
			
			
		}
		else
		{
			
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
	void removefromhead()
	{
		
		if(head==tail)
		{
			delete head;
			head=tail=NULL;
			
			
		}
	else	if(head!=0)
		{
		  Node<T>*temp;
		  temp=head;
		  head=temp->next;
		  head->prev=0;
		  temp->next=0;
		  delete temp;
		  temp=0;
	    	}
}
 	
 	
	void removefromtail()
	{
		
		if(head==tail)
		{
			delete tail;
			head=tail=NULL;
			
			
		}
	else if(tail!=0)
		{
		  Node<T>*temp;
		  temp=tail;
		  tail=temp->prev;
		  tail->next=0;
		  temp->prev=0;
		  delete temp;
		  temp=0;
	    	}
}

        void reversing(){ 
//            Node<T> *temp = NULL;    
//            Node<T> *current = head;  
//            while (current !=  NULL)  
//{  
//             temp=current->prev;
//             current->prev=current->next;
//             current->next=temp;
//             current=current->prev;
//          
//          
//          
//            }        
//            if(temp != NULL ) { 
//               head = temp->prev;  
//            }
//			temp=head;
//			while(temp->next!=0)
//			{
//			  temp=temp->next;	
//				
//				
//			}
//			tail=temp; 
       Reverselist(head);
       
       
        }  
		
		void Reverselist(Node<T>*current)
		{
			if(current->next==0)
			{
				head=current;
				head->prev=0;
				return;
		    }
		    Reverselist(current->next);
		    Node<T>*temp;
		   if(current->prev==NULL)
		    tail=current;
		    temp=current->next;
		    
		    temp->next=current;
		   
		    current->prev=temp;
		    
		    current->next=NULL;
		} 
	
	~DLL()
	{
	   deleteall();	
	 
	}
	
	
	


 	
 	
 };

 
 int main()
 {
 	DLL<int>obj1;
	obj1.insertatfront(3);
 	obj1.insertatfront(2);
 	obj1.insertatfront(1);
 	obj1.insertatlast(4);
 	obj1.insertatlast(5);
 	
 	cout<<"\nObject 1 from head:\n";
 	obj1.printfromhead();
 	cout<<"\nObject 1 from tail:\n";
 	obj1.printfromtail();
 	
 	DLL<int>obj2(obj1);
 	cout<<"\nObject 2 from head:\n";
 	obj2.printfromhead();
    cout<<"\nObject 2 from tail:\n";
 	obj2.printfromtail();
 	
 	
 	cout<<"\nRemoving object 2 from head and tail\n";
    obj2.removefromhead();
	obj2.removefromtail();
	obj2.printfromhead();	
	
	cout<<"\nAfter Reversing object1:\n";
	obj1.reversing();
	obj1.printfromtail();
 	
 	
 }
