//xdoj0263.c

#include<iostream>
using namespace std;
#include<stdlib.h>
#define ElemType int

typedef struct LNode{
    ElemType data;
    struct LNode* next;
}LNode,*LinkList;


int main(){
    int n;
    ElemType e,tmp;
    LinkList L;
    LNode *p,*q;//动态指针，指向L表最后一个结点，方便创建L
    L=new LNode;
    L->next=NULL;
     cin>>n>>e;
    p=L;
    q=NULL;
    for(int i=0;i<n;i++){
        cin>>tmp;
        q=new LNode;
        q->data=tmp;
        q->next=NULL;
        p->next=q;
        p=p->next;
    }
    p=L;
    while(p){
    	if(p->next->data>e)
    		break;
    	p=p->next;
	}
	q=new LNode;
	q->data=e;
    q->next=p->next;
    p->next=q;
    p=L->next;
    while(p){
    	cout<<p->data<<" ";
    	p=p->next;
	}
    return 0;
}

