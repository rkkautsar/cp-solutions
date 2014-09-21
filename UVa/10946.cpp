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
 
int m,n,X;
int dx[4]={-1,0,0,1},
	dy[4]={0,-1,1,0};
vector<pair<char,int> > rank;
vs v;

void f(int x,int y){
	int nx,ny;
	char now=v[x][y];
	v[x][y]='.';
	++X;
	for(int i=0;i<4;++i){
		nx=x+dx[i],ny=y+dy[i];
		if(nx>=0 && nx<m && ny>=0 && ny<n && v[nx][ny]==now)f(nx,ny);
	}
}

bool cmp(pair<char,int> a,pair<char,int> b){
	if(a.second==b.second)return a.first<b.first;
	else return a.second>b.second;
}

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	int problem=0;
	while(cin>>m>>n){
		if(m==0 && n==0)return 0;
		rank.clear();
		v.resize(m);
		pair<char,int> tmp;
		for(int i=0;i<m;++i)cin>>v[i];
		for(int i=0;i<m;++i)
			for(int j=0;j<n;++j)
				if(v[i][j]!='.'){
					X=0;
					tmp.first=v[i][j];
					f(i,j);
					tmp.second=X;
					rank.push_back(tmp);
				}
		sort(rank.begin(),rank.end(),cmp);
		cout<<"Problem "<<++problem<<":\n";
		for(int i=0,len=rank.size();i<len;++i){
			cout<<rank[i].first<<' '<<rank[i].second<<'\n';
		}
	}

	return 0;
}
