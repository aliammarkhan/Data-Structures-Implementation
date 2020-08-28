#include<iostream>
using namespace std;

template<typename T>
class hashtable;



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
  Node(const int n,Node *ptr=0)
  {
  	   data=n;
  	   next=ptr;

  }
  friend class hashtable<T>;
};



template<typename T>
class hashtable
{
	
	private:
	 
	 Node<T> **array;

	 int size;
	 public:
	
	 hashtable(int n)
	 {
           size=n;	 	
	     array=new Node<T>*(0);
   	    for(int i=0;i<size;i++)
   	    array[i]=new Node<T>(0);
   	    
   	     for(int i=0;i<size;i++)
   	     array[i]=0;
   	     
   	}
	 
	 int HASH(int n)
	 {
	 	
	 	return(n%size);
	 }
	 
	 
	 
	 void insert(int key)
	 {
	 	Node<T>*newptr=new Node<T>(key);
	 	int index=HASH(key);
         
		 if(array[index]==0)
		 {
		 
		 	 
		 	array[index]=newptr;
		 	
		 }
		 else
		 {
		 	
		    Node<T>*temp=array[index];
		   
		    while(temp->next!=NULL)
		    temp=temp->next;
		    
		    temp->next=newptr;
					
		 
		        	
		 }	 	
          
	 	
	}

	
	void display()
	{
		Node<T>*temp;
		for(int i=0;i<size;i++)
		{
			cout<<i<<"->";
			if(array[i]!=0)
	        temp=array[i];
		    else
		    { cout<<endl;
		     continue;
		     }
	
		    
			while(temp->next!=NULL)
			{
				
				cout<<temp->data;
				cout<<"->";
				temp=temp->next;
				
				
				
			}
	    	cout<<temp->data;
			cout<<endl;
		
			
			
		}
		
		
		
		
	}
};

int main()
{
	
	hashtable <int>h1(10);
	h1.insert(1);
	h1.insert(2);
	h1.insert(3);
	h1.insert(4);
	h1.insert(5);
	h1.insert(7);
	h1.insert(1);
		h1.insert(50);
	
	h1.display();
	
	
	
	
	
	
}

