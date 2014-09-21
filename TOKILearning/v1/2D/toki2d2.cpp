#include <iostream>
#include <vector>
using namespace std;

vector<int> s,a;

void add(int m){
	int n;
	cin>>n;
	for(int i=0;i<n;i++) s.push_back(m);
	a.push_back(s.size());
}

void del(int n){
	a.push_back(s.back());
	for(int i=0;i<n;i++) s.pop_back();
}

void adx(int n){
	unsigned int len=s.size();
	for(unsigned int i=0;i<len;i++) s[i]+=n;
}

void dex(int n){
	unsigned int len=s.size();
	for(unsigned int i=0;i<len;i++) s[i]-=n;
}

int main(){
	int n,x;
	cin>>n;
	string s;
	for(int i=0;i<n;i++){
		cin>>s>>x;
		if(s=="add") add(x);
		else if(s=="del") del(x);
		else if(s=="adx") adx(x);
		else dex(x);
	}
	for(unsigned int i=0;i<a.size();i++) cout<<a[i]<<"\n";
	return 0;
}
