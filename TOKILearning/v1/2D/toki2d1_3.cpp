#include <cstdio>
#include <queue>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

queue<int> q;
vector<int> a,v;
stack<int> t;
int x,y;

inline void input(int &n);
inline void output(int n);

void rev(){
	unsigned sz=q.size();
	for(unsigned i=0;i<sz;i++){
		t.push(q.front());
		q.pop();
	}
	for(unsigned i=0;i<sz;i++){
		q.push(t.top());
		t.pop();
	}
}

void add(){
	input(x);input(y);
	for(int i=0;i<y;i++) q.push(x);
	a.push_back(q.size());
}

void del(){
	input(x);
	a.push_back(q.front());
	for(int i=0;i<x;i++) q.pop();
}
	

int main(){
	int n;
	string s;
	input(n);
	for(int i=0;i<n;i++){
		cin>>s;
		if (s=="add") add();
		else if (s=="del") del();
		else rev();
	}
	for(unsigned i=0;i<a.size();i++) {
		output(a[i]);
		putw(10,stdout);
	}
	return 0;
}

inline void input(int &n){
	n=0;
	int c=getchar_unlocked(),sign=1;
	while(c<'0' || c>'9')
		if(c=='-'){
			sign*=-1;
			c=getchar_unlocked();
		}
	while(c>='0' && c<='9'){
		n=n*10+c-'0';
		c=getchar_unlocked();
	}
	n*=sign;
}

inline void output(int n){
	int d=0;
	while(n>0){
		v.push_back(n%10);
		d++;	
		n/=10;
	}
	for(int i=0;i<d;i++){
		putw(v.back()+'0',stdout);
		v.pop_back();
	}
}
