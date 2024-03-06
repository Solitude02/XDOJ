//xdoj0258.c
#include<iostream>
using namespace std;
#include<stdlib.h>
#define MAXSIZE 100000 //address�ǷǸ�5λ����

typedef struct LNode{
    int data;
    int next;
}LNode;

LNode Nodes[MAXSIZE];//������飬�±�Ϊaddress

void Display(LNode Nodes[],int p){
    while(p!=-1){
        if(Nodes[p].next==-1){
            printf("%05d %d -1",p,Nodes[p].data);
        }else{
            printf("%05d %d %05d\n",p,Nodes[p].data,Nodes[p].next);
        }
        p=Nodes[p].next;
    }
}

void DeleteNode(LNode Nodes[],int p,int address){
    //��������Ҫɾ���Ľ���ַ
    while(Nodes[p].next != address){
        p=Nodes[p].next;
    }
    Nodes[p].next=Nodes[address].next;
}

int main(){
    int n,p,index;
    cin>>p>>n;

    for(int i=0;i<n;i++){
        cin>>index;
        cin>>Nodes[index].data>>Nodes[index].next;
    }

	for(int i=p;i!=-1;i=Nodes[i].next){
        for(int j=Nodes[i].next;j!=-1;j=Nodes[j].next){//���� 
            if(Nodes[i].data == Nodes[j].data || Nodes[i].data == -Nodes[j].data){
                //abs��ͬ��ɾ����һ�����
                DeleteNode(Nodes,p,j);
                n--;
            }
        }
    }
    cout<<n<<endl;
    Display(Nodes,p);
    return 0;
}

