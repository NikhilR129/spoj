#include <bits/stdc++.h>
#define UA 2
#define M 0
#define F 1
using namespace std;

void dfs(int x,int type[],vector<vector<int>> &v,bool* suspicious,int par_type)
{
	type[x]=(par_type+1)%2;
	for(int i=0;i<v[x].size();i++)
	{
		if(type[v[x][i]]!=UA && type[v[x][i]]==type[x])
		{
			*suspicious=true;
			return;
		}
		else if(type[v[x][i]]==UA)
		{
			dfs(v[x][i],type,v,suspicious,type[x]);
		}

	}
}
int main(int argc, char const *argv[])
{
	int t,V,E,x,y;
	scanf("%d",&t);
	for(int k=1;k<=t;k++)
	{
		bool suspicious=false;
		printf("Scenario #%d:\n",k);
		scanf("%d%d",&V,&E);
		int type[V+1];

		for(int i=1;i<=V;i++)
			type[i]=UA;
		vector<vector<int>> v(V+1);
		for(int i=0;i<E;i++)
		{
			scanf("%d%d",&x,&y);
			v[x].push_back(y);
			v[y].push_back(x);
		}

		for(int i=1;i<=V;i++)
			if(type[i]==UA)
			{
				dfs(i,type,v,&suspicious,0);
				if(suspicious==true)
				{
					printf("Suspicious bugs found!\n");
					break;
				}
			}
		if(!suspicious)
			printf("No suspicious bugs found!\n");
	}
	return 0;
}