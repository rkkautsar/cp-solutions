#include <bits/stdc++.h>
using namespace std;
 
// typedef
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<double,double> dd;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<bool> vb;

#define abs(_x) ((_x)<0?-(_x):(_x))
#define REP(_a,_b) for(ll (_a)=0;(_a)<(_b);++(_a))
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

	int n;
	ll k,x;
	cin>>n>>k>>x;
	vll v(n),prefix(n),suffix(n);
	for(int i=0;i<n;++i)cin>>v[i];

	ll xpow=1;
	for(int i=0;i<k;++i)xpow*=x;

	prefix[0]=0;
	suffix[n-1]=0;

	for(int i=1;i<n;++i)
		prefix[i]=v[i-1]|prefix[i-1];
	for(int i=n-2;i>=0;--i)
		suffix[i]=v[i+1]|prefix[i+1];

	ll m=suffix[0];
	for(int i=0;i<n;++i)
		m=max(m,(v[i]*xpow)|prefix[i]|suffix[i]);
	
	cout<<m<<'\n';

	
	return 0;
}
