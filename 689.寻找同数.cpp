#include<bits/stdc++.h>
using namespace std;

int main() 
{
    char m[3],s[50];
    cin>>m>>s;
    int count=0;
	char *p=s,*q=m,*t=s;
	while(*p!='\0'){
		q=m;
		t=p;
		while(*t==*q){
			t++;
			q++;
		}
		if(*q=='\0') count++;
		p++;
	}
	cout<<count;
	return 0;
}
