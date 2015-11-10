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

vi v;
int COUNT=0;

ll factorial[20];

void f(int idx,int rem,ll target){
	// cout<<idx<<' '<<rem<<' '<<target<<'\n';
	if(target==0) {
		++COUNT;
		return;
	}
	if(idx<0) return;

	if(v[idx]<=18 && rem && target>=factorial[v[idx]]){
		f(idx-1,rem-1,target-factorial[v[idx]]);
	}

	if(target>=v[idx]){
		f(idx-1,rem,target-v[idx]);
	}

	f(idx-1,rem,target);

}

int main(int argc, char **argv){
	// ios_base::sync_with_stdio(0);
	// cin.tie(0);	
	
	int n,k;
	ll s;
	cin>>n>>k>>s;
	v.resize(n);
	for(int i=0;i<n;++i)cin>>v[i];

	//precompute factorial
	factorial[0]=factorial[1]=1;
	for(int i=2;i<=18;++i) factorial[i]=factorial[i-1]*(ll)i;

	f(n-1,k,s); //gabisa dp :(
	cout<<COUNT<<'\n';

	return 0;
}
