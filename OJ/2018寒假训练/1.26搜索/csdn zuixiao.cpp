int mix[max][max];//�ڽӾ���洢��Ӧ�ıߵ�Ȩ��

void prim(int n,int r)//prim�㷨ʵ��
{
	
	int a[max];//a[max]������Ÿ����㵽�Ѿ���ǵ�ļ��ϵ���̾���
	bool vis[max];//vis[max]������¼ÿ����ı��״̬��false��ʾ��û��ǡ�
	int i,j,k,min;
	
	for (i=0; i<n; i++)//��ʼ���Ӹ��ڵ㿪ʼ
	{
		a[i]=mix[r][i];
		vis[i]=false;
	}
	vis[r]=true;
	printf("/n���α���ǵĵ㼰��Ӧ�ߵ�Ȩ�أ�/n");
	printf("%d/t%d/n",r,0);
	for (i=0; i<n-1; i++) //��ʣn-1����
	{
		k=0;
		min=wq;
		for (j=0; j<n; j++)
		{
			//��j���㵽�Ѿ���ǵ�ļ��ϵľ�����С������㻹û�б����
			//k��¼��һ��������ǵĵ�
			if (a[j]<min&&vis[j]==false)
			{
				min=a[j];
				k=j;
			}
		}
		vis[k]=true;//��ǽڵ�k
		printf("%d/t%d/n",k,min);
		//����a[]���״̬��ʱ�̱������µ�״̬
		//��Ÿ����㵽�Ѿ���ǵ�ļ��ϵ���̾���
		for (j=0; j<n; j++)
		{
			if (mix[k][j]<a[j])
			{
				a[j]=mix[k][j];
			}
		}
	}
}
