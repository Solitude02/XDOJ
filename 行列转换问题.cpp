#include<iostream>
using namespace std;

const int LP=100001;
int n,m,k;
int x[LP],y[LP],d[LP];
int c[LP];
int *a[LP];//ÿ��һ��ָ�룬׼�����롰���顱
 
int main(){
	cin>>n>>m>>k;//n��m��k������ 
	for(int i=1;i<=k;i++){
		cin>>x[i]>>y[i]>>d[i];
		c[y[i]]++;//��yi������һ��ֵ 
	}	
	for(int i=1;i<=m;i++){
		a[i]=new int[c[i]];//��i������̬���顱��Ϊc[i]
	}
	for(int i=1;i<=k;i++){
		*a[y[i]]=d[i];
		a[y[i]]++;//a[y[i]]��һ��ָ�룬����ĳһ�еĶ�̬����
 
	}
	for(int i=1;i<=m;i++){
		a[i]-=c[i];
		for(int j=1;j<=c[i];j++,a[i]++){
			cout<<*a[i]<<" ";
		}
	}
	return 0;
} 
