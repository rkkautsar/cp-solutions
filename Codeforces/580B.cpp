#include <bits/stdc++.h>
using namespace std;
 
// typedef
typedef long long ll;
typedef pair<long long,long long> ii;
typedef pair<double,double> dd;
typedef vector<long long> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<bool> vb;

#define abs(_x) ((_x)<0?-(_x):(_x))
#define REP(_a,_b) for(long long (_a)=0;(_a)<(_b);++(_a))
#define mp(_x,_y) make_pair((_x),(_y))
#define PI 3.1415926535897932385
#define EPS 1e-9
#define INF 0x00FFFFFF
#define INFLL 0x00FFFFFFFFFFFFFFLL
#define ceildiv(_a,_b) ((_a)%(_b)==0?(_a)/(_b):((_a)/(_b))+1)
#define fi first
#define se second

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	long long n,d;
	cin>>n>>d;
	vii v(n);
	for(long long i=0;i<n;++i)
		cin>>v[i].fi>>v[i].se;
	
	sort(v.begin(),v.end());

	int l=0,r=1;
	ll ans=v[0].se, sum = v[0].se;

	while(r<n){
		sum+=v[r].se;
		while(v[r].fi-v[l].fi>=d){
			sum-=v[l].se;
			++l;
		}
		ans=max(ans,sum);
		++r;
	}

	cout<<ans<<'\n';
	
	return 0;
}
