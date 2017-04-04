#include <bits/stdc++.h>
using namespace std;

int find(int parent[],int x)
{
	int x1=x;
	while(parent[x1]!=x1)
		x1=parent[x1];

	parent[x]=x1;

	return x1;
}

void merge(int parent[],int x,int y)
{
	int x1=find(parent,x);
	int y1=find(parent,y);
	parent[x1]=y1;
}
int main()
{
	int n,m,x,y;
	bool istree=true;
	scanf("%d%d",&n,&m);

	int parent[n+1];
	for(int i=1;i<=n;i++)
		parent[i]=i;

	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		int z1=find(parent,x);
		int z2=find(parent,y);
		if(z1==z2)
			istree=false;
		else
			merge(parent,z1,z2);
	}

	if(istree)
		printf("YES\n");
	else
		printf("NO\n");
}