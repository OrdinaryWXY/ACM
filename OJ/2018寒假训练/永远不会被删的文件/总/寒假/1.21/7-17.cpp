#include<stdio.h>
//����if�ظ��ı� ��дȫ����ɴ�д 
int main(void)
{
	char s[35];
	for(int i=0;i<35;i++)
	{
		scanf("%c",&s[i]);
		if(s[i]=='#')
			break;
		if(s[i]>=65&&s[i]<=90)//xiao xie
			s[i]+=32;
		else if(s[i]>=97&&s[i]<=122)
			s[i]-=32;
		
	}
	
	
	for(int i=0;i<35;i++)
	{	
		if(s[i]=='#')
			break;
		printf("%c",s[i]);
		
	}
		
	return 0;
}


