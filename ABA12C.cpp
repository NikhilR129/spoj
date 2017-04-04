#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;
int main()
{
	int t,n,k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		int arr[n+1],dp[k+1];
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&arr[i]);
		}
		
		for(int i=1;i<=k;i++)
		{
			if(i<=n)
			{
				if(arr[i]==-1)
					dp[i]=MAX;
				else
					dp[i]=arr[i];
			}
			else
				dp[i]=MAX;
		}

		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=i/2;j++)
			{
				if(dp[j]==MAX || dp[i-j]==MAX)
					continue;

				dp[i]=min(dp[i],dp[j]+dp[i-j]);
			}
		}
		for(int i=1;i<=k;i++)
			cout<<dp[i]<<" ";
		cout<<endl;
	}
}