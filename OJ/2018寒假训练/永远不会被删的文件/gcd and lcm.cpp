

int gcd(int x,int y)//�ݹ� 
{
	return y?gcd(y,x%y):x;
}
int  Gcd(int x,int y)//ѭ�� 
{
    while(y)
    {
        int temp=x;
        x=y;
        y=temp%y;
    }
    return x;
}
typedef  
lcm=r/gcd(r,n)*n;


