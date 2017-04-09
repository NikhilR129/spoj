#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
vector<pii> inc={{0,1},{0,-1},{1,0},{-1,0}};
int bfs(int x,int y,int n,int m,int **dist)
{
	queue<pii> q;
	q.push(make_pair(x,y));
	while(!q.empty())
	{
		auto f=q.front();
		auto x1=f.first,y1=f.second;
		q.pop();
	
		for(int i=0;i<4;i++)
		{
			int newx=x1+inc[i].first; int newy=y1+inc[i].second;
			if(newx>=0 && newx<n && newy>=0 && newy<m && dist[newx][newy]>dist[x1][y1]+1)
			{		
				q.push(make_pair(newx,newy));
				dist[newx][newy]=dist[x1][y1]+1;
			}
		}

	}
}
int main()
{
	int t,m,n;
	int *arr[200],*dist[200];
	char s[200];
	for(int i=0;i<200;i++)
	{
		arr[i]=new int[200];
		dist[i]=new int[200];
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
		{
			scanf("%s",s);
			for(int j=0;j<m;j++)
			{
				arr[i][j]=s[j]-'0';
				if(!arr[i][j])
					dist[i][j]=1000000;
				else
					dist[i][j]=0;
			}
		}

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(arr[i][j])
					bfs(i,j,n,m,dist);
			}
		}

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				printf("%d ",dist[i][j]);
			printf("\n");
		}
	}
}