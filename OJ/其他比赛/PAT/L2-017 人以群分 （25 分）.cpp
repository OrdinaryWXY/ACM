#include<bits/stdc++.h>
using namespace std;
int main() {
	multiset<int> op;//����Ļ�Ծ�ȿ�����ͬ������Ҫʹ��multiset����,��������set����
	int n;
	cin>>n;
	int m=n;
	int ma=0,mi=0;
	int d;
	for(int i=0; i!=n; ++i) {
		scanf("%d",&d);
		op.insert(d);
	}
	int j;
	j=0;
	n%2==0?n=n:n=n+1;//�ж�n�Ƿ�Ϊż�������nΪż�������������͵�������һ���ģ����n��
	//�������������͵������������͵�������һ
	for(auto i=op.begin(); j<m/2; ++i,++j) {
		ma+=*i;//ǰһ���������opΪset�������Զ���������
	}
	j=0;
	for(auto i=op.rbegin(); j<n/2; ++j,++i) {
		mi+=*i;
	}
	printf("Outgoing #: %d\n",n/2);
	printf("Introverted #: %d\n",m/2);
	printf("Diff = %d",mi-ma);
}

