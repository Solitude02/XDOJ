#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,a[100]={0},i,j,b[100]={0};
//	flag=0�����ǵȲ����� 
	cin>>n;
	int min,temp;
	unsigned int min_minus=65535,max_minus=0;
//	���ڼ�¼�����С��ֵ 
	for(i=1;i<n+1;i++){
		cin>>a[i];
		b[i]=i;		
	}
	for(i=1;i<n+1;i++){
		min=a[b[i]];
		for(j=i+1;j<n+1;j++)
			if(a[b[j]]<min){
				min=a[b[j]];
//				Ѱ����Сֵ 
				temp=b[j];
				b[j]=b[i];
				b[i]=temp;
//				����λ����� 
			}	
		if(i>1&&(a[b[i]]-a[b[i-1]])<min_minus) min_minus=a[b[i]]-a[b[i-1]];
		if(i>1&&(a[b[i]]-a[b[i-1]])>max_minus) max_minus=a[b[i]]-a[b[i-1]];
	}
	if(max_minus!=min_minus) cout<<max_minus<<" "<<min_minus;
	else{
		for(i=1;i<n+1;i++)
			cout<<b[i]<<" ";
	}
	return 0;
} 
