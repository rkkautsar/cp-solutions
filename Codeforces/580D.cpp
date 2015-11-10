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
#define bitcount(_x) __builtin_popcount(_x)

int n,m,k,u,v,w;
ll  satisfaction[20],
	bonus[20][20],
	dp[(1<<19)][20];

ll f(int bitmask, int last){
	if(dp[bitmask][last]!=-1) return dp[bitmask][last];
	if(bitcount(bitmask)>=m) return dp[bitmask][last]=0;

	dp[bitmask][last]=0;
	// cout<<"dp["<<bitmask<<"]["<<last<<"]\n";
	int now;
	for(int i=0;i<n;++i){
		if(bitmask&(1<<i)) continue;
		now = satisfaction[i];
		if(bonus[i][last]!=-1) now += bonus[i][last];
		// cout<<i<<" setelah "<<last<<" -> "<<now<<'\n';
		dp[bitmask][last]=max(	dp[bitmask][last],
								now+f(bitmask|(1<<i),i) );
	}

	// cout<<"dp["<<bitmask<<"]["<<last<<"] = "<<dp[bitmask][last]<<'\n';
	return dp[bitmask][last];
}

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>m>>k;
	
	for(int i=0;i<n;++i)
		cin>>satisfaction[i];
	memset(bonus,-1,sizeof bonus);
	for(int i=0;i<k;++i){
		cin>>u>>v>>w;
		--u,--v;
		bonus[u][v]=w; // bonus jika u dimakan setelah v
	}	

	memset(dp,-1,sizeof dp);

	cout<<f(0,19)<<'\n';
	
	return 0;
}
