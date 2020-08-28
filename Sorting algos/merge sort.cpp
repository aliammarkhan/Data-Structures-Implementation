#include<iostream>
using namespace std;


k


void merge(int *l,int *r,int *p,int n,int nl,int nr)
{

int	temp;


int i=0,j=0,k=0	;
  while(i<nl&&j<nr)
  {
  	
  	 if(l[i]<=r[j])
  	 {
  	 	p[k]=l[i];
  	 	i++;
  	 	k++;
  	 	
	}
	else
	{
		p[k]=r[j];
  	 	j++;
  	 	k++;
  	 	
		
	}
  	
}

  while(i<nl)
  {
  		p[k]=l[i];
  	 	i++;
  	 	k++;
  	
  }
    while(j<nr)
  {
  		p[k]=r[j];
  	 	j++;
  	 	k++;
  	
  }
	
	
	
}
void merge_sort(int p[],int n)
{
 if(n<2)
   {
   return;
   }
int mid=n/2;
int l[mid],r[n-mid];	
   
 
 for(int i=0;i<mid;i++)
  l[i]=p[i];
	

 for(int i=mid;i<n;i++)
    r[i-mid]=p[i];
  

	
  merge_sort(l,mid);
  merge_sort(r,n-mid);
  merge(l,r,p,n,mid,n-mid);
	}
int main()
{
	int n;
	cout<<"enter n:";
	cin>>n;
	int array[n];
	for(int i=0;i<n;i++)
	cin>>array[i];
	
	

	merge_sort(array,n);
	
	cout<<"\nAfter Sorting:\n";
	for(int i=0;i<n;i++)
	  cout<<array[i]<<" ";
}
