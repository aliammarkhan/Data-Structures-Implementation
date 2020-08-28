#include<iostream>

using namespace std;


void insertion_sort(int *a,int n) 
{
	int temp,j;
	for(int i=1;i<n;i++)
	{
		temp=a[i];
	 for( j=i-1;j>=0&&a[j]>temp;j--)
	 { 
	       a[j+1]=a[j];
	 }
	 a[j+1]=temp;
	
		
		
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
