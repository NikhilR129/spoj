#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		int ans=0;
		scanf("%d",&n);
		int divisor=5;
		while(divisor<=n)
		{
			ans+=(n/divisor);
			divisor*=5;
		}
		printf("%d\n",ans);
	}
}