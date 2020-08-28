#include<iostream>
#include<cstring>
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
	
	
};



int main()
{
	DynamicSafeArray D1;
	DynamicSafeArray D2(5);
    D2<<cout;
    D2>>cin;
    DynamicSafeArray D3(D2);
    D2<<cout;
    D2[1]=100;   
    D2<<cout;
    D1=D3;
    D1<<cout;
    D2.Resize(10);
    D2<<cout;
	
	
}

