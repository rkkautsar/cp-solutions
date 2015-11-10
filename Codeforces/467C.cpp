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
typedef vector<vll> vvll;
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

int n,m,k;
vll v;
vvll dp;

ll sum(int a,int b){
	ll ret=0;
	for(int i=a;i<=b;++i)ret+=v[i];
	return ret;
}

ll f(int pos,int rem){
	if(pos<0 || rem<0) return 0;
	if(pos-m+1<0) return dp[pos][rem]=0;
	// cout<<"here\n";
	if(rem==0) return dp[pos][rem]=0;
	// cout<<pos<<' '<<rem<<' ';
	// cout<<dp[pos][rem]<<'\n';
	if(dp[pos][rem]!=-1) return dp[pos][rem];
	return dp[pos][rem]=
			max(
				f(pos-1,rem),
				f(pos-m,rem-1) + sum(pos-m+1,pos)
			);
}


int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	cin>>n>>m>>k;
	v.resize(n);
	dp.resize(n,vll(k+1,-1));
	for(int i=0;i<n;++i)cin>>v[i];
	cout<<f(n-1,k)<<'\n';


	return 0;
}
