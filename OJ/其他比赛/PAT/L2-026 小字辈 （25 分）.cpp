#include<bits/stdc++.h>
using namespace std;
typedef struct{
  int a;//a�Ǹ�ĸ�ı��
  int b;//b�Ǹñ������Ӧ�ı���
}T;
int my(map<int,T> &op,int i){//�����ñ�֤�ں������޸ĵ�ֵ������������Ȼ��Ч
  if(op[i].b==0){
  	if(op[i].a!=-1){
  		my(op,op[i].a);
	  }
  }
  op[i].b=op[op[i].a].b+1;
  return op[i].b;//���ظñ�ŵı���
}
int main(){
  map<int,T> op;
  int n;
  cin>>n;
  int d;
  for(int i=1;i<=n;++i){
    scanf("%d",&d);
    op[i].a=d;
    if(d==-1) op[i].b=1;
  }
  int c;
  int max=1;
  for(int i=1;i<=n;++i){
  	if(op[i].a==-1) continue;
    c=my(op,i);
    if(c>max) max=c;//max��¼���ֵ����ֵ
  }
  printf("%d\n",max);
  int cnt=0;
  for(auto i=op.begin();i!=op.end();++i){
  	if(i->second.b==max){
	    if(cnt) printf(" ");
	    cnt++;
	    printf("%d",i->first);
	}
  }
}

