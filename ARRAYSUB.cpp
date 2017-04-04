#include <bits/stdc++.h>
using namespace std;

int tree[450000];

void build(int node,int start,int end,int arr[])
{
	if(start==end)
	{
		tree[node]=arr[start];
		return;
	}

	int mid=(start+end)/2;

	build(2*node,start,mid,arr);
	build(2*node+1,mid+1,end,arr);

	tree[node]=max(tree[2*node],tree[2*node+1]);
}

int query(int node,int start,int end,int l,int r)
{
	if(start>end || start>r || end<l)
		return INT_MIN;

	if(start>=l && end<=r)
		return tree[node];

	int mid=(start+end)/2;

	return max(query(2*node,start,mid,l,r),query(2*node+1,mid+1,end,l,r));
}
int main()
{
	int n,k;
	scanf("%d",&n);

	int arr[n];
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);

	build(1,0,n-1,arr);
	scanf("%d",&k);
	for(int i=0;i<=n-k;i++)
		printf("%d ",query(1,0,n-1,i,i+k-1));

}