#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAX_N=32005;
const int maxn=15010;
int n,tre[MAX_N];
int lowbit(int x){//���λ��һ 
	return x&-x;
}
void add(int i,int val){//�޸ģ����º�׺�͡� 
	for(;i<=MAX_N;i+=lowbit(i)){
		tre[i]+=val;
	}
}
int sum(int i){//1~x�ĺͣ�t��1��ʼ��� 
	int ans=0;
	for(;i>0;i-=lowbit(i)){
		ans+=tre[i];
	}
	return ans;
}
int main(){
	int x,y,ans[maxn];
	memset(tre,0,sizeof(tre));
	memset(ans,0,sizeof(ans));
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&x,&y);
		x++;
		ans[sum(x)]++;
		add(x,1);		
	}
	for(int i=0;i<n;i++)
		printf("%d\n",ans[i]);

	 
    return 0;
}

