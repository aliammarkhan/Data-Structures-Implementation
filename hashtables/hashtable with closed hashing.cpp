#include<iostream>
using namespace std;
template<typename T>
class hashtable;

#define p 7
//hash table using open addressing(closed hashing)
template<typename T>
class DynamicSafeArray
{
	
  	T   *data;
		int size;
	public:	
	 DynamicSafeArray()
	 {
	 	data=0;
	 	size=0;
	 }
	 DynamicSafeArray(int s)
	 {
	 	size=s;
	 	data=new T[s];
	 

	 }
	 
 
 
	
	~ DynamicSafeArray()
	{
	    if(data!=0)
		delete[]data;
		data=0;	
		
	}
	void Resize(int s)
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
	
	friend class hashtable<T>;
};
template<typename T>
class hashtable
{
	DynamicSafeArray <T>*Data;
	int size;
	public:
	
	hashtable(int n)
	{
		Data=new DynamicSafeArray<T>(n);
		size=n;
		for(int i=0;i<size;i++)
		 Data->data[i]=-1;
		
	}
	
	int HASH1(int n)
	{
		
		return(n%size);
		
		
	}
	
	int HASH2(int n)
	{
	
       return(p-(n%p));		
     }
     
     void insert1(T key) //uses duble hash
     {
     	int i=1;
     	int index=HASH1(key);
     	if(Data->data[index]==-1)
     	{
             Data->data[index]=key;
			 return;		
        }
     
        while(1)
        {
        	
   
        	index=((HASH1(key)+i*HASH2(key))%size);
        	
        if(Data->data[index]==-1)
     	{
             Data->data[index]=key;
			 break;		
        }
        i++;
    }
  }
  	    void insert2(T key) //uses linear probing
     {
     	int i=1;
     	int index=HASH1(key);
     	
     	if(Data->data[index]==-1)
     	{
             Data->data[index]=key;
			 return;		
        }
        
        while(1)
        {
         
        	index=(HASH1(key)+i)%size;
        	
        if(Data->data[index]==-1)
     	{
             Data->data[index]=key;
			 return;		
        }
        i++;
        
			
   	}
   }
  	  	    void insert3(T key) //uses Quadratic probing
     {
     	int i=1;
     	int index=HASH1(key);
     	
     	if(Data->data[index]==-1)
     	{
             Data->data[index]=key;
			 return;		
        }
        
        while(1)
        {
         
        	index=(HASH1(key)+(i*i))%size;
        	
        if(Data->data[index]==-1)
     	{
             Data->data[index]=key;
			 return;		
        }
        i++;
        	
        	
  	}
        
 }
     	void print()
     	{
     		
     		for(int i=0;i<size;i++)
     		{
     			cout<<Data->data[i]<<endl;
     			
     			
			 }
    }
     	
     	
     	
     	
	 
			
	
	
	
};

int main()
{	int array[13]={345,1005,5667,1245,6788,5678,1234,785,2456,456,567,564,5689};

 hashtable<int> h1(13),h2(13),h3(13);
 
 for(int i=0;i<13;i++)
 {
 	h1.insert1(array[i]);
 	
 }
 cout<<"\nAfter double hashing\n";
 h1.print();
 
   for(int i=0;i<13;i++)
 {
 	h2.insert2(array[i]);
 	
 }
 cout<<"\nAfter linear probing\n";
 h2.print();
 
  for(int i=0;i<13;i++)
 {
 	h3.insert3(array[i]);
 	
 }
 cout<<"\nAfter quadratic probing\n";
 h3.print();
 
 
 
}
