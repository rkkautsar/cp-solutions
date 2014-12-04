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
typedef vector<vii> vvii;
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

int dist[1005];

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	int tc,n,m,u,v,w;
	vvii adj;

	cin>>tc;
	while(tc--){
		cin>>n>>m;
		adj.clear();
		adj.resize(n);
		for(int i=0;i<m;++i){
			cin>>u>>v>>w;
			adj[u].push_back(mp(v,w));
		}

		memset(dist,INF,sizeof(dist));
		dist[0]=0;

		for(int k=0;k<n;++k){
			for(int u=0;u<n;++u){
				for(int i=0;i<adj[u].size();++i){
					v=adj[u][i].fi;
					w=adj[u][i].se;
					if(dist[u]+w<dist[v])dist[v]=dist[u]+w;
				}
			}
		}

		bool possible=false;

		for(int u=0;u<n && !possible;++u){
			for(int i=0;i<adj[u].size() && !possible;++i){
				v=adj[u][i].fi;
				w=adj[u][i].se;
				if(dist[u]+w<dist[v]){
					possible=true;
				}
			}
		}

		if(possible) cout<<"possible\n";
		else cout<<"not possible\n";

	}

	return 0;
}
