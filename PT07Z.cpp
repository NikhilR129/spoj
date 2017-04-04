#include<bits/stdc++.h>
using namespace std;

void dfs(int x,vector<vector<int>> &v,bool visited[],int temp,int &dist,int &node)
{

	visited[x]=true;
	if(temp>dist)
	{
		dist=temp;
		node=x;
	}
	for(int i=0;i<v[x].size();i++)
	{
		if(!visited[v[x][i]])
		{
			dfs(v[x][i],v,visited,temp+1,dist,node);
		}
	}
}
int main()
{
	int n,x,y;
	cin>>n;
	bool visited[n+1];

	for (int i = 1; i <= n; ++i)
	 {
	 	visited[i]=false;
	 } 

	vector<vector<int>> v(n+1);
	for (int i = 1; i <= n-1; ++i)
	{
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	int dist=0;
	int node=1;
	dfs(1,v,visited,0,dist,node);
	for(int i=1;i<=n;i++)
		visited[i]=false;
	dist=0;
	dfs(node,v,visited,0,dist,node);
	cout<<dist<<endl;
}