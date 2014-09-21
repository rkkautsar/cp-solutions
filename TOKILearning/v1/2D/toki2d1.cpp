#include <iostream>
#include <list>
#include <vector>
using namespace std;

list <int> q;
vector <int> a;
int n,x,y;
string s;

void add(){
	cin>>x>>y;
	for(int i=0;i<y;i++) q.push_back(x);
	a.push_back(q.size());
}

void del(){
	cin>>x;
	a.push_back(q.front());
	for(int i=0;i<x;i++) q.pop_front();
}

int main(){
	ios_base::sync_with_stdio(false);
	cin>>n;
	for(int j=0;j<n;j++){
		cin>>s;
		if (s=="add") add();
		else if (s=="del") del();
		else q.reverse();
	}
	for(unsigned i=0;i<a.size();i++) cout<<a[i]<<"\n";
	return 0;
}
