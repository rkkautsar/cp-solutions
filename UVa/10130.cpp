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
 
//functions
template<class T,class Type> 
inline void reset(T begin, T end, Type fills=0){
	fill(begin,end,fills);
}
template<class T,class Type>
inline void reset(T stdcontainer, Type fills=0){
	fill(stdcontainer.begin(),stdcontainer.end(),fills);
}

//GLOBAL DECLARATION
int t,n,g,a,b,p;
ll total=0;
vii v;
int memo[35][1005];
//FUNCTIONS
int f(int remaining,int index){
	if(remaining<=0) return 0;
	if(index<0) return 0;
	if(memo[remaining][index]!=-1) return memo[remaining][index];
	if(v[index].sec<=remaining)
		return memo[remaining][index]=max(
		v[index].fir+f(remaining-v[index].sec,index-1),
		f(remaining,index-1)
		);
	else return memo[remaining][index]=f(remaining,index-1);
}
 
int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	

	
	cin>>t;
	REP(t){
		for(int i=0;i<35;++i){
			fill(memo[i],memo[i]+1005,-1);
		}
		total=0;
		cin>>n;
		v.resize(n);
		for(int i=0;i<n;++i){
			cin>>a>>b;
			v[i]=mp(a,b);
		}
		cin>>g;
		while(g--){
			cin>>p;
			total+=f(p,n-1);
		}
		cout<<total<<'\n';
	}

	return 0;
}
