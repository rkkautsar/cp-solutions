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
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<bool> vb;
 
//defines
#define abs(_x) ((_x)<0?-(_x):(_x))
#define REP(_x) for(int __x=0;__x<_x;++__x)
#define mp(_x,_y) make_pair((_x),(_y))
#define PI acos(-1)
#define EPS 1e-9
#define INF 0x0FFFFFFF
#define INFLL 0x0FFFFFFFFFFFFFFFLL
#define ceildiv(_a,_b) ((_a)%(_b)==0?(_a)/(_b):((_a)/(_b))+1)
#define fi first
#define se second

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	int t,v,mx;
	string url;
	cin>>t;
	vs rank[101];
	for(int _t=1;_t<=t;++_t){
		cout<<"Case #"<<_t<<":\n";
		mx=0;

		for(int i=0;i<101;++i) rank[i].clear();

		for(int i=0;i<10;++i){
			cin>>url>>v;
			mx=max(mx,v);
			rank[v].push_back(url);
		}

		for(int i=0,len=rank[mx].size();i<len;++i)
			cout<<rank[mx][i]<<'\n';
	}

	return 0;
}
