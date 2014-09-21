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
typedef vector<bool> vb;
 
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

int memo[27][10001][27];

int f(int l,int s,int last){
	if(l>26)return 0;
	if(l==0 && s==0)return 1;
	if(l==0 && s!=0)return memo[l][s][last]=0;
	if(memo[l][s][last]!=-1)return memo[l][s][last];
	memo[l][s][last]=0;
	for(int i=last+1;i<=min(26,s);++i)
		memo[l][s][last]+=f(l-1,s-i,i);
	return memo[l][s][last];
}

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	for(int i=0;i<27;++i)
		for(int j=0;j<10001;++j)
			for(int k=0;k<27;++k) memo[i][j][k]=-1;

	int l,s,_x=1;
	while(cin>>l>>s){
		if(l==0 && s==0)return 0;
		cout<<"Case "<<_x<<": "<<f(l,s,0)<<'\n';
		++_x;
	}

	return 0;
}
