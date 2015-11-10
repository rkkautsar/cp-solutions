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

struct pos{
	int x,y,d;
	pos(){}
	pos(int a,int b,int c){
		x=a;y=b;d=c;
	}
};

int n,m;
vs v;

bool safe(int r,int c,int d){
	if(r<0 || r>=n  || c<0 || c>=m)return false;
	if(c+d*2>=m)return true;
	return (v[r][c+d*2]=='.');
}

int main(int argc, char **argv){
	// ios_base::sync_with_stdio(0);
	// cin.tie(0);

	int tc,s;
	// vs v;
	vector<vb> visited;
	queue<pos> q;
	pos now;
	cin>>tc;
	while(tc--){
		cin>>m>>n;
		n=3;
		v.resize(n);
		visited.resize(n,vb(m,false));
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				visited[i][j]=false;

		for(int i=0;i<n;++i)cin>>v[i];

		for(int i=0;i<n;++i)
			if(v[i][0]=='s'){
				s=i;break;
			}

		while(!q.empty())q.pop();
		q.push(pos(s,0,0));
		while(!q.empty()){
			now=q.front();
			q.pop();
			visited[now.x][now.y]=true;

			if(!safe(now.x,now.y+1,now.d))continue;

			// cout<<now.x<<' '<<now.y<<' '<<now.d<<'\n';
			if(safe(now.x-1,now.y+1,now.d+1) && !visited[now.x-1][now.y+1]) q.push(pos(now.x-1,now.y+1,now.d+1));
			if(safe(now.x  ,now.y+1,now.d+1) && !visited[now.x  ][now.y+1]) q.push(pos(now.x  ,now.y+1,now.d+1));
			if(safe(now.x+1,now.y+1,now.d+1) && !visited[now.x+1][now.y+1]) q.push(pos(now.x+1,now.y+1,now.d+1));
		}
		// return 0;
		bool f=false;

		// for(int i=0;i<n;++i){
		// 	for(int j=0;j<m;++j)cout<<visited[i][j];
		// 	cout<<'\n';
		// }
		for(int i=0;i<n && !f;++i){
			// cout<<visited[i][m-1]<<'\n';
			if(visited[i][m-1])f=true;
		}

		if(f)cout<<"YES\n";
		else cout<<"NO\n";

	}
	
	return 0;
}
