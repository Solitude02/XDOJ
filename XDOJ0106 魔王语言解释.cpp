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
		else{// 此时MonsterWord[p]=')' 
			while(S.top()!='('){//括号里的内容入队列：zgxnie 
				Q.push(S.top());
				S.pop();
			}//此时S.top()=='('
			S.pop(); 
			while(Q.size()>1){
				S.push(Q.back());
				S.push(Q.front());
				Q.pop();
			}
			S.push(Q.back());
			Q.pop();
		}
	}//括号处理完毕
	
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
