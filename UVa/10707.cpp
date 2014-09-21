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
 
int m,n,X,nx,ny;
int dx[4]={-1,0,0,1},
	dy[4]={0,-1,1,0};
vi ranka,rankb;
vvi v;

void f(int x,int y){
	v[x][y]=0;
	++X;
	for(int i=0;i<4;++i){
		nx=x+dx[i],ny=y+dy[i];
		if(nx>=0 && nx<m && ny>=0 && ny<n && v[nx][ny]==1)f(nx,ny);
	}
}


int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	int q,t,x,y;
	cin>>t;
	while(t--){
		ranka.clear(),rankb.clear();
		cin>>m>>n>>q;
		v.assign(m,vi(n,0));

		for(int i=0;i<q;++i){
			cin>>x>>y;
			v[x][y]=1;
		}
		//for(int i=0;i<m;++i){for(int j=0;j<n;++j)cout<<v[i][j];cout<<'\n';}cout<<'\n';
		for(int i=0;i<m;++i)
			for(int j=0;j<n;++j)
				if(v[i][j]==1){
					X=0;
					f(i,j);
					ranka.push_back(X);
				}
		v.assign(m,vi(n,0));
		for(int i=0;i<q;++i){
			cin>>x>>y;
			v[x][y]=1;
		}
		for(int i=0;i<m;++i)
			for(int j=0;j<n;++j)
				if(v[i][j]==1){
					X=0;
					f(i,j);
					rankb.push_back(X);
				}
		sort(ranka.begin(),ranka.end());
		sort(rankb.begin(),rankb.end());
		for(int i=0,len=ranka.size();i<len;++i)cout<<ranka[i]<<'\n';cout<<'\n';
		for(int i=0,len=rankb.size();i<len;++i)cout<<rankb[i]<<'\n';cout<<'\n';
		if(ranka.size()!=rankb.size()){
			cout<<"NO\n";
			continue;
		}
		for(int i=0,len=ranka.size();i<len;++i){
			if(ranka[i]!=rankb[i])cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";

	}

	return 0;
}
