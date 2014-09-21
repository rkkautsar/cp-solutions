#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

queue<int> q;
vector<int> a;
stack<int> t;
int x,y;

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
	cin>>x>>y;
	for(int i=0;i<y;i++) q.push(x);
	a.push_back(q.size());
}

void del(){
	cin>>x;
	a.push_back(q.front());
	for(int i=0;i<x;i++) q.pop();
}
	

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	string s;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		if (s=="add") add();
		else if (s=="del") del();
		else rev();
	}
	for(unsigned i=0;i<a.size();i++) cout<<a[i]<<"\n";
	return 0;
}
