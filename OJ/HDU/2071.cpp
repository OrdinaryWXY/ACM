#include<iostream>
#include<algorithm>

using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;cin>>n;double a[110];
		for(int i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+n);
		printf("%.2lf\n",a[n-1]);
	}	
	return 0;
}
 
