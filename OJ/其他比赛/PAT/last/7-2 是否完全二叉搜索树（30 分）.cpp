#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;
int a[105],b;
int n;
void add(int i,int d)//��ӵ�ͬʱ��a�������ź���
{
    if(a[i] == -1)
    {
        a[i] = d;
        return;
    }
    if(d > a[i])
        add(i*2,d);
    else
        add(i*2+1,d);
}
int main()
{
    cin>>n;
    memset(a,-1,sizeof(a));
    for(int i = 0;i < n;i ++)
    {
        cin>>b;
        add(1,b);//��һ�β���Ǹ��ڵ�
    }
    int flag = 0,i = 0;
    //flag�Ǽ�¼���������������н������������������ʽ
    //i�����ж��Ƿ�����ȫ�������ģ���i == n + 1����һ����
    //��Ϊa[0]�϶���-1��һ����i++��i����1��һ��Ҫע�����Ǵ��±�1��ʼ��ʼ����ģ�
    //�����������ȫ��������iһ����n��һ��
    while(flag < n)
    {
        while(a[i] == -1)i++;//
        if(flag)
            cout<<" "<<a[i];
        else
            cout<<a[i];
        i++;
        flag++;
    }
    if(i == n + 1)//��ʱ����ȫ������
    {
        cout<<endl;
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<endl;
        cout<<"NO"<<endl;
    }
}

