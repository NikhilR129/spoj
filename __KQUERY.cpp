#include <bits/stdc++.h>
using namespace std;
struct node{
	int type;
	int val;
	int left;
	int right;
	int orig_idx;
};

bool comp(node &a,node &b)
{
	if(a.val==b.val)
		return a.type>b.type;

	return a.val>b.val;
}
int tree[120001]={0};

void update(int idx,int start,int end,int node)
{
	if(start>idx || end<idx)
		return;
	if(start==idx && end==idx)
	{
		tree[node]=1;
		return;
	}

	int mid=(start+end)/2;
	update(idx,start,mid,2*node);
	update(idx,mid+1,end,2*node+1);

	tree[node]=tree[2*node]+tree[2*node+1];
}

int query(int node,int l,int r,int start,int end)
{
	if(start>r || end<l)
		return 0;

	if(start>=l && end<=r)
		return tree[node];

	int mid=(start+end)/2;
	return query(2*node,l,r,start,mid)+query(2*node+1,l,r,mid+1,end);
}

int main(int argc, char const *argv[])
{
	node a[230001];
	int n,t,x,y,k;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i].val);
		a[i].type=0;
		a[i].orig_idx=i;
	}
	scanf("%d",&t);
	for(int i=n;i<n+t;i++)
	{
		scanf("%d%d%d",&x,&y,&k);
		a[i].type=1;
		a[i].left=x;
		a[i].right=y;
		a[i].val=k;
		a[i].orig_idx=i;
	}

	sort(a,a+n+t,comp);
	
	int ans[t];
	for(int i=0;i<n+t;i++)
	{
		if(a[i].type==0)
			update(a[i].orig_idx,0,n-1,1);
		else if(a[i].type==1)
			ans[a[i].orig_idx-n]=query(1,a[i].left-1,a[i].right-1,0,n-1);
	}

	for(int i=0;i<t;i++)
		printf("%d\n",ans[i]);
	return 0;
}