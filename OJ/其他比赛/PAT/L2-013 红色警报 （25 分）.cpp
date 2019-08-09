//�������벢�鼯�йص���Ŀ
#include<bits/stdc++.h>
using namespace std;
const int MAXN=505;
int f[MAXN];
int g[MAXN][MAXN];
int visit[MAXN];
void init(int n){//���鼯��ʼ��
  for(int i=0;i!=n;++i){
    f[i]=i;
  }
}
int find(int x){//�����ѯ��ʼʼ��ĺ���
  if(f[x]==x) return x;
  else return f[x]=find(f[x]);
}
bool un(int x,int y){//Ĭ�Ͻ�y����x����Ȧ�У�bool����Ϊ�˲鿴��ͨ��
  x=find(x);
  y=find(y);
  if(x!=y){
    f[y]=x;
    return true;
  }else{
    return false;
  }
}
//������˼·������ջ������ռ�ĳ��б�����������û����ռ�ĳ���ʹ�ò��鼯�γɳ���Ȧ���ٽ�����ռ�ĳ�
//�в��뵽����Ȧ�У�ÿ����һ������ռ�ĳ��У�ͳ�Ƹó��в������Ȧ�У����������·���������1����������ɫ����.
int main(){
  stack<int> op;
  stack<string> o;
  int n,m;
  cin>>n>>m;
  init(n);
  int k,l;
  for(int i=0;i!=m;++i){
    scanf("%d %d",&k,&l);
    g[k][l]=g[l][k]=1;
  }
  cin>>k;
  for(int i=0;i!=k;++i){
  	scanf("%d",&l);
  	op.push(l);
  	visit[l]=1;
  }
  for(int i=0;i!=n;++i){
  	if(visit[i]) continue;
  	for(int j=0;j!=n;++j){
  		if(!visit[j]&&g[i][j]) un(i,j);
	  }
  }
  if(n==k) o.push("Game Over.");
  for(int i=0;i!=k;++i){
  	l=op.top();
  	op.pop();
  	visit[l]=0;
  	int cnt = 0;
    for(int i=0;i!=n;++i){
  		if(!visit[i]&&g[l][i]){
  			if(un(l,i)) cnt++;	
		}
  	}
  	if(cnt>1){
  		char tmp[100];
  		sprintf(tmp,"Red Alert: City %d is lost!\n",l);
  		o.push(tmp);
	  }else{
	  	char tmp[100];
	  	sprintf(tmp,"City %d is lost.\n",l);
	  	o.push(tmp);
	  }
  }
  while(!o.empty()){
  	cout<<o.top();
  	o.pop();
  }
}

