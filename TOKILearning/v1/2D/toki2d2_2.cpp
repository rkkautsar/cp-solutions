#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

vector<int> s,a;

void input(int &x)
{
    register int c = getchar_unlocked();
    x = 0;
    for(;(c<48 || c>57);c = getchar_unlocked());
    for(;c>47 && c<58;c = getchar_unlocked()) {x = x*10 + c - 48;}
}

void output(int res)
{
	int N = res , rev, count = 0;
	rev = N;
	if (N == 0) {
		putchar_unlocked('0');
		return ;
	}
	while ((rev % 10) == 0){ //itung nol
		count++;
		rev /= 10;
	}
	rev = 0; //nol lagi
	while (N != 0)	{
		rev = rev*10 + N % 10; //assign kebalik
		N /= 10;
	}
	while (rev != 0){
		putchar_unlocked(rev%10 + '0'); //tulis dari belakang
		rev /= 10;
	}	
	while (count--)	putchar_unlocked('0'); //tulis nol
}

inline void add(int m){
	int n;
	input(n);
	for(int i=0;i<n;i++) s.push_back(m);
	a.push_back(s.size());
}

inline void del(int n){
	a.push_back(s.back());
	for(int i=0;i<n;i++) s.pop_back();
}

inline void adx(int n){
	for(vector<int>::iterator i=s.begin();i<=s.end();i++) *i+=n;
}

inline void dex(int n){
	for(vector<int>::iterator i=s.begin();i<=s.end();i++) *i-=n;
}

int main(){
	cin.sync_with_stdio(false);
	int n,x;
	input(n);
	string s;
	for(int i=0;i<n;i++){
		cin>>s;
		input(x);
		if(s=="add") add(x); else if(s=="del") del(
		x); else if(s=="adx") adx(x); else dex(x);
	}
	for(unsigned int i=0;i<a.size();i++) {
		output(a[i]);
		putchar_unlocked('\n');
	}
	return 0;
}
