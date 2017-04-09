#include <bits/stdc++.h>
using namespace std;
struct node
{
	int factors;
	int num;
};
bool comp(node &a,node &b)
{
	if(a.factors>=3 && b.factors>=3)
		return a.num<b.num;

	else
	{
		if(a.factors==b.factors)
			return a.num<b.num;
		return a.factors<b.factors;
	}
}
int main()
{
	node factors[100000];
	bool isprime[100000];
	for(int i=0;i<100000;i++)
	{
		isprime[i]=true;
		factors[i].factors=0;
		factors[i].num=i;
	}

	isprime[0]=isprime[1]=false;
	for(int i=2;i<100000;i++)
	{
		if(isprime[i])
		{
			factors[i].factors++;
			for(int j=2*i;j<100000;j+=i)
			{
				isprime[j]=false;
				factors[j].factors++;
			}
		}
	}
	sort(factors,factors+100000,comp);
	int primes3[1000];
	for(int i=0;i<1000;i++)
		primes3[i]=factors[43460+i].num;
	
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",primes3[n-1]);
	}		
}