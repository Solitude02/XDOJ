#include<iostream> // 包含必要的头文件
#include<new>
using namespace std;

struct LNode{
	int x;//系数 
	int m;//次数 
	LNode *next;
};

LNode* InitLinkList(int n){
	LNode *L=new (std::nothrow) LNode; // 使用 std::nothrow 参数
	if (L == NULL) { // 检查返回值是否为空
		cout << "Memory allocation failed." << endl;
		return NULL;
	}
	L->next=NULL;
	L->m=n;//记录项数 
	return L; 
}

LNode* CreateNode(int x,int m){//创建一个节点并赋值 
	LNode *q;
	q=new (std::nothrow) LNode; // 使用 std::nothrow 参数
	if (q == NULL) { // 检查返回值是否为空
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
	while(p->next != NULL && p->next->m>q->m){ // 加上 p->next != NULL 的条件
		p=p->next;
	}
	if(p->next != NULL && p->next->m==q->m)//幂次一样 ,相加 
		p->next->x+=q->x; // 修改为 x 而不是 m
	else{//幂次不一样，插入 
		q->next=p->next;
		p->next=q;
		L->m++;
	}
	if (p->next->x == 0) { // 如果系数为零，删除节点
		LNode *temp = p->next;
		p->next = temp->next;
		delete temp;
		L->m--;
	}
	return L;
}

LNode* Minus(LNode *L,int tmpx,int tmpm){
	LNode *p,*q;
	q=CreateNode(-tmpx,tmpm);//系数置负，将加法变为减法 
	p=L;
	while(p->next != NULL && p->next->m>q->m){ // 加上 p->next != NULL 的条件
		p=p->next;
	}
	if(p->next != NULL && p->next->m==q->m)//幂次一样 ,相减 
		p->next->x+=q->x; 
	else{//幂次不一样，插入 
		q->next=p->next;
		p->next=q;
		L->m++;
	}
	if (p->next->x == 0) { // 如果系数为零，删除节点
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
	if (L->m == 0) { // 如果链表为空，输出 0
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
//	输入样例
/*
4 1 10 2 5 3 4 4 0
4 1 8 -2 5 3 3 4 1
*/	

//	幂次不一样进行插入，幂次一样进行相加或相减 
	int n1,n2,tmpx,tmpm;
	cin>>n1;
	LNode *p1,*p2,*L1,*L2;
	L1=InitLinkList(n1);//初始化链表 
	L2=InitLinkList(n1);
	p1=L1;//指针指向链表 
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

