#include <bits/stdc++.h>
#define ll long long int 
using namespace std;
int main()
{
	int t,n;
	scanf("%d",&t);
	for(int k=1;k<=t;k++)
	{
		printf("Case %d: ",k);
		scanf("%d",&n);
		ll arr[n+1],dp[n+1];
		for(int i=1;i<=n;i++)
			scanf("%lld",&arr[i]);
		
		dp[0]=0;
		dp[1]=arr[1];
		for(int i=2;i<=n;i++)
			dp[i]=max(dp[i-1],dp[i-2]+arr[i]);

		printf("%lld\n",dp[n]);
	}
}