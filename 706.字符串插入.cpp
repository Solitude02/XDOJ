#include<stdio.h>

int main(){
	char m[20]={'\0'},s[20]={'\0'};
	int n;
	gets(m);
	gets(s);
	scanf("%d",&n);
	char *p=&m[n],*q=s,*t=&m[n];
	while(*q!='\0')
		q++;
	while(*t!='\0'){
		*q=*t;
		t++;
		q++;
	}
	q=s;
	while(*q!='\0'){
		*p=*q;
		p++;
		q++;
	}
	p=m;
	while(*p!='\0'){
		printf("%c",*p);
		p++;
	}
	return 0;
}
