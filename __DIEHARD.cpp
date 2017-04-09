#include <bits/stdc++.h>
int dp[1001][1001];
using namespace std;

int ans(int x,int y)
{
	if(x<=0 || y<=0)
		return -1;
	if(dp[x][y]!=-1)
		return dp[x][y];
	return dp[x][y]=max(ans(x-17,y+7),ans(x-2,y-8))+2;
}
int main()
{
	int t;
	int x,y;
	for(int i=0;i<=1000;i++)
	{
		for(int j=0;j<=1000;j++)
			dp[i][j]=-1;
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&x,&y);
		printf("%d\n",ans(x,y));
	}
}