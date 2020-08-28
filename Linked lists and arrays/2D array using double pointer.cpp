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
   	T **data;
   	int row,col;
   	public:
   	DynamicSafeArray()
   	{
   	   data=0;
		row=0;
	
		col=0;
		
	}

   DynamicSafeArray(int nrow,int ncol)
   {
   	    row=nrow;
   	    col=ncol;
   	     
   	    data=new T*[row];
   	    for(int i=0;i<row;i++)
   	    data[i]=new T[col];
   }
   DynamicSafeArray(const DynamicSafeArray<T>&rhs)
   {
       row=rhs.row;
	   col=rhs.col;	
	    
	    data=new T*[row];
   	    for(int i=0;i<row;i++)
   	    data[i]=new T[col];
   	    for(int i=0;i<row;i++)
	   copy(rhs.data[i],rhs.data[i]+col,data[i]);
	
    }
	DynamicSafeArray &operator =(const DynamicSafeArray<T>&rhs)
	{
		if(this!=&rhs)
		{
		for(int i=row-1;i>=0;i--)
		{
			if(data[i]!=0)
			delete[]data[i];
		}
		delete[]data;
	    row=rhs.row;
	    col=rhs.col;	
     
	    data=new T*[row];
   	    for(int i=0;i<row;i++)
   	    data[i]=new T[col];
   	    for(int i=0;i<row;i++)
	   copy(rhs.data[i],rhs.data[i]+col,data[i]);
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
	    
		return data[i][j];
	    }
}

  bool operator ==(DynamicSafeArray<T> &rhs)
  {
  	  
  	   if(row!=rhs.row||col!=rhs.col)
  	      return false;
	   
  	   
  	   for(int i=0;i<row;i++)
  	   {
  	      for(int j=0;j<col;j++)
			{
			   if(data[i][j]!=rhs.data[i][j])
			   {
			   
			   return false;
		       }
			  	
			} 	
	  }
	  return true;
  	  
}
bool operator !=(DynamicSafeArray<T> &rhs)
  {
  	  
  	    if(row*col!=rhs.row*rhs.col)
  	   return true;
  	
  	   for(int i=0;i<row;i++)
  	   {
  	      for(int j=0;j<col;j++)
			{
			   if(data[i][i]==rhs.data[i][j])
			   return false;	
			  	
			} 	
	  }
	  return true;
  	  
}
  void Resize(int a,int b)
  {
  	int temprow=row,tempcol=col;
  	      if(a>col&&b>row)
			{
			
		     int **temp=new T*[row];
   	        for(int i=0;i<row;i++)
   	        temp[i]=new T[col];
   	        
   	      for(int i=0;i<row;i++)
	   copy(data[i],data[i]+col,temp[i]);
   	     
			  
		
		for(int i=row-1;i>=0;i--)
		{
			if(data[i]!=0)
			delete[]data[i];
		}
	    
		delete[]data;
			  
			  row=a;
			  col=b;
			
		data=new T*[row];
   	    for(int i=0;i<row;i++)
   	    data[i]=new T[col];
			  
			for(int i=0;i<temprow;i++)
	   copy(temp[i],temp[i]+tempcol,data[i]);
   	     
			
		for(int i=temprow-1;i>=0;i--)
		{
			if(temp[i]!=0)
			delete[]temp[i];
		}
	    
		delete[]temp;
			  
			for(int i=temprow;i<row;i++)
			for(int j=tempcol;j<col;j++)
			data[i][j]=0;
			                   
  	
  	
  }
}
~ DynamicSafeArray()
{
	
	for(int i=row-1;i>=0;i--)
	{
		 if(data[i]!=0)
		 delete []data[i];
		
		
	}
	delete []data;
	
	
	
}
 
friend ostream& operator <<(ostream&out,DynamicSafeArray<T>&obj)
{
//	out<<obj.row<<" "<<obj.col<<endl;
	for(int i=0;i<obj.row;i++)
	for(int j=0;j<obj.col;j++)
	 out<<obj.data[i][j]<<endl;
	
	return out;
}

friend istream& operator >>(istream&in,DynamicSafeArray<T>&obj)
{
	
	for(int i=0;i<obj.row;i++)
	for(int j=0;j<obj.col;j++)
	 in>>obj.data[i][j];
	
	return in;
}
};






int main()
{
//	DynamicSafeArray<int>DSA1(3,3);
//	cout<<"Enter elements:";
//	cin>>DSA1;
//	cout<<"\nElements of DSA1\n";
//	cout<<DSA1;
// 
//	copy constructor call
//	DynamicSafeArray<int>DSA2(DSA1);
//	cout<<"\nElements of DSA2\n";
//    cout<<DSA2;
//	
//		
//		DynamicSafeArray<int>DSA3;
//		DSA3=DSA2; //assignment operator
//	cout<<"\nElements of DSA3\n";
//    cout<<DSA3;
//    == and !=operator overloading
//    cout<<"\nOverloading of == and !=\n";
//  bool x= DSA1==DSA2;
//  cout<<x<<endl;
//  x=DSA1!=DSA2;
//  cout<<x<<endl;
//  
//  try{
//  	
//   DSA2(5,5)=14; //will throw exception 	
//  	
//  }
//  catch( ArrayIndexOutOfBoundException ex)
//  {
//  	cout<<ex.what();
//  }
//   overloading of()
//  cout<<"\nDSA(2,2)=";
//  cout<<DSA2(2,2)<<endl;
//  
// cout<<"\nElements of DSA2 afer Resize\n";
//  DSA2.Resize(4,4);
//  cout<<DSA2;
//		
//		ofstream infile("2D ARRAY USING double POINTER.txt");
//		infile<<DSA3<<endl;
//		infile.close();
		
	  ifstream outfile("A1P1IO1.txt");
	  int i,j;
	  outfile>>i;
	  outfile>>j;
		DynamicSafeArray<char>DSA5(i,j);


		outfile>>DSA5;
		outfile.close();
		cout<<DSA5;
		
		
		return 0;
}
