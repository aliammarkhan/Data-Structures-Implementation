#include<iostream>
#include<stdio.h>
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
		
			

			
	};

template <typename T>

class Dynamic2darry{
	private :

	int nrow;

	public :
		T *Data;
		Dynamic2darry(){
			nrow = 0;
			Data = 0;
			
		}
		Dynamic2darry(int r){
			nrow = r;
				Data = new T[nrow];
			
		}
		Dynamic2darry(const Dynamic2darry &rhs){
				nrow = rhs.nrow;
				Data = new T[nrow];
			
			for(int i =0 ; i<nrow;i++){
				memcpy(Data,rhs.Data,sizeof(T)*nrow);
			}
		}
		
		
		Dynamic2darry& operator=(const Dynamic2darry &rhs){
			if(this != &rhs){
			
			nrow = rhs.nrow;
			Data = new int[nrow];
			for(int i =0 ; i<nrow;i++){
				memcpy(Data,rhs.Data,sizeof(T)*nrow);
			}
		
		}
		else return *this;
			
		}
		
				
		bool operator==( Dynamic2darry &rhs){
			if(nrow == rhs.nrow){
			 	for(int i = 0 ;i<nrow ; i++){
					if(Data[i]!=rhs.Data[i]){
					return false;
					break ;
					}
				}
				
				return true ; 
			}else //if(nrow == rhs.nrow && ncol == rhs.ncol)
				return false; 
		}
		
		bool operator!=( Dynamic2darry &rhs){
			if(nrow != rhs.nrow ){
				for(int i = 0 ;i<nrow ; i++){
					if(Data[i]!=rhs.Data[i]){
						return true;
						break ;
					}
				}
				return false ;
			}else return true; //if(nrow != rhs.nrow && ncol != rhs.ncol)
		}	
		
		T operator[](int i){
		if(i<nrow){
			return Data[i];
		}
		else
		cout<<"OutOfbound"<<endl;
		}
		
		~Dynamic2darry(){
			if(Data!=0){
			delete[] Data;
			}
		}
};
	template <typename T>	
	class STACK{
		private:

		int size;
		int top;
		public:
		Dynamic2darry<T> *Data;
		STACK(){
			Data->Data= new Dynamic2darry<T>(); 
			top=0;
			size=0;
		}
		STACK(int siz){
			size=siz;
			Data= new Dynamic2darry<T>(size);
			top=-1; 
		}
		
		void PUSH(T element){
		
			if(top < size-1){
			top++;
			Data->Data[top]=element;	
			}else{
				cout<<"Stack is full"<<endl;
			}
		}
		T pop(){
		
			if(top>-1){
				top--;
				return Data->Data[top+1];
			}else{
				cout<<"Stack is Empty"<<endl;
				;
			}
			
		}
		
		void multipush( STACK &rhs){
		
			if(rhs.size+top<size){
				for(int i=0;i<rhs.size;i++){
					top++;
		
					Peek(top+1);
				
				}
				
				for(int i=0;i<rhs.size;i++){
					Data->Data[top]=rhs.pop();
					top--;
				}
				top=top+rhs.size;
				
			}else{
				cout<<"STACK IS FULL"<<endl;
			}
		}
		STACK<T> multipop(int siz){
			STACK<T> *temp;
		
			if(top+1>=siz){
			
			
			temp=new STACK(siz);			
				
			temp->top =temp->top + siz  ;
				for(int i=0;i<siz;i++){
					temp->top --;
					temp->PUSH(this->pop());
					temp->top --;
				}
				
				temp->top =temp->top + siz ;
				 	
							return *temp;
			
			}
			
		}
	int  gettop(){
		return top+1;
	}
	void Peek(int i){
		if(i>=0&&i<=top){
		cout<<Data->Data[i];	
		}
	
	}
	
};

class STACK_Farme_fac{
	private:
		int Parameter;
		int result;
	public: 	 
	STACK_Farme_fac(){
		Parameter=0;
		result=0;
	}
	
	~STACK_Farme_fac(){
		Parameter=0;
		result=0;
	}
	
	void setParameter(int P){
		Parameter=P;
	}
	int getParameter(){
		return Parameter;
	}
	
	void setResult(int r){
		result=r;
	}
	int getResult(){
		return result;
	} 
	
};
//+++++++++++++++++++++++//
int fac(int n){
	STACK<STACK_Farme_fac> stack(n);
	STACK_Farme_fac obj;
	
	while(n!=0){
		if(n==1){
			obj.setParameter(1);
			obj.setResult(1);
		
		}else{
			obj.setParameter(n);
			obj.setResult(-1);
			stack.PUSH(obj);
		
		}
			n--;
	}
	int result =1;
	while(stack.gettop()!=0){	
	result=stack.pop().getParameter() * result;
	//-----=obj.parameter----- at top
	obj.setResult(result);
	
	}
	return obj.getResult();
	
}

/////////xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx//;


class STACK_Farme_facbonachi{
	private:
		int Parameterx;
		int Parametery;
		int result;
	public: 	 
	STACK_Farme_facbonachi(){
		Parameterx=0;
		Parametery=0;
		result=0;
	}
	
	~STACK_Farme_facbonachi(){
		Parameterx=0;
		Parametery=0;
		result=0;
	}
	
	void setParameterx(int x){
		Parameterx=x;
		
	}
	int getParameterx(){
		return Parameterx;
	}
	
	void setParametery(int y){
		Parametery=y;
	}
	int getParametery(){
		return Parametery;
	}
	
	void setResult(int r){
		result=r;
	}
	int getResult(){
		return result;
	} 
	
};

	

void fabonachi(int range){
	STACK<STACK_Farme_facbonachi> stack(range);
	STACK_Farme_facbonachi obj;
	while(range >=0){
		if(range == 0){
			obj.setParameterx(0);
			obj.setParametery(1);
			obj.setResult(0);
			
		}else{
			obj.setParameterx(-1);
			obj.setParametery(-1);
			obj.setResult(-1);
			stack.PUSH(obj);
		}
		range--;
	}
	int result=0;
	while(stack.gettop()!=0){
		cout<<obj.getResult()<<" ";
		result=obj.getParametery();
		obj.setParametery(obj.getParameterx()+obj.getParametery());
		obj.setParameterx(result);
		obj.setResult(result);
		stack.pop();
		
	}
	cout<<endl;
}





int main(){
cout<<"hi";
}
