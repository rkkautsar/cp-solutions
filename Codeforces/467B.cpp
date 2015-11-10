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

int diff(int a,int b){
	int ret=0;
	while(a || b){
		if((a&1) != (b&1))++ret;
		a>>=1;
		b>>=1;
	}
	return ret;
}

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	int n,m,k,fedor,c=0;
	cin>>n>>m>>k;
	vi v(m);
	for(int i=0;i<m;++i)cin>>v[i];
	cin>>fedor;
	for(int i=0;i<m;++i){
		if(diff(fedor,v[i])<=k)++c;
	}
	cout<<c<<'\n';

	return 0;
}
