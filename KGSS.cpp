#include <bits/stdc++.h>
using namespace std;
pair<long long int,long long int> tree[450000];

void build(int node,int arr[],int start,int end)
{
	if(start==end)
	{
		tree[node].first=a[start];
		tree[node].second=a[start];
		return;
	}
	int mid=(start+end)/2;
	build(2*node,arr,start,mid);
	build(2*node+1,mid+1,end);

	tree[node].first=maxm(tree[2*node].first,tree[2*node].second,tree[2*node+1].first,tree[2*node+1].second);
}
int main()
{
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);

	int t,x,y;
	char c;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%c %d %d\n",&c,&x,&y);
		if(c=='U')
			update(x,y)
	}
}