#include <bits/stdc++.h>
int tree[450000];
using namespace std;

void build(int a[],int node,int start,int end)
{
	if(start==end)
	{
		tree[node]=a[start];
		return;
	}
	int mid=(start+end)/2;
	build(a,2*node,start,mid);
	build(a,2*node+1,mid+1,end);

	tree[node]=tree[2*node]&tree[2*node+1];
}

int query(int node,int start,int end,int l,int r)
{
	if(start>end || start>r || end<l)
		return 0x7fffffff;

	if(start>=l && end<=r)
		return tree[node];

	int mid=(start+end)/2;

	return query(2*node,start,mid,l,r)&query(2*node+1,mid+1,end,l,r);
}
int main()
{
	int t,n,k,x;
	scanf("%d",&t);
	while(t--)
	{
		int ONES=0x7fffffff;
		scanf("%d%d",&n,&k);
		if(2*k+1>=n)
		{
			for(int i=0;i<n;i++)
			{
				scanf("%d",&x);
				ONES&=x;
			}
			for(int i=0;i<n;i++)
				printf("%d ",ONES);

		}
		else
		{
			int arr[n];
			for(int i=0;i<n;i++)
				scanf("%d",&arr[i]);

			build(arr,1,0,n-1);

			for(int i=0;i<n;i++)
			{
				ONES=0x7fffffff;
				if(i+k<n)
				{
					ONES&=query(1,0,n-1,i,i+k);
				}
				else if(i+k>=n)
				{
					ONES&=query(1,0,n-1,i,n-1)&query(1,0,n-1,0,(i+k-n)%n);
				}
				if(i-k>=0)
				{
					ONES&=query(1,0,n-1,i-k,i);
				}
				if(i-k<0)
				{
					ONES&=query(1,0,n-1,0,i)&query(1,0,n-1,(i-k+n)%n,n-1);
				}

				printf("%d ",ONES);
			}
		}
	
	printf("\n");

	}
}