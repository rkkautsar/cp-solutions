#include <iostream>
#include <vector>
using namespace std;

vector <long> s,a;
long len=0,f=0;

inline void add(long m){
	long n;
	cin>>n;
	len+=n;
	a.push_back(len);
	for(long i=0;i<n;i++) s.push_back(m);
}

inline void del(long n){
	a.push_back(s.back()+f);
	for(long i=0;i<n;i++) s.pop_back();
	len-=n;
}
	

int main(){
	ios_base::sync_with_stdio(false);
	long n,x;
	cin>>n;
	string s;
	for(long i=0;i<n;i++){
		cin>>s>>x;
		if(s=="add") add(x); else if(s=="del") del(
		x); else if(s=="adx") f+=x; else f-=x;
	}
	for(vector<long>::iterator i=a.begin();i<a.end();i++)cout<<*i<<"\n";
	return 0;
}

	
