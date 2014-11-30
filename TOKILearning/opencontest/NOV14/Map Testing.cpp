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

int n,m,k;
int dx[4]={-1,0,0,1},
	dy[4]={0,-1,1,0};
int v[1000][1000];
bool visited[1000][1000][2];

queue<ii> q;

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	int t,x,y,nx,ny;
	bool f;
	ii now;
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j){
				cin>>v[i][j];
				visited[i][j][0]=visited[i][j][1]=false;
			}

		while(!q.empty())q.pop();

		q.push(mp(0,0));
		while(!q.empty()){
			now=q.front();
			q.pop();
			x=now.first;
			y=now.second;
			visited[x][y][0]=true;
			int nx,ny;
			for(int i=0;i<4;++i){
				nx=x+dx[i];
				ny=y+dy[i];
				if(nx>=0 && nx<n && ny>=0 && ny<m && !visited[nx][ny][0] && v[nx][ny]-v[x][y]<=k)
					q.push(mp(nx,ny));
			}
		}

		q.push(mp(n-1,m-1));
		while(!q.empty()){
			now=q.front();
			q.pop();
			x=now.first;
			y=now.second;
			visited[x][y][1]=true;
			int nx,ny;
			for(int i=0;i<4;++i){
				nx=x+dx[i];
				ny=y+dy[i];
				if(nx>=0 && nx<n && ny>=0 && ny<m && !visited[nx][ny][1] && v[x][y]-v[nx][ny]<=k)
					q.push(mp(nx,ny));
			}
		}

		f=true;
		for(int i=0;i<n && f;++i)
			for(int j=0;j<m && f;++j){
				if(i==n-1 && j==m-1)continue;
				if(!visited[i][j][0])continue;
				if(!visited[i][j][1]){
					f=false;
					break;
				}
			}

		if(f) cout<<"YES\n";
		else cout<<"NO\n";
	}

	return 0;
}
