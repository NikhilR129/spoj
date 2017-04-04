#include <bits/stdc++.h>
using namespace std;

int func(int stalls[],int n,int cows,int dist)
{
	int left=0,cnt=1;

	for(int i=1;i<n;i++)
	{
		if(stalls[i]-stalls[left]>=dist)
		{
			cnt++;
			if(cnt==cows)
				return 1;

			left=i;
		}
	}
	return 0;
}
int main()
{
	int n,c,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&c);
		int stalls[n];
		for(int i=0;i<n;i++)
			scanf("%d",&stalls[i]);

		sort(stalls,stalls+n);

		int start=0,end=stalls[n-1]-stalls[0]+1;

		while(end-start>1)
		{
			int mid=(start+end)/2;
			if(func(stalls,n,c,mid))
				start=mid;
			else
				end=mid;
		}
		printf("%d\n",start);
	}
	
}