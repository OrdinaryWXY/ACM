#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int digit[20];//��λ20
ll dp[20][2];
//if4 ��ǰλ ֵ�Ƿ�Ϊ4
//limit �Ͻ�!!!
// �Ӹ�λ��ʼ��������һλ�Ƿ���4�� 
ll dfs(int len,bool if4,bool limit)//�Ż�ģ���������� 
{
	if(len == 0) return 1;//��λ��1��������һλ����0��. 
	if(!limit && dp[len][if4]) return dp[len][if4]; 
	ll cnt = 0,up_bound = (limit?digit[len]:9);
	
	for(int i =0 ;i<=up_bound;++i){
		if(if4 && i == 9) continue;//����49��һֻ 
		
		cnt+=dfs(len-1,i==4,limit&&i==up_bound);//�ϴ������Ҳ�ǲ��ǽ���		
	}
	if(!limit) dp[len][if4] = cnt;//�����Ͻ缴����״̬���´��ٸ�λ�Ͽ���ֱ��ͳ�� 
	return cnt;
} 
ll cal(ll num){ //��num��λ�ֽ⣬����¼��digit�����±��1-max. 
	int k = 0;
	while(num){
		digit[++k] = num%10;
		num/=10;
	} 
	return dfs(k,false,true);// �����λ��ʼ�����Ͻ簡 
}
int main(){
	int T;
	ll n; 
	scanf("%d",&T);
	while(T--){
		scanf("%lld",&n);
		printf("%lld\n",n+1-cal(n));
	}
	return 0;
} 
