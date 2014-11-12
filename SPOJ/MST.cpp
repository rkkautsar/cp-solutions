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
typedef pair<int,ii> iii;
typedef vector<iii> viii;
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
#define W first
#define U second.first
#define V second.second

vi p;

int find(int x){
	if(p[x]==x) return x;
	else return p[x]=find(p[x]);
}

bool sameset(int a,int b){
	return find(a)==find(b);
}

void gabung(int a,int b){
	if(!sameset(a,b)){
		p[find(a)]=find(b);
	}
}



int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	int n,m;
	cin>>n>>m;
	viii edge;
	edge.resize(m);
	p.resize(n);
	int count=n;
	for(int i=0;i<n;++i) p[i]=i;
	int u,v,w;
	for(int i=0;i<m;++i){
		cin>>u>>v>>w;
		--u;
		--v;
		edge[i]=mp(w,mp(u,v));
	}
	sort(edge.begin(),edge.end());

	ll cost=0;

	for(int i=0;i<m && count;++i){
		w=edge[i].W;
		u=edge[i].U;
		v=edge[i].V;
		if(!sameset(u,v)){
			gabung(u,v);
			cost+=w;
			--count;
		}
	}

	cout<<cost<<'\n';


	return 0;
}
