#include<stdio.h>
#include<vector>

const int INF=0x3f3f3f3f;
const int maxn=1e5+5;

struct unt
{
	int v,w;
};
vector<unt>adj[maxn];
int n,dis[maxn];
bool vis[maxn];
int res=0;

void Prim (int x)
{
	mem(dis, INF);              // ������Ȩֵ��ʼ��Ϊ������
	dis[x] = 0;                 // ������Ȩֵ����Ϊ0
	for (int i = 0; i < n; ++i) // �������ж��㣬��֤���û��δ�����ʵĶ���
	{
		int u = -1,min = INF;   // ��minɸѡ��dis�е���Сֵ����δ��ɸѡ���Ķ��㵽����������Ȩֵ����Сֵ������u��¼�˶���
		for (int j = 0; j < n; ++j)     // ɸѡ����
		{
			if (vis[j] == 0 && dis[j] < min)    // �ж�����Ϊ1.δ��ɸѡ����2.С
			{
				u = j;              // ��¼����
				min = dis[j];       // ��¼��СȨֵ
			}
		}
		vis[u] = 1;     // ��ɸѡ���Ĵ˵���
		res += min;     // ���˵㵽������������СȨֵ���뵽�����
		// �������Ѹ���
		for (int j = 0; j < Adj[u].size(); ++j)     //����δ��ɸѡ���Ķ��㵽������������Ȩֵ
		{
			int v = Adj[u][j].v;        // v������¼����
			if (vis[v] == 0 && Adj[u][j].dis < dis[v])      // �ж�����Ϊ1.�˶���δ��ɸѡ����2.�˶��㵽�����������ľ�����Ը���֮ǰ�˶��㵽���������ľ���
			{
				dis[v] = Adj[u][j].dis;     // ���´˶��㵽���������ľ���
	V		}
		}
	}
}
