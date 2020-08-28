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
	
  DynamicSafeArray <T>*Data;
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
	
	Data=new DynamicSafeArray<T>(n);
    front =-1;
	rear=-1;	
	
	
}

void enqueue(T n)
{
	rear++;
	

	if(front=-1)
	front++;
   if(rear==Data->size)
	{
		cout<<"\n\nQueue is full!!\n\n";
		
}
	else
	{
		Data->data[rear]=n;
		
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
	   var=Data->data[front];
	   front++;
	   if(front==Data->size)
	   front=rear=-1;
	   
	   return var;
	}		
}

int size()
{
	return((rear-front)+1);
	
	
}
	bool isempty()
	{
		if(front==-1&&rear==-1)
		return true;
		else 
		return false;
	}

T Front()
{
		if(front==-1)
	{
	cout<<"\n\nQueue is empty\n\n";
       
   }
   else
   return Data->data[front];
	
	
}

void print()
{
	
	for(int i=front;i<=rear;i++)
	{
		cout<<Data->data[i]<<" ";
	}
	
	
	
}


};

int main()
{
  Queue<int>q1(100);
   
   for(int i=1;i<=10;i++)
   {
        q1.enqueue(i);   
  }
  q1.print();
  cout<<"\nSize:"<<q1.size()<<endl;
  
     for(int i=0;i<10;i++)
   {
       cout<<"\n\nFront element:"<<q1.Front(); 
        cout<<"\nSize:"<<q1.size();
	 
	int  var=q1.Dequeue();
	  cout<<"\npoped element:"<<var;   
  }

  
  


	
}

