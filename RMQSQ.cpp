#include <bits/stdc++.h>
using namespace std;

int tree[450000];

void build(int start,int end,int node,int arr[])
{
	if(start==end)
	{
		tree[node]=arr[start];
		return;
	}
	int mid=(start+end)/2;
	build(start,mid,2*node,arr);
	build(mid+1,end,2*node+1,arr);

	tree[node]=min(tree[2*node],tree[2*node+1]);
}
int query(int start,int end,int node,int x,int y)
{
	if(start>=x && end<=y)
		return tree[node];

	if(start>end || start>y || end<x)
		return INT_MAX;

	int mid=(start+end)/2;
	return min(query(start,mid,2*node,x,y),query(mid+1,end,2*node+1,x,y));
}
int main()
{
	int n,q,x,y;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);

	build(0,n-1,1,arr);
	/*for(int i=0;i<10;i++)
		cout<<tree[i]<<" ";*/

	/*cout<<query(0,n-1,1,0,n-1);*/
	cin>>q;
	while(q--)
	{
		scanf("%d%d",&x,&y);
		printf("%d\n",query(0,n-1,1,x,y));
	}
}