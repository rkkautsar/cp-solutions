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
 
//defines
#define abs(_x) ((_x)<0?-(_x):(_x))
#define REP(_x) for(int __x=0;__x<_x;++__x)
#define mp(_x,_y) make_pair((_x),(_y))
#define PI 3.1415926535897932385
#define EPS 1e-9
#define INF 0x7FFFFFFF
#define INFLL 0x7FFFFFFFFFFFFFFFLL
#define ceildiv(_a,_b) ((_a)%(_b)==0?(_a)/(_b):((_a)/(_b))+1)

int r,c;


int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	cin>>r>>c;
	vs v(r);
	vvi dp(r,vi(c));
	
	for(int i=0;i<r;++i)cin>>v[i];

	for(int i=0;i<r;++i)
		for(int j=0;j<c;++j){
			if(v[i][j]=='x')dp[i][j]=INF;
			else if(j==c-1) dp[i][j]=0;
		}

	int ans=INF;
	for(int j=max(0,c-2);j>=0;--j)
		for(int i=0;i<r;++i){
			if(dp[i][j]==INF)continue;
			dp[i][j]=INF;
			if(dp[i][j+1]!=INF)dp[i][j]=min(dp[i][j],dp[i][j+1]);
			if(i>0 && dp[i-1][j+1]!=INF && v[i][j+1]=='.') dp[i][j]=min(dp[i][j],1+dp[i-1][j+1]);
			if(i<r-1 && dp[i+1][j+1]!=INF && v[i][j+1]=='.') dp[i][j]=min(dp[i][j],1+dp[i+1][j+1]);
			if(j==0) ans=min(ans,dp[i][j]);
		}

	if(ans==INF)cout<<-1<<'\n';
	else cout<<ans<<'\n';

	/*for(int i=0;i<r;++i){
		for(int j=0;j<c;++j)cout<<(dp[i][j]==INF?8:dp[i][j])<<' ';cout<<'\n';
	}*/

	return 0;
}
