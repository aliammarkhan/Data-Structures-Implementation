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
	cout<<"Count in bubble:"<<count<<endl;
	
}

void comb_sort(int *p,int n)
{
	int gap=n,temp=0,i=0,j;
	gap=gap/1.3;
	j=gap+i;
     while(gap>=1)
     {
	    while(j<n)
		{
		  if(p[i]>p[j])
		  {
		  	cout<<"\nSwapping "<<p[i]<<" and "<<p[j]<<endl;
		  	    temp=p[i];
				p[i]=p[j];
				p[j]=temp;
				
		  	
		  }
		  i++;
		  j=gap+i;
		
		}
		i=0;
		gap=gap/1.3;
		j=gap+i;
   }
 //bubble_sort(p,n);
		

	
	
}


int main()
{
	int n;
	cout<<"Enter number elements:";
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	
	comb_sort(a,n);
	
		for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
	
}
