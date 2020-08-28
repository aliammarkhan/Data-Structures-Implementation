#include<iostream>
#include<cstring>
#include<math.h>
using namespace std;

class DynamicSafeArray
{
	
		int *data;
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
	 	data=new int[s];
	 	memset(data,0,sizeof(int)*size);
	 }
	 
	  DynamicSafeArray (const  DynamicSafeArray &obj)
	  {
	  	  size=obj.size;
		  data=new int[size];
		  copy(obj.data,data+size,data);
	  	   
	}
	int &operator [](int i)const
	{
		
				return data[i];
		
	}
		int &operator [](int i)
	{
		
				return data[i];
		
	}
	
	 
	DynamicSafeArray &operator =(const DynamicSafeArray &obj)
	{
	     if(this!=&obj)
		 {
		    delete []data;
		    data=new int[obj.size];
		    size=obj.size;
			
			copy(obj.data,data+size,data);
			return *this;
			 	
		}	
		else return *this;
	  	
	}
istream &operator >>(istream &input)
 {
 	for(int i=0;i<size;i++)
 	input>>data[i];
 		
    
    return input ;
 }
 ostream &operator <<(ostream &output)
 {
 	for(int i=0;i<size;i++)
 	output<<data[i];
 		
    cout<<endl;
    return output ;
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
		  	int *temp=new int[size];
		  	copy(data,data+size,temp);
		  	delete[]data;
		  	size=s;
		  	data=new int[size];
		  	copy(temp,temp+size,data);
		  	for(int i=tempsize;i<size;i++)
		  	  data[i]=0;
		}
        		
		
   }
	
	friend class Heap;
};

class Heap
{
	 DynamicSafeArray *Data;
	 int capacity;
	 int Size;
	 
	public:
	Heap()
	{
       Data=0;
	   capacity=0;		
	   Size=-1;
	}
   Heap(int s)
   {
   	 Data=new  DynamicSafeArray(s);
   	 capacity=s;
   	 Size=-1;
   }
   void insert(int n)
   {
   	  int temp,i;
   	    Size++;
   	    temp=n;
   	    
   	    if(Size==capacity)
   	    {
   	    	Data->Resize(capacity+1);
   	    	capacity=capacity+1;
 	    	
   	    }
   	    for (i=Size;i>0;i=(i-1)/2)
   	    {
 
   	    
               if((*Data)[(i-1)/2]<temp)
			   {
			   	  (*Data)[i]=(*Data)[(i-1)/2];
			   	  
			
			   	
			  } 
			  else
			  break;
		}
		(*Data)[i]=temp;
	    
   	
   }
   
   int Remove()
   {
   	

	    int tempdata=(*Data)[0],i;
	    int temp;
	  temp=(*Data)[0]=(*Data)[Size];
	   Size--;
	   int index;
	   for( i=0;i<Size;)
	   {
	   	  if((*Data)[(2*i)+1]>temp||(*Data)[(2*i)+2]>temp)
	   	  {
	   	      	index=max((2*i)+1,(2*i)+2);
    		  (*Data)[i]=(*Data)[index];
    		 	i=index;    
    	  }
    	     else
	         break;
	   	
	   }
	
	   (*Data)[i]=temp;
	   return tempdata;
	  	
	
		}	

   	
   	
   	
   	
   	
   	
   	
   	
   	
   	
   	
   
   
void heap_sort()
{
	
	
	
	
	
	
	
	
	
	
	
}
   	 
void print()
{
	
	for(int i=0;i<=Size;i++)
	cout<<(*Data)[i]<<" ";
	
}


};

int main()
{
	Heap h1(100);
	h1.insert(50);
	h1.insert(20);
	h1.insert(30);
	h1.insert(10);
	h1.insert(12);
	h1.insert(15);
	h1.insert(10);
	h1.insert(8);
	h1.insert(7);
	h1.insert(1);
	h1.insert(3);
	h1.insert(7);
	h1.insert(9);
    h1.print();
	cout<<endl<<endl;
	
	for(int i=0;i<13;i++)
	cout<<h1.Remove()<<" ";
	

}

