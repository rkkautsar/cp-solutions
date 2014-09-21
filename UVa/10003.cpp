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
#define ceildiv(_a,_b) ((_a)%(_b)==0?(_a)/(_b):((_a)/(_b))+1)
 
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

vi v;
vvi memo;
int l,n;

int cut(int a,int b){
	if(a==b-1)return 0;
	if(memo[a][b]!=-1)return memo[a][b];
	memo[a][b]=INF;
	for(int i=a+1;i<b;++i){
		memo[a][b]=min(memo[a][b],cut(a,i)+cut(i,b)+v[b]-v[a]);
	}
	return memo[a][b];
}



int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	

	do{
		cin>>l;
		if(!l)return 0;
		cin>>n;
		v.resize(n+2);
		memo.resize(n+2,vi(n+2,-1));
		v[0]=0;
		for(int i=1;i<=n;++i)cin>>v[i];
		v[n+1]=l;
		cout<<"The minimum cutting is "<<cut(0,n+1)<<".\n";
		v.clear();
		memo.clear();
	}while(1);

	return 0;
}
