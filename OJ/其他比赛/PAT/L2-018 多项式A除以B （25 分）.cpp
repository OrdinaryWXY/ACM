//�����ѵ����ڶ���ʽ����������������㷨������ٶ�
#include<bits/stdc++.h>
using namespace std;
double a[10005],b[10005];//ÿ�����鱣��һ������ʽ
int main () {
	map<int,double> op;//��¼���
	int n;
	cin>>n;
	int m;
	int maxn1=0,maxn2=0;//maxn1�������ʽA������ָ����maxn2�������ʽB������ָ����
	double l;
	for(int i=0; i<n; ++i) {
		scanf("%d %lf",&m,&l);
		a[m]=l;
		if(m>maxn1) maxn1=m;
	}
	int n1;
	cin>>n1;
	for(int i=0; i<n1; ++i) {
		scanf("%d %lf",&m,&l);
		b[m]=l;
		if(m>maxn2) maxn2=m;
	}
	for(int i=maxn1; i>=0; --i) { //�������㷨�������
		if(i<maxn2) break;//���������ָ��С�ڳ������ָ����������
		if(a[i]) {
			op[i-maxn2]=a[i]/b[maxn2];
			for(int j=maxn2; j>=0; --j) {
				a[i-maxn2+j]-=op[i-maxn2]*b[j];//�õ��µı���ʽ
			}
		}
	}
	//�������op�б�������̣�����a�б��������
	int cnt=0;
	for(auto i=op.begin(); i!=op.end(); ++i) {
		if(fabs(i->second)<0.05) op.erase(i);//С��0.05����������0����������Ҫ��ȥ��
	}
	printf("%d ",op.size());
	if(op.size()==0) printf("0 0.0");
	for(auto i=op.rbegin(); i!=op.rend(); ++i) {
		if(cnt) printf(" ");
		printf("%d %.1lf",i->first,i->second);
		cnt++;
	}
	printf("\n");
	int flag=0;
	for(int i=maxn2-1; i>=0; i--) {
		if(fabs(a[i])>=0.05) {
			flag++;
		}
	}
	cnt=0;
	printf("%d ",flag);
	if(!flag) printf("0 0.0");
	else {
		for(int i=maxn2-1; i>=0; --i) {
			if(fabs(a[i])>=0.05) {
				if(cnt) printf(" ");
				printf("%d %.1lf",i,a[i]);
				cnt++;
			}
		}
	}
}

