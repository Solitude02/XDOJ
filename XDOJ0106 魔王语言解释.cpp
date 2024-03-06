//xdoj0106.cpp
#include<algorithm>
#include<iostream>
#include<stack>
#include<queue>
using namespace std;

/*
In:B(einxgz)B
Out:tsaedsae ezegexeneie tsaedsae

//B(pxyzABhij)B
//tsaedsaepjpiphptsaedsaepsaepzpypxptsaedsae
*/	

int main(){
	string MonsterWord;
	cin>>MonsterWord;
	stack<char> S,Final;
	queue<char> Q;
	
	for(int p=0;p<MonsterWord.size();p++){
		if(MonsterWord[p]!=')'){
			S.push(MonsterWord[p]);
		}
		else{// ��ʱMonsterWord[p]=')' 
			while(S.top()!='('){//���������������У�zgxnie 
				Q.push(S.top());
				S.pop();
			}//��ʱS.top()=='('
			S.pop(); 
			while(Q.size()>1){
				S.push(Q.back());
				S.push(Q.front());
				Q.pop();
			}
			S.push(Q.back());
			Q.pop();
		}
	}//���Ŵ������
	
	while(!S.empty()){
		Final.push(S.top());
		S.pop();
	} 
	while(!Final.empty()){
		if(Final.top()=='A')
			cout<<"sae";
		else if(Final.top()=='B')
			cout<<"tsaedsae";
		else
			cout<<Final.top();
		Final.pop();
	}
    return 0;
}
