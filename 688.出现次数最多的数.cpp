#include <iostream>
using namespace std;
int main()
{   
    int n;
    cin>>n;
    int a[1024];
    for(int i=1;i<=n;i++)
    cin>>a[i];
    int b[10010]={0};//�����±�������������ֵ����������ֵĴ���
	for(int i=1;i<=n;i++)
    {   
        int b_i=a[i];
	    b[b_i]++;
    }
	int max=0;  //Ĭ�ϴ�����0 
	int ans;        
	for( int i=1;i<10010;i++)
	{
		if(b[i]>max&&b[i]!=0) // ���ڱ�֤�����������ಢ������������С�� 
		{
			 max=b[i]; //������������� 
			 ans=i;
		}
	     
	}
	cout<<ans<<endl;
	return 0;	                                                           
}

