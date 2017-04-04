#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void update(ll arr[],ll lz[],ll node,ll start,ll end,ll l,ll r,ll val)
{
	if(start>end)
		return;
	
	if(lz[node])
	{
		arr[node]+=(end-start+1)*lz[node];
		if(start!=end)
		{
			lz[2*node]+=lz[node];
			lz[2*node+1]+=lz[node];
		}
		lz[node]=0;		
	}

	if(l>end || r<start)
		return;

	if(start>=l && end <=r)
	{
		arr[node]+=(end-start+1)*val;
		if(start!=end)
		{
			lz[2*node]+=val;
			lz[2*node+1]+=val;
		}	
		return;
	}

	ll mid=(start+end)/2;
	update(arr,lz,2*node,start,mid,l,r,val);
	update(arr,lz,2*node+1,mid+1,end,l,r,val);
	arr[node]=arr[2*node]+arr[2*node+1];
}

ll query(ll arr[],ll lz[],ll node,ll start,ll end,ll l,ll r)
{
	if(start>end || start>r || end<l)
		return 0;

	if(lz[node])
	{
		arr[node]+=(end-start+1)*lz[node];
		if(start!=end)
		{
			lz[2*node]+=lz[node];
			lz[2*node+1]+=lz[node];
		}
		lz[node]=0;
	}
	
	if(start>=l && end<=r)
		return arr[node];

	ll mid=(start+end)/2;

	return query(arr,lz,2*node,start,mid,l,r)+query(arr,lz,2*node+1,mid+1,end,l,r);
}
int main()
{
	ll t,n,c;
	


	cin>>t;
	ll type,x,y,val;
	while(t--)
	{
		scanf("%lld%lld",&n,&c);
		ll arr[400000],lz[400000];

	for(ll i=1;i<=400000;i++)
	{
		arr[i]=0;
		lz[i]=0;
	}
		while(c--)
		{
			scanf("%lld",&type);
			if(!type)
			{
				scanf("%lld%lld%lld",&x,&y,&val);
				update(arr,lz,1,1,n,x,y,val);
			}
			else
			{
				scanf("%lld%lld",&x,&y);
				printf("%lld",query(arr,lz,1,1,n,x,y));
			}
		}
	}
}