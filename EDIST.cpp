#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	char a[2002],b[2002];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%s",a,b);
		int n=strlen(a),m=strlen(b);
		int dp[n+1][m+1];
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=m;j++)
			{
				if(i==0)
					dp[i][j]=j;
				else if(j==0)
					dp[i][j]=i;
				else if(a[i-1]==b[j-1])
					dp[i][j]=dp[i-1][j-1];
				else
					dp[i][j]=1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
			}
		}
		printf("%d\n",dp[n][m]);
	}
}