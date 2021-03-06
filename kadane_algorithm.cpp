#include<iostream>//O(n^2)
#include<climits>//kadane 's algorithm for max_sum of subarray O(n)
using namespace std;

void kadane(int a[],int n)
{
	int csum=0,msum=0;
	for(int i=0;i<n;i++)
	{
		csum=csum+a[i];
		if(csum<0)
		{
			csum=0;
		}
		msum=max(csum,msum);
	}
	cout<<msum;
}
int main()
{
	int a[9]={-4,1,3,-2,6,2,-8,-9,4};
	kadane(a,9);
	
}
