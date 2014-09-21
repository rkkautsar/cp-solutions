
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


vector<vb> adjmatrix;

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	int t,n,m,u,v;
	ll count;

	cin>>t;

	while(t--){
		adjmatrix.clear();
		cin>>n>>m;
		adjmatrix.resize(n,vb(n,false));
		while(m--){
			cin>>u>>v;
			adjmatrix[u-1][v-1]=true;
			adjmatrix[v-1][u-1]=true;
		}
		count=0;
		for(int a=0;a<n-2;++a){
			for(int b=a+1;b<n-1;++b){
				if(adjmatrix[a][b]==false)continue;
				for(int c=b+1;c<n;++c){
					if(adjmatrix[b][c]==false || adjmatrix[a][c]==false)continue;
					++count;
				}
			}
		}
		cout<<count<<'\n';
	}

	return 0;
}
