/*
Hashing using chaining
*/
#include <iostream>
using namespace std;

template <typename t>
class dnode{

	public:
	t data;
	dnode<t>* next;
	dnode<t>* prev;	
	template <typename u>
	friend class list;
	
	dnode():prev(0),next(0),data(0){}
	dnode(dnode<t> *a,t data):prev(a),next(0),data(data){}
	dnode(t data):prev(0),next(0),data(data){}
	dnode(dnode<t> *a,dnode<t> *b, t data=0):prev(a),next(b),data(data){}	
		
};

template <typename t>
class list{

	public:
	dnode<t> *head;
	dnode<t> *tail;
	
	void deleteallnodes(){
		if(head!=0 && tail!=0){
			dnode<t> *temp=head;
			dnode<t> *deletor;
			
			while(temp!=0){
				cout<<"\nDeleting location: "<<temp;
				deletor=temp;
				temp=temp->next;
				delete deletor;
			}
			
			cout<<"\n\nAll nodes destroyed\n";
		}
		else{
			cout<<"\nNo nodes found\n";
		}
	}
	

	list(dnode<t>* a=0,dnode<t> *b=0):head(a),tail(b){}
	
	//dodeepcopy
	void dodeepcopy(const list<t>& list){
		dnode<t> *temp=list.head;
		dnode<t> *ptr=0;
		
		this->head=0;
		this->tail=0;
		
		while(temp!=0){
			ptr=new dnode<t>(temp->data);
			if(head==0 && tail==0){
				head=ptr;
				tail=ptr;
			}
			else{
				tail->next=ptr;
				ptr->prev=tail;
				tail=ptr;
				ptr->next=0;
			}
				temp=temp->next;
		}
	}
	
	//copy constructor
	list(const list<t>& list){
		dodeepcopy(list);
		
	}
	
	//assignment operator
	list<t>& operator=(const list<t>& d){
		if(this!=&d){
			delete this;
			dodeepcopy(d);
		}
		else return (*this);
	}
	
	void insertatlast(t a){
		dnode<t> *newnode=new dnode<t>(a);
		if(head==0 && tail==0){
			head=newnode;
			tail=newnode;
		}
		else{
			newnode->next=0;
			newnode->prev=tail;
			tail->next=newnode;
		    tail=newnode;
		}
	}
	
	void removefromlast(){
		dnode<t> *temp;
		if(head==0){
			cout<<"\nEmpty list\n";
		}
		else if(head==tail){
			delete head;
			head=0;
			tail=0;
		}
		else{
			temp=tail;
			tail=tail->prev;
			tail->next=0;			
			delete temp;
		}
	}
    
    dnode<t>* search(int k){
    	dnode<t> *temp=head;
    	while(temp->data!=k){
    		temp=temp->next;
		}
		return temp;
	}
	
	void printall(){
		dnode<t> *temp=head;
		while(temp!=0){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
	}
	
	~list(){
		deleteallnodes();
		head=0;
	}
	
};

template <typename t>
class hashing{
	
	private:
	list<t> *l;
    int size;
		
	public:
	hashing(int a){
		size=a;
		l=new list<t>[a];
	}
	
	int getcapacity(){
		return size;
	}
	
	//key calculation
	int hashkey(int k){
		return (k%size);
	}
	
	void insert(int k){
		int hash_index=hashkey(k);
		l[hash_index].insertatlast(k);
	}
	
	
	
	
	void print(){
		for(int i=0;i<size;i++){
			l[i].printall();
			cout<<endl;
		}
	}
	
};

int main(){
	
	int arr[10]={97,16,63,100,235,47,10,14,74,4};
	hashing<int> h(10);
	for(int i=0;i<10;i++){
		h.insert(arr[i]);
	}
	
	h.print();
	
}
