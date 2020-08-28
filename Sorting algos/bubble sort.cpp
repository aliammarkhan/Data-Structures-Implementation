#include<iostream>
using namespace std;


void bubble_sort(int *a,int n)
{
	bool x=false;
	int count=0;
	int round=0,temp=0;
	
	for(round=0;round<n;round++)
	{
		  count++;
		
		for(int i=0;i<n-round-1;i++)
		{
			count++;
			if(a[i]>a[i+1])
			{   
			    x =true;
				temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
				
			}
			
			
		}
		if(x==false)
		break;
		
		
	}
	cout<<"Count:"<<count<<endl;
	
}

int main()
{
	int n;
	cout<<"Enter number elements:";
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	
	bubble_sort(a,n);
	
		for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
	
}
