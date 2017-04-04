#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	int n,u,q;
	while(t--)
	{
		scanf("%d%d",&n,&u);
		long long int arr[n];
		for(int i=0;i<n;i++)
			arr[i]=0;

		int x,y,val;
		while(u--)
		{
			scanf("%d%d%d",&x,&y,&val);
			arr[x]+=val;
			if(y+1<n)
				arr[y+1]-=val;
		}
		long long int temp=0;
		for(int i=0;i<n;i++)
		{
			temp+=arr[i];
			arr[i]=temp;
		}
		scanf("%d",&q);
		int index;
		while(q--)
		{
			scanf("%d",&index);
			printf("%lld\n",arr[index]);
		}
	}
}