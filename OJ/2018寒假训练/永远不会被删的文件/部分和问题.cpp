#include<cstdio>
#include<iostream>
using namespace std;
int n,k,a[22],b[22];
bool  dfs(int x,int sum)  //�����ұ���һ��ɵý�
{
	if(sum>k) return false;    //�˴����ں��ڲ��䣬�����������һ����֦��ʱ��ͻ��Ϊ8MS������ƽʱ��Ҫ��ע�ؼ�֦�������Ż����밡������
	if(x==n) return sum==k;  //���ǰn�������ˣ�����sum=k�Ƿ����
	if(dfs(x+1,sum))
	{
		b[x]=0;
		return true;
	}   //���������a[x]����������Ϊ0��
	if(dfs(x+1,sum+a[x]))
	{
		b[x]=1;
		return true;
	}   //�������a[x]����������Ϊ1��
	return false;
}
int main()
{
	cin>>n;
	for(int i = 0; i<n; i++)
		scanf("%d",&a[i]);
	cin>>k;
	if(dfs(0,0))
	{
		printf("YES\n");
		for(int i=0; i<n; i++)
			if(b[i])printf("%d ",a[i]);
		printf("\n");
	}
}
