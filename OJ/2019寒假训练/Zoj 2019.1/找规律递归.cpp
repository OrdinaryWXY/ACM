#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+5;
ll f(ll n){
	if(n==3)	return 2;
	if(n==2)	return 2;
	if(n<=1)	return 1;
	ll i;
	for(i=1;i<n;i=i<<1);//����֮��i���Ͻ硣
	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   cout<<"up = "<<i<<endl;
	if(n-(i>>1)>(i>>2))//��벿��   ���ޣ� 
		return f(n-(i>>1))*2;
	else//ǰ�벿�� 
		return f(n-(i>>2));
}
int main() {
	int n;
	cin>>n;
	cout<<f(n)<<endl;
	return 0;
}
