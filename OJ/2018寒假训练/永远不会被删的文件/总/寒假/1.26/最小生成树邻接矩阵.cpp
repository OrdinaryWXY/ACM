#include<stdio.h>
#include<string.h>
const int MAXN = 100000;
const int INF = 0x3f3f3f3f;

int n,g[MAXN][MAXN],d[MAXN],vis[MAXN]={0};//g����dȨֵ��vis��� 
int ans=0;
void prim(int x)
{
	memset(d,INF,sizeof(d));
	d[x]=0;
	for(int i=0;i<n;i++)
	{
		int u =-1,min=INF;
		for(int j=0;j<n;j++)
		{
			if(vis[j]==0 && d[j]<min)//����d[]�����е����ݲ��Ƚ�		 
			{						// �ҳ���Сֵ�����±��ֵ
				u=j;				 
				min=d[j];
			}
		}
		vis[u]=1;					//�Ѹõ���Ϊ������ 
		ans+=min;					//Ȩֵ���� 
		for(int v=0;v<n;v++)		//ͨ�������ø��У��ҵ��ܹ����� 
		{
			if(vis[v]==0&&g[u][v]<d[v]) 
			{
				d[v]=g[u][v]; 
			}
		}
		
		
		
	}
	
	
	
}
