#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,m,x;
	scanf("%d",&t);
	while(t--)
	{
		int maxm=INT_MIN,winner=0;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&x);
			if(x>maxm)
			{
				maxm=x;
				winner=0;
			}
		}
		for(int i=0;i<m;i++)
		{
			scanf("%d",&x);
			if(x>maxm)
			{
				maxm=x;
				winner=1;
			}
		}
		printf("%s\n",winner?"MechaGodzilla":"Godzilla");
	}
}