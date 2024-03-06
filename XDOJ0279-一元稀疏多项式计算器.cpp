#include<iostream>
#include<cmath>
using namespace std;

struct LNode{
	int s,e;//ϵ����ָ�� 
	LNode *next;
};

LNode *CreateNode(){
	LNode *p;
	p=new LNode;
	p->next=NULL;
	return p;
}

LNode *CreateLL(int n){//��������Ϊn�Ķ���ʽ 
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
		if(tmp->e == q->e){//��Ƚ���ϵ���Ӽ� 
			tmp->s+=sign*q->s;
			if(tmp->s==0){//ϵ��Ϊ0ɾȥ�ڵ� 
				p->next=tmp->next;
				delete tmp;
			}
			q=q->next;
		}
		else{//ָ����ͬ������ڵ� 
			tmp=q;
			q=q->next;
			tmp->next=p->next;
			p->next=tmp;
		} 
	}
}

//���L���Զ���ʽ��ʽ���
void Display(LNode *L){
    LNode *p=L->next;
    if(p==NULL){
        //pΪ�գ���˵��L1��L2�����Ϊ0
        cout<<0;
        return;
    }
    while(p){
    	if(p->s < 0){//ϵ��Ϊ�� 
	    	if(p->s==-1){//ϵ��-1 
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
			else{//ϵ��-x 
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
		else{//ϵ��Ϊ�� 
			if(p->s==1){//ϵ��1 
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
			else{//ϵ��+x 
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
	int n,m,t,s,e;//n�m�t=0���ӷ���t=1������ 
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
