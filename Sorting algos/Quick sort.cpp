#include<iostream>
using namespace std;

int count=0;
int partition(int *p,int start,int end)
{
int pivot,temp,j=0,i=0;
pivot=p[end];

 while(i<end)
{
	
	if(p[i]<=pivot)
     {
        count++;
     	temp=p[i];
     	p[i]=p[j];
     	p[j]=temp;
     	j++;
    }
    i++;
	
    
}
       
        	
		temp=p[end];
     	p[end]=p[j];
     	p[j]=temp;
     	return j;
         
 	
}

void Quick_sort(int *p,int start,int end)
{

	if(start<end)
	{
	
	int	pivoti=partition(p,start,end);
		Quick_sort(p,start,pivoti-1);
		Quick_sort(p,pivoti+1,end);
	}
	
	
	
}





int main()
{
	int n;
	cout<<"enter n:";
	cin>>n;
	int array[n];
	for(int i=0;i<n;i++)
	cin>>array[i];
	
	
Quick_sort(array,0,n-1);
	
	cout<<"\nAfter Sorting:\n";
	for(int i=0;i<n;i++)
	  cout<<array[i]<<" ";
	  cout<<"\nNo of comparisons\n"<<count;
}
