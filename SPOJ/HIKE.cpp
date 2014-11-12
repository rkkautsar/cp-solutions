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

struct tiga{
	int a,b,c;
	tiga(int x,int y,int z) : a(x), b(y), c(z) {}
	tiga() : a(0), b(0), c(0) {}
};

int visited[55][55][55];

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	int n,a,b,c;
	pair<tiga,int> now;
	tiga t;
	vvi adj;
	string s;
	queue<pair<tiga,int> > q;

	bool udah;
	while(cin>>n && n){
		cin>>a>>b>>c;

		for(int i=0;i<55;++i)
			for(int j=0;j<55;++j)
				for(int k=0;k<55;++k)
					visited[i][j][k]=-1;

		adj.clear();
		adj.resize(n,vi(n));
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j){
				cin>>s;
				adj[i][j]=(int)s[0];
			}

		q.push(mp(tiga(a-1,b-1,c-1),0));
		udah=false;
		while(!q.empty()){
			now=q.front();
			t=now.first;
			q.pop();
			//cerr<<t.a<<' '<<t.b<<' '<<t.c<<' '<<now.second<<'\n';
			visited[t.a][t.b][t.c]=now.second;
			if(t.a==t.b && t.b==t.c){
				cout<<now.second<<'\n';
				udah=true;
				break;
			}

			for(int i=0;i<n;++i){
				if(adj[t.a][i] == adj[t.b][t.c] && visited[i][t.b][t.c]==-1){
					q.push(mp(tiga(i,t.b,t.c),now.second+1));
				}
				if(adj[t.b][i] == adj[t.a][t.c] && visited[t.a][i][t.c]==-1){
					q.push(mp(tiga(t.a,i,t.c),now.second+1));
				}
				if(adj[t.c][i] == adj[t.a][t.b] && visited[t.a][t.b][i]==-1){
					q.push(mp(tiga(t.a,t.b,i),now.second+1));
				}
			}
		}

		if(udah){
			while(!q.empty())q.pop();
			continue;
		} else {
			while(!q.empty())q.pop();
			cout<<"impossible\n";
			continue;
		}

	}

	return 0;
}
