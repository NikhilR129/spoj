#include <bits/stdc++.h>
using namespace std;
struct node
{
	bool end;
	node *children[10];
	node()
	{
		end=false;
		for(int i=0;i<10;i++)
			children[i]=NULL;
	}
};

bool insert(node *root,char *str)
{
	for(int i=0;str[i]!='\0';i++)
	{
		if(root->children[str[i]-'0']==NULL)
		{
			root->children[str[i]-'0']=new node();
			root=root->children[str[i]-'0'];
			if(str[i+1]=='\0')
			{
				root->end=true;
				return true;
			}
		}
		else
		{
			root=root->children[str[i]-'0'];
			if(str[i+1]=='\0')
			{
				root->end=true;
				return false;
			}
			if(root->end)
				return false;
		}
		
	}
}
void traverse(node *root,int idx)
{
	if(!root)
		return;
	cout<<idx<<" "<<root->end<<endl;
	for(int i=0;i<10;i++)
	{
		traverse(root->children[i],i);
	}
}
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		node *root=new node();
		bool temp=true;
		scanf("%d",&n);
		char a[12];
		while(n--)
		{
			scanf("%s",a);
			temp&=insert(root,a);

		}
		//traverse(root,-1);
		printf("%s\n",temp?"YES":"NO");
	}
}