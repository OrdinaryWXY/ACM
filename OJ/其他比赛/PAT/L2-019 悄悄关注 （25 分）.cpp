#include<bits/stdc++.h>
using namespace std;
int main() {
	set<string> op;//�����û���ע���˵�����
	map<string,int> o;//���汻�����û�id�͵��޴���
	int n;
	cin>>n;
	string c;
	for(int i=0; i!=n; ++i) {
		cin>>c;//�˴�����scanf���Ч�ʣ�����char kk[15] scanf����%s����kk����c=kk��scanf��ȡ��Ч��Զ����cin��
		//���������ܴ���������Ч�ļ��ٺ�ʱ������ԭ�����г�ʱ�Ĵ��룬��cin��Ϊscanf����ܻ�ͨ��
		op.insert(c);
	}
	double av=0;
	int m;
	int d;
	cin>>m;
	for(int i=0; i!=m; ++i) {
		cin>>c>>d;
		av+=d;
		o[c]=d;
	}
	av/=m;
	int cnt=0;
	for(auto i=o.begin(); i!=o.end(); ++i) {
		if(i->second>av&&!op.count(i->first)) { //���û�id�����޴�������ƽ��ֵ�Ҳ��ٱ���ע����op��
			cout<<i->first<<endl;
			cnt++;
		}
	}
	if(!cnt) printf("Bing Mei You");
}

