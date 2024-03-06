#include<bits/stdc++.h>
using namespace std;

struct LNode{
	int data;
	LNode *next;
};
int main(){
	int n,m,tmp;
	cin>>n;
	LNode *p,*q,*L[n];
	for(int i=0;i<n;i++){
		L[i]=new LNode;
		L[i]->next=NULL;
		p=L[i];
		cin>>m;
		for(int j=0;j<m;j++){
			cin>>tmp;
			q=new LNode;
			q->data=tmp;
			q->next=p->next;
			p->next=q;
		}	
	}
	for(int i=0;i<n;i++){
		p=L[i]->next;
		while(p){
			cout<<p->data<<" ";
			p=p->next;
		}
		cout<<endl;
	}
	return 0;
}
