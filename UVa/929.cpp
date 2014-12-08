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

int mat[1000][1000],dist[1000*1000];
int r,c,n;
int dx[]={-1,0,0,1},
	dy[]={0,-1,1,0};

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	int tc,u,v,w,nx,ny;
	cin>>tc;
	vector<vii> adj;
	priority_queue<ii,vii,greater<ii> > pq;
	while(tc--){
		cin>>r>>c;
		adj.clear();
		adj.resize(r*c);
		n=r*c;
		for(int i=0;i<r;++i)
			for(int j=0;j<c;++j){
				cin>>mat[i][j];
				dist[i*c+j]=INF;
			}

		for(int i=0;i<r;++i){
			for(int j=0;j<c;++j){
				for(int k=0;k<4;++k){
					nx=i+dx[k];
					ny=j+dy[k];
					if(nx>=0 && nx<r && ny>=0 && ny<c)
						adj[i*c+j].push_back(mp(nx*c+ny,mat[nx][ny]));
				}
			}
		}

		dist[0]=mat[0][0];
		pq.push(mp(0,0));
		while(!pq.empty()){
			w=pq.top().fi;
			u=pq.top().se;
			pq.pop();
			if(u==n-1){
				while(!pq.empty())pq.pop();
				break;
			}
			if(w>dist[u]) continue;
			for(int i=0;i<adj[u].size();++i){
				v=adj[u][i].fi;
				w=adj[u][i].se;
				if(dist[u]+w<dist[v]){
					dist[v]=dist[u]+w;
					pq.push(mp(dist[v],v));
				}
			}
		}

		//for(int i=0;i<n;++i)cout<<dist[i]<<(i==n-1?'\n':' ');

		cout<<dist[n-1]<<'\n';
	}

	return 0;
}

/*
2
4 5
0 3 1 2 9
7 3 4 9 9
1 7 5 5 3
2 3 4 2 5
1 6
0 1 2 3 4 5
*/