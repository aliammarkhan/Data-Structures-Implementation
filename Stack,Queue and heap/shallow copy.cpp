#include<iostream>
using namespace std;
template <typename T>
class node
{
	public:
	T info;
	node<T> *next;
	node()
	{
	//info=0;
	next=0;
    }	
    node(T d)
	{
	info=d;
	next=0;
    }	
    node(T d,node<T> *in)
	{
	info=d;
	next=in;
    }	
};
template <typename T>
class stack
{
	private:
	int size;
	node<T> *top;
	public:
	stack()
	{
	size=0;
	top=0;	
	}
	bool isempty()
	{
	if(top==0)
	{
		return true;
	}	
	else
	{
		return false;
			}		
   }
   
   void push(T value)
   { node<T> *temp1=new node<T>();
    temp1->info=value;
   	if(isempty())
   	{
   	top=temp1;	
    }
    else
    {
    	temp1->next=top;
    	top=temp1;
	}
    size++;
   }
   
   void pop()
   { node<T> *temp=new node<T>();
   	if(isempty())
   	{
   		cout<<"stack is empty"<<endl;
    }
    else
    {
    	temp->info=top->info;
    	top=top->next;
    	delete temp;
    
	}
	   size--;
   	
   }
   int getsize()
   {
   	return size;
   }
   
   void multipush()
   { int num;
   	cout<<"Enter number of entries:\t";
   	cin>>num;
   	T entry;
   	for(int i=0;i<num;i++)
   	{
   		cin>>entry;
   		push(entry);
   		size++;
   		
	}
   }
   
   void multipop()
   {
   	if(isempty())
   	cout<<"stack is empty<<endl";
   	else
   	{
   	while(size!=0)
	{
		pop();
	}	
	}
   }
   
   
   T returntop()
   {
   	if(isempty())
   	cout<<"stack empty<<endl";
   	else
   	{
   		return top->info;
	}
   }
   
   void viewstack()
   {
   	node<T> *temp2=new node<T>();
   	temp2=top;
   	while(temp2!=0)
   	{
   	cout<<temp2->info<<endl;
	   temp2=temp2->next;	
	}
	
   }
   void swap(node<T> *a,node<T> *b) 
{ 
    T temp = a->info; 
    a->info = b->info; 
    b->info = temp; 
} 
   
   void sort()
   {
   	int swapped, i; 
     node<T> *ptr1; 
     node<T> *lptr = NULL; 
  
   
    if (top == 0) 
        return; 
  
    do
    { 
        swapped = 0; 
        ptr1 = top; 
  
        while (ptr1->next != lptr) 
        { 
            if (ptr1->info > ptr1->next->info) 
            {  
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
   }
   
	
};

int main()
{
	stack<string> stc;
	stc.multipush();
	stc.sort();
    stc.viewstack();
}s
