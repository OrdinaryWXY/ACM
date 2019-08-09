#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;

const int MAXN=1e5+5;

int vis[MAXN],ans[MAXN];
int n,k;
int bfs(int x,int end)
{
	queue<int> q1;
	q1.push(x);
	vis[x]=1;
	while(!q1.empty())
	{
		int v=q1.front(),t=0;
		q1.pop();
		for(int i=0; i<3; i++)
		{
			if(i==0) t=v+1;			//״̬ת�� 
			else if(i==1) t=v-1;	//
			else t=v*2;				//	

			if(t<0||t>2*k||t>100000) continue;//�ʵ���֦����ȷ���߽� 

			if(vis[t]==0)			//���ö��� ѭ���� 
			{
				q1.push(t);
				vis[t]=1;
				ans[t]=ans[v]+1;
			}
			if(t==end) return ans[t];//�ж� 
		}
	}
}

int main(void)
{
	memset(vis,0,sizeof(vis));
	memset(ans,0,sizeof(ans));
	scanf("%d%d",&n,&k);
	if(n>=k) printf("%d",n-k);
	else printf("%d",bfs(n,k));


	return 0;
}



