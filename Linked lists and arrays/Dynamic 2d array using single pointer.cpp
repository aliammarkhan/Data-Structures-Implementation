
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

class ArrayIndexOutOfBoundException {
public:
	ArrayIndexOutOfBoundException()
		: message ("Array Index Out of Bound\n") {}
	~ArrayIndexOutOfBoundException() { /*delete message; */}
	const string what() const { return message; }
private:
	string message;
};

template <typename T>
class DynamicSafeArray
{
   	T *data;
   	int row,col,size,offset;
   	public:
   	DynamicSafeArray()
   	{
   	   data=0;
		row=0;
		size=0;
		col=0;
		offset=0;	
	}

   DynamicSafeArray(int nrow,int ncol)
   {
   	   offset=0;
   	    row=nrow;
   	    col=ncol;
   	     size=row*col;
   	    data=new T[size];
   }
   DynamicSafeArray(const DynamicSafeArray<T>&rhs)
   {
       row=rhs.row;
	   col=rhs.col;	
	    size=row*col;
	   data=new T[size];
	   copy(rhs.data,rhs.data+size,data);
	
    }
	DynamicSafeArray &operator =(const DynamicSafeArray<T>&rhs)
	{
		if(this!=&rhs)
		{
		delete []data;
      	data=0;
	    row=rhs.row;
	    col=rhs.col;	
        size=row*col;
	   data=new T[size];
	   copy(rhs.data,rhs.data+size,data);
	   return *this;
		}
		else
		{
			cout<<"Both are same objects\n";
			return *this;
		}
		
	}
  int &operator()(int i,int j)
  {
  	  if(i<0||i>row-1||j>col-1||j<0)
  	  {
  	  
  	  	ArrayIndexOutOfBoundException exception;
  	  	throw exception;
  	  	
  	  	  
	}
		else
		{
	    offset=(i*col)+j;
		return data[offset];
	    }
}

  bool operator ==(DynamicSafeArray<T> &rhs)
  {
  	  
  	   if(size!=rhs.size||this ==&rhs)
  	   return false;
  	
  	 for(int i=0;i<size;i++)
  	 {
  	 	
  	 	  if(data[i]!=rhs.data[i])
  	 	  return false;
  	 	
  	 	
	 }
	 return true;
}
bool operator !=(DynamicSafeArray<T> &rhs)
  {
  	  
  	   if(size!=rhs.size)
  	   return true;
  	
  	 for(int i=0;i<size;i++)
  	 {
  	 	
  	 	  if(data[i]==rhs.data[i])
  	 	  return false;
  	 	
  	 	
	 }
	 return true;
}
  void Resize(int i,int j)
  {
  	      if(i>col&&j>row)
			{
				int tempsize=size;
		      int *temp=new T[size];
		      copy(data,data+size,temp);
			  delete[]data;
			  data=0;
			  row=i;
			  col=j;
			  size=row*col;
			  data=new T[size];
			  copy(temp,temp+tempsize,data);
			  delete []temp;
			  temp=0;
			  	for(int i=tempsize;i<size;i++)
		  	  data[i]=0;
				
			}                       
  	
  	
  }
 
friend ostream& operator <<(ostream&out,DynamicSafeArray<T>&obj)
{
	out<<obj.size<<endl;
	for(int i=0;i<obj.size;i++)
	 out<<obj.data[i]<<endl;
	
	return out;
}

friend istream& operator >>(istream&in,DynamicSafeArray<T>&obj)
{
	
	for(int i=0;i<obj.size;i++)
	 in>>obj.data[i];
	
	return in;
}
};






int main()
{
	DynamicSafeArray<int>DSA1(3,3);
	cout<<"Enter elements:";
	cin>>DSA1;
	cout<<"\nElements of DSA1\n";
	cout<<DSA1;
 
	//copy constructor call
	DynamicSafeArray<int>DSA2(DSA1);
	cout<<"\nElements of DSA2\n";
    cout<<DSA2;
	
		
		DynamicSafeArray<int>DSA3;
		DSA3=DSA2; //assignment operator
	cout<<"\nElements of DSA3\n";
    cout<<DSA3;
    //== and !=operator overloading
    cout<<"\nOverloading of == and !=\n";
  bool x= DSA1==DSA2;
  cout<<x<<endl;
  x=DSA1!=DSA2;
  cout<<x<<endl;
  
  try{
  	
   DSA2(5,5)=14; //will throw exception 	
  	
  }
  catch( ArrayIndexOutOfBoundException ex)
  {
  	cout<<ex.what();
  }
  // overloading of()
  cout<<"\nDSA(2,2)=";
  cout<<DSA2(2,2)<<endl;
  
  	cout<<"\nElements of DSA2 afer Resize\n";
  DSA2.Resize(4,4);
  cout<<DSA2;
		
		ofstream infile("2D ARRAY USING SINGLE POINTER.txt");
		infile<<DSA3<<endl;
		infile.close();
		
		return 0;
}
