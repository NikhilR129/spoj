#include <bits/stdc++.h>
#define ll long long int
using namespace std;
map<ll,ll> m;

ll maxm(ll x,ll y,ll z,ll w)
{
	return max(x,max(max(y,z),w));
}
ll query(ll x)
{
	if(m.find(x)!=m.end())
		return m[x];

	return m[x]=max(query(x/2)+query(x/3)+query(x/4),x);
}
int main()
{
	m[0]=0;
	m[1]=1;
	m[2]=2;
	m[3]=3;
	ll n;
	while( scanf("%lld", &n) != EOF)
	{
		printf("%lld\n",query(n));
	}
	return 0;	
}