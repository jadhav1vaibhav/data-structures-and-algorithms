//display all the sub matrices of the matrix #include<iostream>
#include<iostream>
using namespace std;
int main()
{
	/*#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input1.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif
*/
	int n;
	cin>>n;
	int a[n+1][n+1];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
		int sum=0;
		int prefix_sum[n+1][n+1];
		for(int i=0;i<=n;i++)
		{
			prefix_sum[0][i]=0;
			prefix_sum[i][0]=0;
		}
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			prefix_sum[i][j]=0;
			for(int k=1;k<=j;k++)
			{
				prefix_sum[i][j]=prefix_sum[i][j]+a[i][k];			
			}				
		}
		
		for(int i=2;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			
			prefix_sum[i][j]=prefix_sum[i][j]+prefix_sum[i-1][j];			
				
		}
		
		
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				 
				for(int k=1;k<=n-i+1;k++)
					for(int l=1;l<=n-j+1;l++)
					{
						
						int tx=k,ty=l;
						int bx=k+i-1,by=l+j-1;
						
					  sum=sum+prefix_sum[bx][by]-prefix_sum[bx][ty-1]-prefix_sum[tx-1][by]+prefix_sum[tx-1][ty-1];
					}
			}
		}
		cout<<sum;
}
