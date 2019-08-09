#include<stdio.h>
#include<algorithm> 
using namespace std;
const int maxn = 111;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
struct edge{
	int from,to;
	long long cost;// Ȩ�� 
}E[maxn*maxn]; //have maxn��ô��� ���п�����ƽ������ߡ� 

bool cmp(edge a,edge b)
{
	return a.cost<b.cost;
}

int N,M;			//N������ 

int father[maxn];

void init()
{
	for(int i=1;i<=M;i++)
		father[i] = i;
}
int Find(int x)				//�Ҽ��ϣ� 
{
	if(x == father[x]) return x;
	return father[x] = Find(father[x]);
	
}

bool Same(int x,int y)//�ж�x��y�Ƿ���һ���������棻 
{
	return Find(x) == Find(y); 
}

void unionset(int x,int y)
{
	int u = Find(x),v = Find(y);
	if(v == u) return;
	father[u] = v;
}

long long kruskal()	//���������̰�ĵ�ȡ ���������ӵ��������Ƿ���ͬһ�������ڡ� 
{
	long long res = 0;
	sort(E+1,E+1+M,cmp);	//���Ȱ���Ȩ���������� 
	for(int i = 1;i <= M;i++)	//�������еı�̰�ĵ�ȡ�� 
	{
		if(Same(E[i].from,E[i].to)) continue; //����ͬһ�����Ͼ͡�������
		unionset(E[i].from,E[i].to);									  // ����ϲ� 
		res += E[i].cost;
	}
	return res;
}
int main()
{
	while(scanf("%d%d",&M,&N) == 2)
	{
		if(M == 0) break;
		init();						//��ʼ�� 
		for(int i = 0;i <= M;i++)	//���� 
		{
			scanf("%d%d%lld",&E[i].from,&E[i].to,&E[i].cost);
			
		}
		long long res = kruskal();
		for(int i = 0;i <= N;i++)
			if(!Same(i,1))
				res=-1;
		if(res==-1) printf("?\n");
		else printf("%lld\n",res);	
	}	
	
	return 0;
}

	
