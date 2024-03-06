#include<iostream>
#include<cmath>
using namespace std;

struct LNode{
	int s,e;//系数和指数 
	LNode *next;
};

LNode *CreateNode(){
	LNode *p;
	p=new LNode;
	p->next=NULL;
	return p;
}

LNode *CreateLL(int n){//创建长度为n的多项式 
	LNode *p,*q,*L;
	int s,e;
	L=CreateNode();
	p=L;
	for(int i=0;i<n;i++){
		cin>>s>>e;
		q=CreateNode();
		q->s=s;
		q->e=e;
		
		p->next=q;
		p=p->next;
	}
	return L;
}

LNode *Option(LNode *L1,LNode *L2,int t){
	int sign;
	sign=pow(-1,t);
	LNode *p,*q,*tmp;

	q=L2->next;
	while(q){
		p=L1->next;
		tmp=p->next;
		while(tmp->e < q->e){
			p=p->next;
			tmp=p->next;
		}
		if(tmp->e == q->e){//相等进行系数加减 
			tmp->s+=sign*q->s;
			if(tmp->s==0){//系数为0删去节点 
				p->next=tmp->next;
				delete tmp;
			}
			q=q->next;
		}
		else{//指数不同，插入节点 
			tmp=q;
			q=q->next;
			tmp->next=p->next;
			p->next=tmp;
		} 
	}
}

//输出L表，以多项式形式输出
void Display(LNode *L){
    LNode *p=L->next;
    if(p==NULL){
        //p为空，则说明L1和L2运算后为0
        cout<<0;
        return;
    }
    while(p){
    	if(p->s < 0){//系数为负 
	    	if(p->s==-1){//系数-1 
	    		switch(p->e){
	    			case 0:
	    				cout<<"-1";
	    				break;
	    			case 1:
	    				cout<<"-x";
	    				break;
	    			default:
	    				cout<<"-x^"<<p->e;
	    				break;
				}
			}
			else{//系数-x 
				switch(p->e){
	    			case 0:
	    				cout<<p->s;
	    				break;
	    			case 1:
	    				cout<<p->s<<"x";
	    				break;
	    			default:
	    				cout<<p->s<<"x^"<<p->e;
	    				break;
				}
			}
		}
		else{//系数为正 
			if(p->s==1){//系数1 
				switch(p->e){
	    			case 0:
	    				cout<<"1";
	    				break;
	    			case 1:
	    				cout<<"x";
	    				break;
	    			default:
	    				cout<<"x^"<<p->e;
	    				break;
				}
			}
			else{//系数+x 
				switch(p->e){
	    			case 0:
	    				cout<<p->s;
	    				break;
	    			case 1:
	    				cout<<p->s<<"x";
	    				break;
	    			default:
	    				cout<<p->s<<"x^"<<p->e;
	    				break;
				}
			}
		}
		if(p->next&&p->next->s>0)
			cout<<"+";
    	p=p->next;
	}
    
}

int main(){
/*
6 3 0
1 0 1 1 -3 2 1 3 1 4 1 5
-1 3 -2 4 1 5	
*/	
	int n,m,t,s,e;//n项，m项，t=0：加法，t=1：减法 
	cin>>n>>m>>t;
	LNode *L1,*L2;
	L1=CreateLL(n);
	L2=CreateLL(m);
	
	Option(L1,L2,t);
	Display(L1);	
//	LNode *p=L1->next;	
//	while(p){
//		cout<<p->s<<" "<<p->e<<" ";
//		p=p->next; 
//	}
	return 0;
}
