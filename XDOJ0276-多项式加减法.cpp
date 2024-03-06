#include<iostream> // ������Ҫ��ͷ�ļ�
#include<new>
using namespace std;

struct LNode{
	int x;//ϵ�� 
	int m;//���� 
	LNode *next;
};

LNode* InitLinkList(int n){
	LNode *L=new (std::nothrow) LNode; // ʹ�� std::nothrow ����
	if (L == NULL) { // ��鷵��ֵ�Ƿ�Ϊ��
		cout << "Memory allocation failed." << endl;
		return NULL;
	}
	L->next=NULL;
	L->m=n;//��¼���� 
	return L; 
}

LNode* CreateNode(int x,int m){//����һ���ڵ㲢��ֵ 
	LNode *q;
	q=new (std::nothrow) LNode; // ʹ�� std::nothrow ����
	if (q == NULL) { // ��鷵��ֵ�Ƿ�Ϊ��
		cout << "Memory allocation failed." << endl;
		return NULL;
	}
	q->x=x;
	q->m=m;
	q->next=NULL;
	return q;
}

void Append(LNode **p,int tmpx,int tmpm){
	LNode *q;
	q=CreateNode(tmpx,tmpm);
	(*p)->next=q;
	*p=q;
}

LNode* Add(LNode *L,int tmpx,int tmpm){
	LNode *p,*q;
	q=CreateNode(tmpx,tmpm);
	p=L;
	while(p->next != NULL && p->next->m>q->m){ // ���� p->next != NULL ������
		p=p->next;
	}
	if(p->next != NULL && p->next->m==q->m)//�ݴ�һ�� ,��� 
		p->next->x+=q->x; // �޸�Ϊ x ������ m
	else{//�ݴβ�һ�������� 
		q->next=p->next;
		p->next=q;
		L->m++;
	}
	if (p->next->x == 0) { // ���ϵ��Ϊ�㣬ɾ���ڵ�
		LNode *temp = p->next;
		p->next = temp->next;
		delete temp;
		L->m--;
	}
	return L;
}

LNode* Minus(LNode *L,int tmpx,int tmpm){
	LNode *p,*q;
	q=CreateNode(-tmpx,tmpm);//ϵ���ø������ӷ���Ϊ���� 
	p=L;
	while(p->next != NULL && p->next->m>q->m){ // ���� p->next != NULL ������
		p=p->next;
	}
	if(p->next != NULL && p->next->m==q->m)//�ݴ�һ�� ,��� 
		p->next->x+=q->x; 
	else{//�ݴβ�һ�������� 
		q->next=p->next;
		p->next=q;
		L->m++;
	}
	if (p->next->x == 0) { // ���ϵ��Ϊ�㣬ɾ���ڵ�
		LNode *temp = p->next;
		p->next = temp->next;
		delete temp;
		L->m--;
	}
	return L;
}

void MyPrint(LNode *L){
	LNode *p;
	p=L->next;
	if (L->m == 0) { // �������Ϊ�գ���� 0
		cout << "0" << endl;
		return;
	}
	cout<<L->m<<" ";
	while(p){
		cout<<p->x<<" "<<p->m<<" ";
		p = p->next;
	}
	cout<<endl;
}

int main(){
//	��������
/*
4 1 10 2 5 3 4 4 0
4 1 8 -2 5 3 3 4 1
*/	

//	�ݴβ�һ�����в��룬�ݴ�һ��������ӻ���� 
	int n1,n2,tmpx,tmpm;
	cin>>n1;
	LNode *p1,*p2,*L1,*L2;
	L1=InitLinkList(n1);//��ʼ������ 
	L2=InitLinkList(n1);
	p1=L1;//ָ��ָ������ 
	p2=L2;
	for(int i=0;i<n1;i++){
		cin>>tmpx>>tmpm;
		Append(&p1,tmpx,tmpm);
		Append(&p2,tmpx,tmpm);
	}
	
	cin>>n2;
	for(int i=0;i<n2;i++){
		cin>>tmpx>>tmpm;
		L1=Add(L1,tmpx,tmpm);
		L2=Minus(L2,tmpx,tmpm);
	}
	MyPrint(L1);
	MyPrint(L2);
	return 0;
}

