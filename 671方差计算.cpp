#include<stdio.h>
#include<math.h>

int main()
{
	int n=0,x[30]={0},i,x_ba,p=0,sum=0;;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x[i]);
		sum+=x[i];
	}
	x_ba=int(sum/n);
	for(i=0;i<n;i++)
		p+=pow((x[i]-x_ba),2);
	p=int(p/n);
	printf("%d\n",p);
	return 0;
 } 
