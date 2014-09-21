#include <iostream>
#include <vector>
using namespace std;

vector <int> s,t; // vector s=stackNumber, vector t=stackFreq
vector <int>::iterator it;
int len=0;

inline void add(int m){
	int n;
	cin>>n;
	len+=n;
	cout<<len<<"\n";
	if(s.empty() || s.back()!=m){
		s.push_back(m);
		t.push_back(n);
	} else {
		t.back()+=n;
	}
}

inline void loopdel(int n){
	if(t.back()>n) t.back()-=n;
	else {
		n-=t.back();
		t.pop_back();
		s.pop_back();
		if(n!=0) loopdel(n);		
	}
}

inline void del(int n){
	cout<<s.back()<<"\n";
	len-=n;
	loopdel(n);
}

inline void adx(int n){
	it=s.begin();
	while(it!=s.end()){
		*it+=n;
		it++;
	}
}
	

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n,x;
	cin>>n;
	string s;
	for(int i=0;i<n;i++){
		cin>>s>>x;
		if(s[0]=='a'){
			if(s[2]=='d') add(x); //add
			else adx(x); //adx
		} else {
			if(s[2]=='l') del(x); //del
			else adx(-x); //dex
		}
	}
	return 0;
}
