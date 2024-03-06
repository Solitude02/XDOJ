#include<bits/stdc++.h>
using namespace std;

int main(){
	int a[100],n,i,temp,j,b[2]={10};
	int *p,*q;
	cin>>a[0]>>a[1]>>n;
	p=&a[0];
	q=&a[1];
	for(i=2;i<n;){
		temp=(*p)*(*q);
		j=0;
		if(temp>9){
			a[i+1]=temp%10;
			temp/=10;
			a[i]=temp;
			i+=2;
		}else{
			a[i++]=temp;
		}
		p++;
		q++;
	}
	for(i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
