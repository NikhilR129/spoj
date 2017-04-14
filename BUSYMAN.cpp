#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int,int> a,pair<int,int> b)
{
	if(a.second==b.second)
		return a.first>b.first;

	return a.second<b.second;
}
int main(int argc, char const *argv[])
{
	int t,n,x,y;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		pair<int,int> arr[n];
		for(int i=0;i<n;i++)
			scanf("%d%d",&arr[i].first,&arr[i].second);

		sort(arr,arr+n,comp);
		int cnt=1,i=1,end=arr[0].second;

		while(i<n)
		{
			if(arr[i].first>=end)
			{
				cnt++;
				end=arr[i].second;
			}
			i++;
		}
		printf("%d\n",cnt);
	}
	return 0;
}