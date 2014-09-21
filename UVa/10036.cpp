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
 
bool memo[150][10005][100],hit[150][10005][100];
vi v;

bool f(int n,int idx,int k,string indent=""){
	cout<<indent<<"f("<<n<<','<<idx<<','<<k<<")=\n";
	if(idx<-1 || k<2){
		cout<<indent<<0<<'\n';
		return 0;
	}
	if(idx>=0 && hit[n][idx][k]){
		cout<<indent<<memo[n][idx][k]<<'\n';
		return memo[n][idx][k];
	}
	if(idx==-1 && n%k==0){
		cout<<indent<<1<<'\n';
		return 1;
	}
	else if(idx==-1 && n%k!=0){
		cout<<indent<<0<<'\n';
		return 0;
	}
	if(idx>0) {
		hit[n][idx][k]=1;
		memo[n][idx][k]=f((n+v[idx])%k,idx-1,k,indent+"  ")|f((n-v[idx])%k,idx-1,k,indent+"  ");
		cout<<indent<<memo[n][idx][k]<<'\n';
		return memo[n][idx][k];
	}
	else {
		hit[n][idx][k]=1;
		memo[n][idx][k]=f((n+v[idx])%k,idx-1,k,indent+"  ");
		cout<<indent<<memo[n][idx][k]<<'\n';
	}
}

int main(int argc, char **argv){

	for(int i=0;i<150;++i){
		mfill(memo[i],10005,100,false);
		mfill(hit[i],10005,100,false);
	}
	
	int t,n,k;
	cin>>t;
	while(t--){
		cin>>n>>k;
		v.resize(n);
		for(int i=0;i<n;++i)cin>>v[i];
		cout<<(f(0,n-1,k)?"Divisible\n":"Not divisible\n");
	}

	return 0;
}
