#include<bits/stdc++.h>

using namespace std;
const int N=10000;
bool isprime[N];
int cnt=0,pri[N];
void ispri()//������ɸ����������
{
    memset(isprime,0,sizeof(isprime));
    for(int i=2;i<=N;i++)
    {
        if(!isprime[i])
            pri[cnt++]=i;
        for(int j=0;j<cnt&&i*pri[j]<=N;j++)
        {
            isprime[i*pri[j]]=1;//һ��ʾ������ 
            if(!(i%pri[j]))
                break;
        }
    }
    return;
}
int main()
{
	ispri();
	for(int i=0;i<N;i++)
	{
		if(!isprime[i]) cout<<i<<' '; 
	}
	
	return 0;
}
 
