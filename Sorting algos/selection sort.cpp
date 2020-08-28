using namespace std;
#include<iostream>

void insertion_sort(int *a,int n) 
{
	int minindex,temp;
	for(int i=0;i<n-1;i++)
	{
		 minindex=i;
	 for(int j=i+1;j<n;j++)
	 { 
	       if(a[j]<a[minindex])
	        minindex=j;
	 }
	 
	  temp=a[i];
	  a[i]=a[minindex];
	  a[minindex]=temp;
	  
		
		
	}
	
	
}
int main()
{
	int n;
	cout<<"Enter number elements:";
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	
	insertion_sort(a,n);
	
		for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
	
}
