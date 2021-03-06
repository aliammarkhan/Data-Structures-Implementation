#include<iostream>
using namespace std;

class Node
{
	public:
	 int data;
	 Node *next;

	 

		
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
  
  Node* get_address(Node *ptr)
  {
  	  return ptr;
  	
  }
};


class SinglyLinkedList
{
	
	private:
		Node *head;
		int size;
	  public:
	  	
	public:
		 SinglyLinkedList()
		 {
		 	
		 	head=0;
		 	size=0;
		}

  void intilize_head(Node*ptr)
  {
  	
  	head=ptr->get_address(ptr);
}
  void insertatfirst(const int n)
  {
  	
  	 Node *newptr;
  	 newptr=new Node(n);
  	if(head==0)
  	head=newptr;
  	else
  	newptr->next=head;
  	
  	head=newptr;
  	 size++;
  }	
  
  void insertatlast(const int  n)
  {
  	
  	
  	Node *newptr;
    newptr =new Node(n);
	Node *temp=0;
	temp=head;
	while(temp->next!=0)
	{
	  temp=temp->next;	
		
	}  	
	
	temp->next=newptr;
	temp=0;
	 size++;
  }
  
  
  int removefromfront()
  {
  	
  	Node *temp;
  	temp=head;
  	
  	if(head!=0)
  	head=head->next;
  	
  	temp->next=0;
   int n= temp->data;
   delete temp;
   temp=0;
    size--;
   return n;
  	
  }
  int removefromlast()
  {
  	 Node *temp,*prev; 
  	 temp=head;
  	 while(temp->next!=0)
  	 {
  	 	prev=temp;
  	   temp=temp->next;
  	 	
	}

	prev->next=0;
	prev=0;
int n= temp->data;
  delete temp;
  temp=0;
   size--;
  return n;
  	
  	
  }
  void display()
  {
  	Node *temp;
  	temp=head;
  	  while(temp->next!=0)
  	  {
  	     cout<<temp->data<<endl;
		  temp=temp->next;  	
  	  	
  	}
  	cout<<temp->data;
  	
  	temp=0;
  	}
  	
  	~SinglyLinkedList()
  	{
  	    deleteall();	
  		
  		
	}
	void deleteall()
	{
		if(head!=0)
		{
			Node *temp;
			temp=head;
		
		   while(head!=0)
		   {
		   	
		   	 head=head->next;
		   	 temp->next=0;
		   	 delete temp;
		   	 temp=head;
		 }
	}
		
}
SinglyLinkedList(const SinglyLinkedList &rhs)
{
	size=rhs.size;
	Node *newptr=0,*old;
	this->head=0;
    newptr=new Node(rhs.head->data);
    this->head=newptr;
    old=this->head;
    Node *temp;
    temp=rhs.head;

   do
    {
     temp=temp->next;
     
    newptr=new Node(temp->data);
    old->next=newptr;
    old=newptr;
	   
	   
    }while(temp->next!=0);
    
}

SinglyLinkedList& operator =(SinglyLinkedList &rhs)
{
	
	if(this!=&rhs)
	{
	   deleteall();	
	   
	   	size=rhs.size;
	Node *newptr=0,*old;
	this->head=0;
    newptr=new Node(rhs.head->data);
    this->head=newptr;
    old=this->head;
    Node *temp;
    temp=rhs.head;

   do
    {
     temp=temp->next;
     
    newptr=new Node(temp->data);
    old->next=newptr;
    old=newptr;
	   
	   
    }while(temp->next!=0);
		
	
	}
	
}

          void reverse()
		  {  
//            Node *current = head;  
//            Node *prev = NULL, *next = NULL;  
//            while (current != NULL)  {  
//                next=current->next;
//				current->next=prev;
//				prev=current;
//				current=next; 
//}  
//            head = prev;  
              reverselist(head);
}
void reverselist(Node *current){ //by recursion on stack
			
			if(current->next==0){
			head=current;
			return;
			}
			
			reverselist(current->next); //this will create stack till second last node and then run from second last to first
			
			Node* temp; 
			temp=current->next; //to hold address of last node
			temp->next=current; //last node ko second last node ka address de diya
			current->next=0;  //second last node ko null de diya
			
			//ab jb third last ke liye chalay ga to null ki value fourth last pr shift ho jae gi aur link third last to fourth last bn jae ga and so on
}
   int getsize()
   
   {
   return size;
   }

   void breaklist(int i,int j,SinglyLinkedList &obj)
   {
   	
   	   if(i+j==size)
   	   {
   	   	int count=0;
   	   	  Node* temp;
   	   	  obj.head=0;
   	   	  temp=head;
   	   	  while(count<i-1)
   	   	  {
   	   	     temp=temp->next;
   	   	     count++;
   	   	 }
   	   	obj.head=temp->next;
   	   	 temp->next=0;
   	   	 temp=0;
   	   	 obj.size=j;
   	   	 size=i;
	 }
	 else
	 cout<<"\nEnter valid breaking parameters\n";
   	
   	
   }
   
   void bubble_sort()
   {
    Node *temp;
   
    int var;
     for(int round=0;round<size;round++)
	 {
	 	 temp=head;
	     for(int i=0;i<size-round-1;i++)
		 {
		 	
		 	if(temp->data > temp->next->data)
		 	{
		 	   var=temp->data;
			  temp->data=temp->next->data;
			  temp->next->data=var;
			  
		 	   	
			}
				
	   temp=temp->next;
	
		 	
		 	
		 }	
	}   	
   	
}


 
	
  	
  


  	



};
	
	
	
	




int main()
{




	
	SinglyLinkedList obj1;

	obj1.insertatfirst(4);
	obj1.insertatfirst(4);
	obj1.insertatlast(5);
	obj1.insertatfirst(1);
	obj1.insertatlast(2);

	obj1.bubble_sort();
	obj1.display();
	
	
}
