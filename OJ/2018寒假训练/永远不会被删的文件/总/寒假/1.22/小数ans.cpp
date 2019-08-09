#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int Gcd_(int x,int y)
{
    return y? Gcd_(y, x % y) : x;
}

void Get_ans(char *s)
{
    int len=strlen(s);
    int a=0,b=0;
    int M1=0,M2=0;
    int flag=0;//�ж��Ƿ�Ϊѭ��С�� 
    for(int i = 2; i < len; i++)
    {
        if(s[i] == '(')
            break;
        a = a * 10 + s[i] - '0';
        M1++;//��ĸ��0�ĸ���
    }
    for(int i = 2; i < len; i++)
    {
        if(s[i] == '(' || s[i] == ')')
        {
            flag = 1;
            continue;
        }
        b = b * 10 + s[i] - '0';
        M2++;
    }
    M2 -= M1;//��ĸ9�ĸ���
    int Num = b - a;//����
    int Den = 0;//��ĸ
    if(!flag)
    {
        Num = b;
        Den = 1;
        M2 = 0;
    }
    for(int i = 0; i < M2; i++)
        Den = Den * 10 + 9;
    for(int i = 0; i < M1; i++)
        Den *= 10;
    int Gcd = Gcd_(Num, Den);
    Den /= Gcd;
    Num /= Gcd;
    printf("%d/%d\n", Num, Den);
    return;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char s[20];
        scanf("%s", s);
        Get_ans(s);
    }
    return 0;
}
