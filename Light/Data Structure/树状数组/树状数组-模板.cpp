#include<iostream>
#include<cstring>
using namespace std;
const int maxn=5010;

int lowbit(int x){//���λ��һ 
	return x&-x;
}
void add(int i,int val){//�޸ģ����º�׺�͡� 
	for(;i<=n;i+=lowbit(i)){
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
	
    return 0;
}

