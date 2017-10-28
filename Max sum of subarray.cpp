#include<iostream>
#include<climits>
using namespace std;

int MaxSubarraySum(int arr[], int n)
{
	int ans= INT_MIN, start= 0, end= 0, max=  0, s= 0;
	
	for(int i=0;i<n;i++)
	{
		max+= arr[i];
		if(ans < max)
		{
			ans = max;
			start = s;
			end = i;
		}
		if( max < 0)
		{
			max = 0;
			s= i+1;
		}
	}
	cout<<"Maximum contigous sum is: "<<ans<<endl;
	cout<<"From: "<<start<<" To: "<<end<<endl;
}

int main()
{
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];	
	}
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";	
	}
	cout<<endl;
	MaxSubarraySum(arr,n);
	
}
