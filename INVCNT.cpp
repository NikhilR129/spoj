#include <bits/stdc++.h>
using namespace std;

void merge(int arr[],int start,int mid,int end,long long int &ans)
{
	int b[mid-start+1],c[end-mid];
	for(int i=start;i<=mid;i++)
		b[i-start]=arr[i];

	for(int i=mid+1;i<=end;i++)
		c[i-mid-1]=arr[i];

	int l1=0,l2=0,idx=start;
	while(l1<mid-start+1 && l2<end-mid)
	{
		if(b[l1]<=c[l2])
		{
			arr[idx++]=b[l1];
			l1++;
		}
		else
		{
			ans+=(mid-start-l1+1);
			arr[idx++]=c[l2];
			l2++;
		}

	}
	while(l1<mid-start+1)
		{
			arr[idx++]=b[l1++];
		}
	while(l2<end-mid)
		arr[idx++]=c[l2++];
}
void merge_sort(int arr[],long long int &ans,int start,int end)
{
	if(end-start<1)
		return;
	int mid=(start+end)/2;
	merge_sort(arr,ans,start,mid);
	merge_sort(arr,ans,mid+1,end);

	merge(arr,start,mid,end,ans);
}
int main(int argc, char const *argv[])
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		long long int ans=0;
		scanf("%d",&n);
		int arr[n];
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);

		merge_sort(arr,ans,0,n-1);
		
		printf("%lld\n",ans);
	}
	return 0;
}