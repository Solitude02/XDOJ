#include<iostream>
using namespace std;

const int LP=100001;
int n,m,k;
int x[LP],y[LP],d[LP];
int c[LP];
int *a[LP];//每列一个指针，准备申请“数组”
 
int main(){
	cin>>n>>m>>k;//n行m列k行输入 
	for(int i=1;i<=k;i++){
		cin>>x[i]>>y[i]>>d[i];
		c[y[i]]++;//第yi列新增一个值 
	}	
	for(int i=1;i<=m;i++){
		a[i]=new int[c[i]];//第i个“动态数组”长为c[i]
	}
	for(int i=1;i<=k;i++){
		*a[y[i]]=d[i];
		a[y[i]]++;//a[y[i]]是一个指针，代表某一列的动态数组
 
	}
	for(int i=1;i<=m;i++){
		a[i]-=c[i];
		for(int j=1;j<=c[i];j++,a[i]++){
			cout<<*a[i]<<" ";
		}
	}
	return 0;
} 
