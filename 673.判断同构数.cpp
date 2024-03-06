#include<stdio.h>

int main(){
	int n=1,sq,x,s=1;
	scanf("%d",&n);
	x=n;
	sq=x*x;
	while(x>0&&sq%10==x%10){
		sq/=10;
		x/=10;
	}
	if(x>0)
		s=0;
	printf("%d %d",n,s);
	return 0;
}
