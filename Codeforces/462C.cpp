#include <bits/stdc++.h>
using namespace std;
 
// typedef
typedef long long ll;
typedef vector<ll> vll;
typedef pair<int,int> ii;
typedef pair<double,double> dd;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<bool> vb;
 
//defines
#define abs(_x) ((_x)<0?-(_x):(_x))
#define REP(_x) for(int __x=0;__x<_x;++__x)
#define mp(_x,_y) make_pair((_x),(_y))
#define PI 3.1415926535897932385
#define EPS 1e-9
#define INF 0x7FFFFFFF
#define INFLL 0x7FFFFFFFFFFFFFFFLL
#define ceildiv(_a,_b) ((_a)%(_b)==0?(_a)/(_b):((_a)/(_b))+1)

vll v,sum;

ll f(int l,int r){
	ll score=1LL*sum[r]-(l>0?sum[l-1]:0);
	if(r<=l) return score;
	if(r-l+1==2){
		return score+f(l,l)+f(r,r);
	}

	return score+f(l,r-1)+f(r,r);
}

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	int n;
	cin>>n;
	v.resize(n);
	sum.resize(n,0);
	for(int i=0;i<n;++i) cin>>v[i];
	sort(v.begin(),v.end(),greater<int>());
	for(int i=0;i<n;++i){
		if(i==0)sum[i]=v[i];
		else sum[i]=sum[i-1]+v[i];
	}
	
	cout<<f(0,n-1)<<'\n';

	return 0;
}
