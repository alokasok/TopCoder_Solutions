#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int lis( int arr[], int n)
{

	int *lis,i,j;
	int *max_ele = new int[n];
	lis = new int[n];
	fill_n(lis,n,1);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j<=(i+1))
				lis[j]=arr[i];
			else if((i==0)&&(j==n-1))
			{
				cout<<i<<" "<<j<<endl;

				lis[j]=*max_element(lis,lis+(n-1));
				cout<<lis[j]<<endl;
			}
			else
			{
				lis[j]=*max_element(lis,lis+(j-1))+arr[j];
			}
		}



			/*if( arr[j]<arr[i] && lis[i]<lis[j]+1)
				lis[i] = lis[j] +1;*/
	//cout<<lis;
	for(int k=0;k<n;k++)
		cout<<lis[k]<<" ";
	cout<<endl;
	max_ele[i]=*max_element(lis,lis+(n));
	cout<<"Max: "<<arr[i]<<":"<<max_ele[i]<<endl;
	}


	return *max_element(max_ele,max_ele+n);
}

int main()
{
	  //int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
	  //int arr[] = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 };
	  int arr[] = { 94, 40, 49, 65, 21, 21, 106, 80, 92, 81, 679, 4, 61,  
		    6, 237, 12, 72, 74, 29, 95, 265, 35, 47, 1, 61, 397,
		      52, 72, 37, 51, 1, 81, 45, 435, 7, 36, 57, 86, 81, 72 };
	  int n = sizeof(arr)/sizeof(arr[0]);
	  //cout<<"Length of LIS is %d\n"<<lis( arr, n );
	  cout<<"Maximum alternate element sum is:"<<lis(arr,n)<<endl;
}
