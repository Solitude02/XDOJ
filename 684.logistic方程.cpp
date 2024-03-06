#include<bits/stdc++.h>
using namespace std;

int main()
{
	float r,x[1001]={0.0};
	int n = 2,flag=0;
	cin>>x[1]>>r;
	for(n=2;n<1001;n++){
		x[n] = r*x[n-1]*(1-x[n-1]);
		if(fabs(x[n]-x[n-1])<0.00001){
			flag=1;
			break;
		} 
	}
	if(n<1000)
	cout<<setprecision(4)<<x[n]<<" "<<flag;
	else cout<<setprecision(4)<<x[1000]<<" "<<flag;
	return 0;
}
