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
typedef vector<vb> vvb;
 
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
	
	int n,m;
	cin>>n>>m;
	vii edgelist(m);
	vvb adjmat(n,vb(n,false));
	vi cnt(n,0);

	int u,v;
	for(int i=0;i<m;++i){
		cin>>u>>v;
		--u,--v;
		edgelist[i] = ii(u,v);
		++cnt[u];
		++cnt[v];
		adjmat[u][v]=adjmat[v][u]=true;
	}

	int ans=INF,now;
	//search triple
	bool found=false;
	for(int i=0;i<m;++i){
		u = edgelist[i].first;
		v = edgelist[i].second;
		for(int j=0;j<n;++j)
			if(adjmat[u][j] && adjmat[v][j]){
				//found triple
				found=true;
				//calc recognition
				ans=min(ans,cnt[u]+cnt[v]+cnt[j]-6);
			}
	}

	if(!found){
		cout<<-1<<'\n';
		return 0;
	}

	cout<<ans<<'\n';

	return 0;
}
