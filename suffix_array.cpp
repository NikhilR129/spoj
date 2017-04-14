#include <bits/stdc++.h>
using namespace std;

struct node{
	int rank1;
	int rank2;
	int idx;
};

bool comp(node &a,node &b)
{
	if(a.rank1==b.rank1)
		return a.rank2<b.rank2;

	return a.rank1<b.rank1;
}

int main(int argc, char const *argv[])
{
	int t;
	char s[100000];
	node suff[100000];
	int rev[100000];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		int n=strlen(s);
		for(int i=0;i<n;i++)
		{
			suff[i].idx=i;
			suff[i].rank1=s[i]-'a';
			suff[i].rank2=(i+1<n?s[i+1]-'a':-1);
		}
		sort(suff,suff+n,comp);

		for(int k=2;k<n;k++)
		{
			int prev_rank=suff[0].rank1,rank=0;
			suff[0].rank1=0;
			rev[suff[0].idx]=0;
			for(int i=1;i<n;i++)
			{
				if(suff[i].rank1==prev_rank && suff[i].rank2==suff[i-1].rank2)
				{
					suff[i].rank1=rank;
				}
				else
				{
					prev_rank=suff[i].rank1;
					suff[i].rank1=++rank;
				}
				rev[suff[i].idx]=i;
			}
			for(int i=0;i<n;i++)
			{
				suff[i].rank2=(suff[i].idx+k<n)?suff[rev[suff[i].idx+k]].rank1:-1;
			}
			sort(suff,suff+n,comp);
		}

		for(int i=0;i<n;i++)
			cout<<suff[i].idx<<" ";


		cout<<endl;
	}
	return 0;
}