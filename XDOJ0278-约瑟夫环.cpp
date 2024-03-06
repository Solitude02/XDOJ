#include<iostream>
#include<new>
using namespace std;

typedef struct LNode{
	int num;
	int code;
	LNode *next;
}LNode,*LinkList; 

LinkList InitLinkList(){
	LinkList L;
	L=new LNode;
	L->next=NULL;
	
	return L;
}

int main(){
/*
in:
7 20
3 1 7 2 4 8 4
out:
6 1 4 7 2 3 5
*/
	int n,m,code;//n个人，初始密码为m 
	cin>>n>>m;
	LinkList L;
	LNode *p,*q;
	L=InitLinkList();
	p=L;
	for(int i=1;i<=n;i++){
		cin>>code;
		q=new LNode;
		q->num=i;
		q->code=code;
		q->next=L->next;
		
		p->next=q;
		p=p->next;
	}
	p=L;
	for(int i=1;i<=n;i++){
		for(int j=1;j<m;j++){
			p=p->next;
		}
		q=p->next;
		p->next=q->next;
		m=q->code;
		cout<<q->num<<" ";
		delete q;
	}
	return 0;
}
