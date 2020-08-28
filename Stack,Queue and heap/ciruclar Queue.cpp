#include<iostream>
#include<cstring>
using namespace std;
template<typename T>
class Queue;





template  <typename T>
class DynamicSafeArray
{
	public:
	     T *data;
		int size;
		
	 DynamicSafeArray()
	 {
	 	data=0;
	 	size=0;
	 }
	 DynamicSafeArray(int s)
	 {
	 	size=s;
	 	data=new T[s];
	 	memset(data,0,sizeof(T)*size);
	 }
	 
	  DynamicSafeArray (const  DynamicSafeArray &obj)
	  {
	  	  size=obj.size;
		  data=new T[size];
		  copy(obj.data,data+size,data);
	  	   
	}
     T &operator [](int i)const
	{
		
				return data[i];
		
	}
	  T &operator [](int i)
	{
		
				return data[i];
		
	}
	
	 


 
	
	~ DynamicSafeArray()
	{
	    if(data!=0)
		delete[]data;
		data=0;	
		
	}
	void Resize(int s)
	{
		  if(s>size)
		  {
		  	int tempsize=size;
		  	int *temp=new T[size];
		  	copy(data,data+size,temp);
		  	delete[]data;
		  	size=s;
		  	data=new T[size];
		  	copy(temp,temp+size,data);
		  	for(int i=tempsize;i<size;i++)
		  	  data[i]=0;
		}
        		
		
   }
	

	
};

template <typename T>

class Queue
{
	
   DynamicSafeArray <T> *Data;
	int front;
	int rear;
	
	public:
	
	
	


Queue()
{
	Data=0;
	Data=0;
	front=0;
	
	
	
}
Queue(int n)
{
	
	Data=new  DynamicSafeArray <T> (n);
    front =-1;
	rear=-1;	
	
	
}

void enqueue(T n)
{
	
	

	
   if(isfull())
   
	{
		cout<<"\nStack is Full\n";
		return;
	}
	if(front==-1)
	front++;

	{
		rear=(rear+1)%capacity();
        (*Data)[rear]=n;		
		
	}
	
	
}
T dequeue()
{
	T var;
	if(isempty())
	{
	cout<<"\n\nQueue is empty\n\n";
       
   }
	else
	{
		var=(*Data)[front];
		front=(front+1)%capacity();
	
		
	  return var;
		
	}
	
}

int capacity()
{
  
  return
    Data->size;	
	
	
}

bool isempty()
{
	if(front==-1&&rear==-1)
	return true;
	
}
bool isfull()
{
	
	if((rear+1)%capacity()==front)
	return true;
	else
	return false;
	
	
	
}

T Front()
{
		if(isempty())
	{
	cout<<"\n\nQueue is empty\n\n";
       
   }
   else
   return Data[front];
	
	
}

void print()
{
	int i;
	for( i=front;i!=rear;i=(i+1)%capacity())
	{
		cout<<(*Data)[i]<<" ";
	}
	cout<<(*Data)[i]<<" ";
	
	
	
}
};

int main()
{

   int var;
   
   
      Queue <int>q1(5);
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);
    q1.dequeue();
    q1.enqueue(6);
    q1.print();
      
      
      
   
 
  
  


	
}

