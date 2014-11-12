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

vs v;
int x,y;
int d[1005][1005];
bool vis[1005][1005];
int c,r;

int dx[4]={-1,0,0,1},
	dy[4]={0,-1,1,0};

void dfs(int a,int b){
	vis[a][b]=true;
	if(d[a][b]>d[x][y]){
		x=a,y=b;
	}
	int nx,ny;
	for(int i=0;i<4;++i){
		nx=a+dx[i];
		ny=b+dy[i];
		if(nx>=0 && nx<r && ny>=0 && ny<c && v[nx][ny]=='.' && !vis[nx][ny]){
			d[nx][ny]=d[a][b]+1;
			dfs(nx,ny);
		}
	}
}

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	int t;
	cin>>t;
	while(t--){
		cin>>c>>r;
		v.resize(r);
		memset(d,-1,sizeof(d));
		memset(vis,0,sizeof(vis));
		for(int i=0;i<r;++i)cin>>v[i];

		bool udah=false;
		for(int i=0;i<r && !udah;++i)
			for(int j=0;j<c && !udah;++j)
				if(v[i][j]=='.'){
					//cout<<i<<' '<<j<<'\n';
					x=i;
					y=j;
					d[i][j]=0;
					dfs(i,j);
					udah=true;
				}

		//cout<<x<<' '<<y<<'\n';

		memset(d,-1,sizeof(d));
		memset(vis,0,sizeof(vis));
		d[x][y]=0;
		dfs(x,y);

		//cout<<x<<' '<<y<<'\n';

		cout<<"Maximum rope length is "<<d[x][y]<<".\n";
	}

	return 0;
}
