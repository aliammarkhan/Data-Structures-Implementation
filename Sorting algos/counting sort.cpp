#include<iostream>
using namespace std;

void counting_sort(long long *p,long long n)
{
  long long max=p[0],temp[n],count=0;
  for(int i=0;i<n;i++)
  temp[i]=0;
  
  for(int i=1;i<n;i++)
  {
  	  if(p[i]>max)
  	  max=p[i];
  	
  }
  
  int Range[max+1];
  
  for(int i=0;i<=max;i++)
   Range[i]=0;
   
   for(int i=0;i<=max;i++)
   {
   	  for(int j=0;j<n;j++)
   	  {
   	     if(p[j]==i)
   	     {
   	     	 count++;
		 }
   	  	
	 }
	 Range[i]=count;
	 count=0;
   	  
   	
   }
  
   
   for(int i=1;i<=max;i++)
   {
   	 Range[i]=Range[i]+Range[i-1];
   }
	
for(int i=n-1;i>=0;i--)
{
	temp[Range[p[i]]-1]=p[i];
	Range[p[i]]--;
}

for(int i=0;i<n;i++)
  p[i]=temp[i];
	
}









int main()
{
	int n;
	cout<<"Enter number of elements:";
	cin>>n;
	long long a[n];
  for(int i=0;i<n;i++)
  cin>>a[i];
  counting_sort(a,n);
  cout<<"\nafter sorting\n";
for(int i=0;i<n;i++)
  cout<<a[i]<<" ";
  return 0;
  
}
	
	
	
	
	
	
	
	
	
	
	
	

