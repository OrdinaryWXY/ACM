#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int f[1010],n,m;

struct unt{
	int a,b,w;	
}mp[3010];

int find(int x)
{
	return x==f[x]?x:find(f[x]);		
}
void join(int x,int y)
{
	int jx=find(x),jy=find(y);
	f[jx]=jy;
}
bool cmp(unt a,unt b)
{
	return a.w<b.w;
}
void init()
{
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
	}
}

int main(void)
{
	while(scanf("%d%d",&n,&m))
	{
		init();
		int ans=0;
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d",&mp[i].a,&mp[i].b,&mp[i].w);
		}
		sort(mp+1,mp+1+m,cmp);
		for(int i=1;i<=m;i++)
		{
			if(find(mp[i].a)!=find(mp[i].b))
			{
				join(mp[i].a,mp[i].b);
				ans+=mp[i].w;
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(f[i]==i)
			cnt++;
		}
		if(cnt>1)
			printf("-1\n");
		else 
			printf("%d\n",ans);
	}
	
	return 0;
}
