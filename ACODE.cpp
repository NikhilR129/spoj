#include <bits/stdc++.h>
using namespace std;
int main()
{
	while(true)
	{
		string s;
		cin>>s;
		if(s=="0")
			return 0;

		int n=s.size();
		long long int dp[n+1];
		dp[0]=1;
		dp[1]=1;

		for(int i=2;i<=n;i++)
		{
			/*if((s[i-2]-'0')*10+(s[i-1]-'0')>=1 && (s[i-2]-'0')*10+(s[i-1]-'0')<=26)
				dp[i]=dp[i-1]+dp[i-2];*/
			int c=s[i-1]-'0';
			int c1=s[i-2]-'0';
			if(c1==0 && c==0)
				dp[i]=0;
			else if(c1==0)
				dp[i]=dp[i-1];
			else if(c==0)
			{
				if(c1*10+c>=1 && c1*10+c<=26)
					dp[i]=dp[i-2];
				else
					dp[i]=0;
			}
			else if(c1*10+c >=1 && c1*10+c<=26)
			{
				dp[i]=dp[i-1]+dp[i-2];
			}
			else
				dp[i]=dp[i-1];
		}

		printf("%lld\n",dp[n]);
	}
}