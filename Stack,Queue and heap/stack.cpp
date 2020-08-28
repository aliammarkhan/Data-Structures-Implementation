#include<iostream>
#include<cstring>
using namespace std;
class Student
{
	
	public:
		string name;
		int no;
		

		
		 Student()
			 {
			 	name="";
			 	no=0;
			 	
			 }
			
		
			 Student(string a,int b)
			 {
			 	name=a;
			 	no=b;
			 	
			 }
			 void print()
			 {
			 	cout<<name<<endl<<no<<endl;
			 }
		
			

			
	};



template<typename T>
class stack;

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
	 	memset(data,0,sizeof(int)*size);

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
	
	friend class stack<T>;
};

template<typename T>
class stack
{
	
	public:
	int top;
	 int *Data;


	

		stack()
		{
			top=-1;
			Data=0;
			
			
		}
		stack(int n)
		{
			Data=new int (n);
			top=-1;
			
			
		}
		void push(int n)
		{
			top++;
		
			Data[top]=n;
			
		}
		int pop()
        {
        	int var;
        	var=Data[top];
        	top--;

        	return var;
         	
        	
		}
		bool isempty()
		{
			if(top==-1)
            return true;
			return false;			
			
		}
			void peek()
		{
			if(top!=-1)
			cout<<Data[top]<<endl;
			else
			cout<<"\n\nStack is empty\n\n";
			
			
		}
		void display()
		{
			for(int i=top;i>=0;i--)
			{
			   
			   cout<<Data[i]<<endl;	
				
			
			}
			
			
			
		}
			
	};
//
//class stackframe_fac
//{
//	int parameter;
//	int result;
//	public:
//	stackframe_fac()
//	{
//		parameter=1;
//	
//	}
//	
//	void set_parameter(int x)
//	{
//		parameter=x;
//		
//	}
//
//		int get_parameter()
//	{
//		return parameter;
//		
//	}
//
//	
//
//	
//	
//};
//
//class stackframe_fib
//{
//	int parameter1;
//	int parameter2;
//	public:
//	stackframe_fib()
//	{
//		parameter1=1;
//		parameter2=1;
//	}
//	
//	void set_parameter1(int x)
//	{
//		parameter1=x;
//		
//	}
//	void set_parameter2(int x)
//	{
//		 parameter2=x;
//	}
//		int get_parameter1()
//	{
//		return parameter1;
//		
//	}
//	int get_parameter2()
//	{
//		return parameter2;
//	}
//};
//
//	int fib(int n)
//	{
//		
//		stack<stackframe_fib> st(n);
//		stackframe_fib obj;
//		int count=0;
//	
//	    	if(n==1||n==2)
//			return 1;
//	else
//	{
//		
//		int sum=0;
//		st.push(obj);
//	   while(count<n-2)	
//       {
//       	obj=st.pop();
//       	 sum=obj.get_parameter1()+obj.get_parameter2();
//       	 obj.set_parameter1(obj.get_parameter2());
//       	 obj.set_parameter2(sum);
//       	 st.push(obj);
//       	 count++;
//}		
//
//return sum;
//		
//		
//	}	
//	
//	
//		
//	}
//	
//	int factorial(int n)
//	{
//
//		stack<stackframe_fac>sts(n);
//		
//		stackframe_fac obj;		
//	
//		
//		
//		while(n!=0)
//		{
//		obj.set_parameter(n);
//			sts.push(obj);
//		
//			n--;
//		}
//		
//		int result=1;
//		
//		while(!sts.isempty())
//       {
//       
//         result=result*sts.pop().get_parameter();   	
//         
//       } 		
//		return result;
//		
//	}
//	
	


int main()
{
	
//	cout<<factorial(9)<<endl;
//	for(int i=1;i<=10;i++)
//	cout<<fib(i)<<" ";


stack<int>s2(19);



//	stack <int>s1(10);
//	
//	
//   for(int i=0;i<10;i++)
//	{
//		
//		s1.push(i);
//	}
//	cout<<"\nStack 1"<<endl;
//	s1.display();
//	
//		stack <int>s2(10);
//	
//   for(int i=10;i<20;i++)
//	{
//		
//		s2.push(i);
//	}
//	cout<<"\nStack 2"<<endl;
//	s2.display();
//	
//	s1.multipush(s2);
//	
//		cout<<"\nAfter multipush"<<endl;
//	cout<<"\nStack 1"<<endl;
//	s1.display();
//	cout<<"\nTop:";
//	 s1.peek();
//		
//	stack<int> s3;
//s3=	s1.multipop(10);
//		
//	cout<<"\nStack 3"<<endl;
//	s3.display()	;
//	
//		cout<<"\nStack 1"<<endl;
//	s1.display();
//		
////	cout<<"\nTop:";
////	s1.peek();
////	cout<<"\nCapacity:"<<s1.capacity();
////	cout<<"\nSize:"<<s1.size();
////	
////	int x=s1.pop();
////	cout<<"\npoped:"<<x;
////	
////	cout<<"\nCapacity:"<<s1.capacity();
////	cout<<"\nSize:"<<s1.size()<<endl;
////	s1.display();
////	cout<<"\nTop:";
////	s1.peek();
////	
////	
////	for(int i=0;i<9;i++)
////	s1.pop();
////	
////	cout<<"\nSize:"<<s1.size()<<endl;
////	s1.display();
////	
////	
	
}
