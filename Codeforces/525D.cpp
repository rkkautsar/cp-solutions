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

vs v;

int dx[4] = {1, 1,-1,-1},
	dy[4] = {1,-1, 1,-1};

int bx[8] = {-1,-1,-1,0,0,1,1,1},
	by[8] = {-1,0,1,-1,1,-1,0,1};

int n,m;

bool tembok_sendiri(const int &x,const int &y){
	if(v[x][y]!='*') return 0;
	int nx,ny;
	for(int i=0;i<4;++i){
		nx=x+dx[i];
		ny=y+dy[i];
		int c=0;
		if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
		if(v[nx][ny]=='.')++c;
		if(v[nx][y]=='.')++c;
		if(v[x][ny]=='.')++c;
		if(c==3) return 1;
	}
	
	return 0;
}

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	

	cin>>n>>m;
	v.resize(n);
	for(int i=0;i<n;++i)cin>>v[i];

	queue<ii> q;

	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j){
			if(tembok_sendiri(i,j)){
				v[i][j]='.';
				q.push(ii(i,j));
			}
		}

	int x,y,nx,ny;
	while(!q.empty()){
		x=q.front().fi;
		y=q.front().se;
		q.pop();
		// cout<<x<<' '<<y<<'\n';
		for(int i=0;i<8;++i){
			nx=x+bx[i];
			ny=y+by[i];
			if(nx>=0 && nx<n && ny>=0 && ny<m && tembok_sendiri(nx,ny)){
				v[nx][ny]='.';
				q.push(ii(nx,ny));
			}
		}
	}

	for(int i=0;i<n;++i)cout<<v[i]<<'\n';

	return 0;
}
