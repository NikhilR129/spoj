#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n,x;
	while(true)
	{
		scanf("%d",&n);
		if(!n)
			return 0;
		stack<int> s;
		queue<int> q;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&x);
			q.push(x);
		}
		int cnt=1;
		while(true)
		{
			int x=(q.empty()?-1:q.front()),y=(s.empty()?-1:s.top());
			if(x==-1 && y==-1)
			{
				cout<<"yes"<<endl;
				break;
			}
			if(x==-1 && y!=cnt)
			{
				cout<<"no"<<endl;
				break;
			}
			else if(x==cnt)
			{
				q.pop();
				cnt++;
			}
			else if(y==cnt)
			{
				s.pop();
				cnt++;
			}
			else
			{
				s.push(x);
				q.pop();
			}
		}
	}
	return 0;
}