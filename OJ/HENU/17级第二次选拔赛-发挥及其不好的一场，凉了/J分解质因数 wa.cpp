#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define N 10000
bool isprime[N];
int pri[N];
int cnt=0;
void ispri()//������ɸ����������
{
	memset(isprime,0,sizeof(isprime));
	for(int i=2; i<=N; i++)
	{
		if(!isprime[i])
			pri[cnt++]=i;
		for(int j=0; j<cnt&&i*pri[j]<=N; j++)
		{
			isprime[i*pri[j]]=1;
			if(!(i%pri[j]))
				break;
		}
	}
	return;
}
void solve(int n)
{
	for(int i=0;; i++) //����������
	{
		if(!isprime[n])//�������֮����n��һ������ ��������
		{
			cout<<n<<endl;
			break;
		}
		int flag=0;
		while(n%pri[i]==0)//������������n�������� ����n��ֵ
		{
			if(flag)
				cout<<pri[i];
			else
				cout<<'*'<<pri[i];
			n/=pri[i];
		}

	}

	return;
}

int main()
{
	int n;
	ispri();
	while(cin>>n)
	{
		solve(n);
	}
	return 0;
}

