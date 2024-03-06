#include<bits/stdc++.h>
using namespace std;

int fold(int a[],int &count){
	int i,k;
	count/=2;
	for(i=0;i<count;i++){
		k=2*count-1-i;
		a[i]+=a[k];
	} 
	return count;
}
int main(){
	int n,m,i,a[64],count;
	cin>>n>>m;
	count=pow(2,n);
	for(i=0;i<count;i++){
		cin>>a[i];
	}
	for(i=0;i<m;i++){
		count=fold(a,count);
	}
	for(i=0;i<count;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
