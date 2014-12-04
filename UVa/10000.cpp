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

int dist[105];

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	int n,s,u,v,mx,tc=0;
	vvi adj;
	while(cin>>n && n){
		cin>>s;
		memset(dist,-9999999,sizeof(dist));
		dist[s-1]=0;
		adj.clear();
		adj.resize(n);
		while(cin>>u>>v && u && v){
			adj[u-1].push_back(v-1);
		}

		for(int k=0;k<n;++k){
			for(int u=0;u<n;++u){
				if(dist[u]<0)continue;
				for(int i=0;i<adj[u].size();++i){
					v=adj[u][i];
					if(dist[u]+1>dist[v])dist[v]=dist[u]+1;
				}
			}
		}

		mx=s-1;
		for(int i=0;i<n;++i)
			if(dist[i]>dist[mx])mx=i;

		cout<<"Case "<<++tc<<": The longest path from "<<s<<" has length "<<dist[mx]<<", finishing at "<<mx+1<<".\n\n";

	}

	return 0;
}
