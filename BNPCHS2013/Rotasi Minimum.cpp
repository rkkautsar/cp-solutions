//IO
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
 
//C Header
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
 
//container
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
 
//misc
#include <algorithm>
#include <functional>
#include <limits>
#include <string>
 
using namespace std;
 
// typedef
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<double,double> dd;
typedef pair<int,ii> iii;
typedef pair<double,dd> ddd;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<ii> vii;
typedef vector<dd> vdd;
typedef vector<vi> vvi;
typedef vector<vd> vvd;
typedef vector<vc> vvc;
 
//defines
#define abs(_x) ((_x)<0?-(_x):(_x))
#define REP(_x) for(int __x=0;__x<_x;++__x)
#define mp(_x,_y) make_pair((_x),(_y))
#define mp3(_x,_y,_z) make_pair((_x),(mp(_y,_z)))
#define fir first
#define sec second
#define PI 3.1415926535897932385
#define EPS 1e-9
#define PHI 1.6180339887498948482
#define INF 0x7FFFFFFF
#define INFLL 0x7FFFFFFFFFFFFFFFLL
#define readl(_s) getline(cin,_s);cin.ignore(9999,'\n')
 
//functions
template<class T,class Type> 
inline void reset(T begin, T end, Type fills=0){
	fill(begin,end,fills);
}
template<class T,class Type>
inline void reset(T stdcontainer, Type fills=0){
	fill(stdcontainer.begin(),stdcontainer.end(),fills);
}
template<class T,class Type>
inline void mfill(T container, int r, int c, Type fills=0){
	for(int i=0;i<r;++i)
		fill(container[i],container[i]+c,fills);
}
 
int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t,m,im,n=9,a,b;
	bool ketemu;
	string s;
	cin>>t;
	for(int x=1;x<=t;++x){
		cout<<"Kasus #"<<x<<": ";
		m=10,im=0;
		cin>>s;

		//getmin
		for(int i=0;i<n;++i){
			if(s[i]-'0'<m && s[i]!='0')m=s[i]-'0',im=i;
		}
		bool testsama=false;
		for(int i=1;i<n;++i){
			if(s[i]!=s[i-1])break;
			else if(i==n-1) testsama=1;
		}
		if(testsama){
			cout<<s<<'\n';
			continue;
		}
		for(int i=0;i<n;++i){
			if(s[i]==s[im] && i!=im){
				a=i,b=im;
				a=(a==8?0:a+1);
				b=(b==8?0:b+1);
				if(s[a]<s[b])im=i;
				else {
					while(s[a]==s[b]){
					if(a!=i && b!=im){
						a=(a==8?0:a+1);
						b=(b==8?0:b+1);
					}
					if(s[a]< s[b])im=i;
					}
				}
			}
		}

		for(int i=im;i<n;++i)cout<<s[i];
		for(int i=0;i<im;++i)cout<<s[i];
		cout<<'\n';
		
	}

	return 0;
}
