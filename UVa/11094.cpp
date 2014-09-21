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

int VALUE=0,m,n;
int dx[4]={-1,0,0,1},
	dy[4]={0,-1,1,0};
char LAND;
vector<vb> visited;

void flood(vs &v,const int &x,const int &y){
	if(!(x>=0 && x<m && y>=0 && y<n && v[x][y]==LAND && !visited[x][y]))return;
	visited[x][y]=true;
	++VALUE;
	int nx,ny;
	for(int i=0;i<4;++i){
		nx=x+dx[i],ny=y+dy[i];
		if(ny==n)ny=0;
		else if(ny==-1)ny=n-1;
		if(nx>=0 && nx<m && ny>=0 && ny<n && v[nx][ny]==LAND && !visited[nx][ny]) flood(v,nx,ny);
	}
}

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	int x,y;
	int largest;
	vs v;
	while(cin>>m>>n){
		largest=0;
		v.clear();
		visited.clear();
		v.resize(m);
		visited.resize(m,vb(n,0));
		for(int i=0;i<m;++i)cin>>v[i];
		cin>>x>>y;
		LAND=v[x][y];
		flood(v,x,y);

		for(int i=0;i<m;++i)
			for(int j=0;j<n;++j)
				if(v[i][j]==LAND && !visited[i][j]){
					VALUE=0;
					flood(v,i,j);
					largest=max(largest,VALUE);
				}
		cout<<largest<<'\n';
	}

	return 0;
}
