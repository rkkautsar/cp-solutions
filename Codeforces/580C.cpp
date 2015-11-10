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

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,m,u,v,cat;
	cin>>n>>m;
	vvi adj(n);
	vb cats(n),visit(n);
	for(int i=0;i<n;++i){
		cin>>u;
		cats[i]=(u==1);
		visit[i]=false;
	}
	for(int i=0;i<n-1;++i){
		cin>>u>>v;
		--u,--v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	queue<ii> q;
	q.push(ii(0,(cats[0]?1:0))); //idx 0 and 0 consecutive cats

	ii now;
	int ans=0;
	while(!q.empty()){
		now = q.front();
		q.pop();

		u 	= now.fi;
		cat = now.se;
		// cout<<"# "<<u<<' '<<cat<<'\n';

		visit[u] = true;

		if(adj[u].size()<=1 && u!=0){ //leaf
			++ans;
			// cout<<u<<" leaf\n";
			continue;
		}

		for(int i=0;i<adj[u].size();++i){
			v = adj[u][i];
			// cout<<"  > "<<v<<' '<<(cats[v]?1:0)<<'\n';
			if(visit[v]) continue;
			if(cats[v]){
				if(cat+1>m) continue;
				else q.push(ii(v,cat+1));
			} else q.push(ii(v,0));
		}
	}

	cout<<ans<<'\n';

	return 0;
}
