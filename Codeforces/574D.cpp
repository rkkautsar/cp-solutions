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
	
	int n;
	cin>>n;
	vi v(n+2),tmp;
	for(int i=1;i<=n;++i)
		cin>>v[i];

	// precompute kiri
	vi left(n+2,0);
	for(int i=1;i<=n;++i)
		left[i]=min(left[i-1]+1, v[i-1]+1);

	// precompute kanan
	vi right(n+2,0);
	for(int i=n;i>=1;--i)
		right[i]=min(right[i+1]+1, v[i+1]+1);

	// ---
	int ans=0, now;
	for(int i=1;i<=n;++i){
		now=min(v[i],min(left[i],right[i]));
		ans=max(ans,now);
	}

	cout<<ans<<'\n';

	return 0;
}
