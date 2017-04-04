#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int t,n,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		int arr[n][m];
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				scanf("%d",&arr[i][j]);
		}

		int dp[n][m];
		for(int i=0;i<m;i++)
			dp[0][i]=arr[0][i];

		for(int i=1;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(j==0)
					dp[i][j]=max(dp[i-1][j],dp[i-1][j+1])+arr[i][j];
				else if(j==m-1)
					dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+arr[i][j];
				else
					dp[i][j]=max(dp[i-1][j],max(dp[i-1][j-1],dp[i-1][j+1]))+arr[i][j];
			}

		}
		int maxm=INT_MIN;
		for(int i=0;i<m;i++)
			maxm=max(maxm,dp[n-1][i]);

		printf("%d\n",maxm);
	}	
	return 0;
}