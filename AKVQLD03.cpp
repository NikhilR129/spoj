#include <bits/stdc++.h>
using namespace std;
int tree[450000];

void add(int node,int start,int end,int x,int val)
{
	if(start>end || start>x || end<x)
		return;

	if(start==end && start==x)
	{
		tree[node]+=val;
		return;
	}
	int mid=(start+end)/2;
	add(2*node,start,mid,x,val);
	add(2*node+1,mid+1,end,x,val);

	tree[node]=tree[2*node]+tree[2*node+1];
}

int sum(int node,int start,int end,int l,int r)
{
	if(start>end || start>r || end<l)
		return 0;

	if(start>=l && end<=r)
		return tree[node];

	int mid=(start+end)/2;

	return sum(2*node,start,mid,l,r)+sum(2*node+1,mid+1,end,l,r);
}

int main()
{
	int n,q,x,y;
	string s;
	cin>>n>>q;
	while(q--)
	{
		cin>>s>>x>>y;
		if(s=="add")
			add(1,1,n,x,y);
		if(s=="find")
			cout<<sum(1,1,n,x,y)<<endl;
	}
}