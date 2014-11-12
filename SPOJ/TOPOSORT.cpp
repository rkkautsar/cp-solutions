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
#define WHITE 0
#define GREY 1
#define BLACK 2


vvi adj;
vi topo,color;
bool gabisa=false;

void dfs(int idx){
	color[idx]=GREY;
	int next;
	for(int i=adj[idx].size()-1;i>=0;--i){
		next=adj[idx][i];
		if(color[next]==WHITE){
			dfs(next);
		} else if(color[next]==GREY){
			cout<<"Sandro fails.\n";
			exit(0);
		}
	}
	color[idx]=BLACK;
	topo.push_back(idx);
}

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	int n,m,a,b;
	cin>>n>>m;
	adj.resize(n);
	color.assign(n,WHITE);
	for(int i=0;i<m;++i){
		cin>>a>>b;
		adj[a-1].push_back(b-1);
	}

	for(int i=0;i<n;++i) sort(adj[i].begin(),adj[i].end());

	for(int i=n-1;i>=0;--i){
		if(color[i]==WHITE){
			dfs(i);
		}
	}

	for(int i=topo.size()-1;i>=0;--i) cout<<topo[i]+1<<(i==0?'\n':' ');

	return 0;
}
