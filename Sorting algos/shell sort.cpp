#include<iostream>
#include<math.h>

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

void shell_sort(int *p,int n)
{
	int gap=n,temp=0,i=0,j;
	gap=floor(n/2);
	j=gap+i;
     while(gap>1)
     {
	    while(j<n)
		{
            while(j-gap>0)
			{
				if(p[j-gap]>p[j])
				{
				temp=p[j];
				p[j]=p[j-gap];
				p[j-gap]=temp;
					
					
				}
				j=j-gap;
				
				
				
			}	
 		  i++;
		  j=gap+i;
		
		}
		i=0;
		gap=floor(gap/2);
		j=gap+i;
   }
 insertion_sort(p,n);
		
	
	
	
}
int main()
{
	int n;
	cout<<"Enter number elements:";
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	
	shell_sort(a,n);
	
		for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
	
}
