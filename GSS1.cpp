#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int mps;
	int mss;
	int ts;
	int msubsum;
};
Node tree[250000];
void build(int node,int start,int end,int arr[])
{
	if(start==end)
	{
		tree[node].mps=tree[node].mss=tree[node].ts=tree[node].msubsum=arr[start];
		return;
	}

	int mid=(start+end)/2;

	build(2*node,start,mid,arr);
	build(2*node+1,mid+1,end,arr);

	tree[node].ts=tree[2*node].ts+tree[2*node+1].ts;
	tree[node].mps=max(tree[2*node].mps,tree[2*node].ts+tree[2*node+1].mps);
	tree[node].mss=max(tree[2*node+1].mss,tree[2*node+1].ts+tree[2*node].mss);
	tree[node].msubsum=max(max(tree[2*node].msubsum,tree[2*node+1].msubsum),tree[2*node].mss+tree[2*node+1].mps);
}

Node newNode(int x)
{
	Node n;
	n.ts=n.mss=n.mps=n.msubsum=x;
	return n;
}

Node query(int node,int start,int end,int l,int r)
{
	if(start>end || start>r || end<l)
		return newNode(-1000000);
	if(start>=l && end<=r)
		return tree[node];

	int mid=(start+end)/2;

	Node n1=query(2*node,start,mid,l,r);
	Node n2=query(2*node+1,mid+1,end,l,r);

	Node N;
	N.ts=n1.ts+n2.ts;
	N.mps=max(n1.mps,n1.ts+n2.mps);
	N.mss=max(n2.mss,n2.ts+n1.mss);
	N.msubsum=max(max(n1.msubsum,n2.msubsum),n1.mss+n2.mps);

	return N;
}
int main()
{
	int n,m,x,y;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);

	build(1,0,n-1,arr);

	scanf("%d",&m);

	while(m--)
	{
		scanf("%d%d",&x,&y);
		Node NZ=query(1,0,n-1,x-1,y-1);
		printf("%d\n",NZ.msubsum);
	}
}