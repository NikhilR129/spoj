#include <bits/stdc++.h>
using namespace std;

int lca(int parent[],int level[],int x,int y)
{
	

	int z1=(level[x]>level[y]?x:y);
	if(z1==x)
	{
		while(level[x]!=level[y])
			x=parent[x];
	}
	else
	{
		while(level[x]!=level[y])
			y=parent[y];
	}
	if(x==y)
		return x;
	while(parent[x]!=parent[y])
	{
		x=parent[x];
		y=parent[y];
	}
	return parent[x];
}
int main()
{
	int t,n,x,y,nbs,q;
	scanf("%d",&t);
	for(int k=1;k<=t;k++)
	{
		scanf("%d",&n);
		int parent[n+1],level[n+1];
		parent[1]=-1,level[1]=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&nbs);
			while(nbs--)
			{
				scanf("%d",&x);
				parent[x]=i;
				level[x]=level[i]+1;
			}
		}
		printf("Case %d:\n",k);
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d%d",&x,&y);
			printf("%d\n",lca(parent,level,x,y));
		}
	}
}