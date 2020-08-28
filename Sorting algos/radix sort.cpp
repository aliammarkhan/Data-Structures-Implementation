#include<iostream>
using namespace std;

void counting_sort(int  *p1,int  *p2,int n)
{

int Range[10];
int count=0;  
int temp[n];

  
  for(int i=0;i<=10;i++)
   Range[i]=0;
   
   for(int i=0;i<=10;i++)
   {
   	  for(int j=0;j<n;j++)
   	  {
   	     if(p1[j]==i)
   	     {
   	     	 count++;
		 }
   	  	
	 }
	 Range[i]=count;
	 count=0;
   	  
   	
   }
  
   
   for(int i=1;i<=10;i++)
   {
   	 Range[i]=Range[i]+Range[i-1];
   }
	
for(int i=n-1;i>=0;i--)
{
	temp[Range[p1[i]]-1]=p2[i];
	Range[p1[i]]--;
}

for(int i=0;i<n;i++)
  p2[i]=temp[i];
	
}
void Radix_sort(int *p,int n)
{
	int array[n];
	int max=p[0];
	int count=0;
	
	for(int i=0;i<n;i++)
	{
		if(max<p[i])
		max=p[i];
    }
    while(max!=0)
    {
    	max=max/10;
    	count++;
    	
    	
	}
	int factor=1;
	
	for(int i=0;i<count;i++,factor*=10)
	{
		
		for(int j=0;j<n;j++)
		{
			array[j]=(p[j]/factor)%10;
			
			
		}
		
		counting_sort(array,p,n);
		
		
	}
	
	
	
	
	
	
	
	
}









int main()
{
	int n;
	cout<<"Enter number of elements:";
	cin>>n;
	int a[n];
  for(int i=0;i<n;i++)
  cin>>a[i];
 Radix_sort(a,n);
  cout<<"\nafter sorting\n";
for(int i=0;i<n;i++)
  cout<<a[i]<<" ";
  return 0;
  
}
	
	
	
	
