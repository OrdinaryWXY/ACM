//���������ܹ�������֪�����ǵ����鼯����Ŀ��������Ŀ����˵���ѵ�����Ҳ�����ѣ�ʹ�ò��鼯�����ǲ���һ������Ȧ�м���
//������Ŀ����˵��������ֻ����һ�ֹ�ϵ�������Ѻ͵��˲�����һ����������¼��Ӧ�÷ֿ���¼����ֹ�ڼ�¼
//��ĳ���˳��ּ���һ���˵�����Ҳ������˵ĵ���
#include<bits/stdc++.h>
using namespace std;
int g[105][105];
int a[105];
void init() { //���鼯��ʼ��
	for(int i=1; i!=105; ++i) a[i]=i;
}
int find(int x) { //���ҳ�ʼ����
	return x==a[x]?x:a[x]=find(a[x]);
}
void mer(int x,int y) { //�ϲ�����Ȧ
	x=find(x);
	y=find(y);
	if(x!=y) {
		a[y]=x;
	}
}
int main() {
	init();
	int n,m,k;
	int flag;
	cin>>n>>m>>k;
	int o,p;
	for(int i=0; i!=m; ++i) {
		scanf("%d %d %d",&o,&p,&flag);
		g[o][p]=g[p][o]=flag;
		if(flag==1) mer(o,p);
	}
	int o1,p1;
	for(int i=0; i!=k; ++i) {
		scanf("%d %d",&o,&p);
		o1=find(o);
		p1=find(p);
		if(g[o][p]!=-1&&o1==p1) printf("No problem\n");
		else if(g[o][p]==0) printf("OK\n");
		else if(o1==p1&&g[o][p]==-1) printf("OK but...\n");
		else if(g[o][p]==-1&&o1!=p1) printf("No way\n");
	}
}

