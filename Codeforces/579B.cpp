#include <bits/stdc++.h>
using namespace std;
 
// typedef
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<double,double> dd;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int,ii> iii; 

// macros
// #define __debug

#ifndef __debug
	#define IO_INIT() ios_base::sync_with_stdio(0);cin.tie(0)
	#define debug(_x) cerr<<(_x)<<'\n'
	#define debugArray(_array,_size) for(int ___i=0;___i<(_size);++___i)cout<<(__array[___i])<<(___i==(_size)-1?'\n':' ')
#else
	#define IO_INIT() {}
	#define debug(_x) {}
	#define debugArray(_array,_size) {}
#endif

#define abs(_x) ((_x)<0?-(_x):(_x))
#define REP(_a,_b) for(int (_a)=0;(_a)<(_b);++(_a))
#define mp(_x,_y) make_pair((_x),(_y))
#define PI 3.1415926535897932385
#define EPS 1e-9
#define INF 0x00FFFFFF
#define INFLL 0x00FFFFFFFFFFFFFFLL
#define ceildiv(_a,_b) ((_a)%(_b)==0?(_a)/(_b):((_a)/(_b))+1)
#define fi first
#define se second

int main(int argc, char **argv){
	IO_INIT();

	int n,x;
	cin>>n;
	vector<iii> v;
	vi p(2*n,-1);

	for(int i=1;i<2*n;++i){
		for(int j=0;j<i;++j){
			cin>>x;
			v.push_back(mp(x,mp(i,j)));
		}
	}

	int len=v.size();

	sort(v.begin(),v.end(),greater<iii>());

	for(int i=0;i<len;++i){
		if(p[v[i].se.fi]<0 && p[v[i].se.se]<0){
			p[v[i].se.fi] = v[i].se.se;
			p[v[i].se.se] = v[i].se.fi;
		}
	}

	for(int i=0;i<2*n;++i){
		cout<<p[i]+1<<(i==2*n-1?'\n':' ');
	}
	
	return 0;
}
