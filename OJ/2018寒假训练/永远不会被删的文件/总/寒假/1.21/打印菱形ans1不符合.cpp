#include<stdio.h>
int main(void) 
{
	int i,j,n,k,m;
	scanf("%d",&n);
	for (i=1; i<=n; i++) 
	{ //��ӡ�ϰ벿��
		for(j=1; j<=n-i; j++) 
		{ //��ӡ�ո񣬸����ݼ�
			printf(" ");
		}
		for(k=1; k<=2*i-1; k++) //��ӡ* ������Ϊ2k-1
			printf("*");
		printf("\n");
	}

	for(i=1; i<=n-1; i++) { //��ӡ�°벿��
		for(j=1; j<=i; j++) { //��ӡ�ո�
			printf(" ");
		}
		for (m=1; m<=2*(n-i)-1; m++) { //��һ�¼��ι�ϵ���ɵõ�2*��n-1��-1�����ϵ
			printf("*");
		}
		printf("\n");
	}
}
