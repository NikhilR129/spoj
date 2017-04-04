#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	long long int count=0;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);

	unordered_map<int,int> m;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
				m[arr[i]*arr[j]+arr[k]]++;
		}
	}

	
	for(int i=0;i<n;i++)
	{
		if(arr[i]!=0)
		{
			for(int j=0;j<n;j++)
			{
				for(int k=0;k<n;k++)
				{
					if(m[arr[i]*(arr[j]+arr[k])])
					{
						count+=m[arr[i]*(arr[j]+arr[k])];
					}
				}
			}
		}
	}

	printf("%lld",count);	
}