#include<stdio.h>
#include<math.h>

int fac(int n){
	if(n<=1)
		return 1;
	else
		return n*fac(n-1);
}
int main(){
	int n=0,s=1;
	double x=0.0,sinx=0.0;
	scanf("%d %lf",&n,&x);
	for(int i=1;i<n+1;i++){
		sinx+=s*pow(x,2*i-1)/fac(2*i-1);
		s=-s;
	}
	printf("%.4lf",sinx);
	return 0;
}
