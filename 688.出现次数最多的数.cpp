#include <iostream>
using namespace std;
int main()
{   
    int n;
    cin>>n;
    int a[1024];
    for(int i=1;i<=n;i++)
    cin>>a[i];
    int b[10010]={0};//数组下标存这个数，数组值存这个数出现的次数
	for(int i=1;i<=n;i++)
    {   
        int b_i=a[i];
	    b[b_i]++;
    }
	int max=0;  //默认次数是0 
	int ans;        
	for( int i=1;i<10010;i++)
	{
		if(b[i]>max&&b[i]!=0) // 大于保证了输出的是最多并且是最多的中最小的 
		{
			 max=b[i]; //这个就是最大次数 
			 ans=i;
		}
	     
	}
	cout<<ans<<endl;
	return 0;	                                                           
}

