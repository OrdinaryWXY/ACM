#include<stdio.h>
/*long long ar[10000000]= {0};//���仯�ݹ飬��ȴ�������С�� 
long long pow(int a,int b)//a��b�η� digui;
{
	if(ar[b]>0)
		return ar[b];
	else
	{
		if(b==1)
			return ar[b]=a;
		else
		{
			if(b%2==0)
				return ar[b]=pow(a,b/2)*pow(a,b/2);
			else
				return ar[b]=pow(a,(b-1)/2)*pow(a,(b-1)/2)*pow(a,1);

		}
	}
}
int pow(int a,int n)//����ֵ��a��n�η�,��̳�ϵ� 
{
    int result=1;
    while(n!=0)
    {
        if(n%2==1)//���n������
            result=result*a;//��Ҫ���һ��
        a=a*a;
        n=n/2;//����
    }
    return result;
}



int ans=1,a;
for(int i=0;i<n;i++)
{
	ans=ans*a;


}







int fi(int n)//�ݹ飬쳲���������ģ�� 
{
	if(n==1||n==2)
		return 1;
	else
		return fi(n-1)+fi(n-2);

}
int pow(int a,int b)//������ 
{
		if(b==1)
			return a;
		else
		{
			if(b%2==0)
				return pow(a,b/2)*pow(a,b/2);
			else
				return pow(a,(b-1)/2)*pow(a,(b-1)/2)*pow(a,1);
		}
}
long long pow(int a,int b)//��Ϊlong long�������ݹ�ģ 
{
		if(b==1)
			return a;
		else
		{
			if(b%2==0)
				return pow(a,b/2)*pow(a,b/2);
			else
				return pow(a,(b-1)/2)*pow(a,(b-1)/2)*pow(a,1);
		}
}
*/


	
int main(void)
{
	int x,y,t;
	while(scanf("%d%d",&x,&y)!=EOF)
	{
			
	printf("%lld",pow(x,y));
	}
	return 0;
}
