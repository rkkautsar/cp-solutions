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

int dx[4]={-1,0,0,1},
	dy[4]={0,-1,1,0};

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	int n;
	cin>>n;
	vs v(n);
	for(int i=0;i<n;++i)cin>>v[i];

	int nx,ny;
	bool good=true;
	for(int i=0;i<n && good;++i){
		for(int j=0;j<n && good;++j){
			int c=0;
			for(int k=0;k<4;++k){
				nx=i+dx[k],ny=j+dy[k];
				if(nx>=0 && nx<n && ny>=0 && ny<n && v[nx][ny]=='o')++c;
			}
			if(c&1) good=false;
		}
	}
	if(good)cout<<"YES\n";
	else cout<<"NO\n";

	return 0;
}
