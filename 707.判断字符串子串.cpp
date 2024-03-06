#include<stdio.h>
bool comp(char m[],char s[],int n){
	int i,j;
	for(i=0,j=0;s[j]!='\0';i++,j++)
		if(m[n+i]!=s[j])
			return false;
	return true;
}
int main(){
	char m[20],s[20];
	gets(m);
	gets(s);
	int i,flag=0;
	for(i=0;m[i]!='\0';i++){
		if(comp(m,s,i)){
			flag=1;
			break;
		}
	}
	if(flag==1)
		printf("%d",i+1);
	else
		printf("No!");
	return 0;
}
