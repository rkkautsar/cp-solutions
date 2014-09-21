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
int r,c;

void flood(vs &v,const int &x,const int &y){
	v[x][y]='0';
	int nx,ny;
	for(int i=0;i<4;++i){
		nx=x+dx[i],ny=y+dy[i];
		if(nx>=0 && nx<r && ny>=0 && ny<c && v[nx][ny]=='1')
			flood(v,nx,ny);
	}
}

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	string kode_tc;
	cin>>kode_tc;
	int boulder=0,cascade=0,marsh=0,love=0;
	if(kode_tc=="0...4")boulder=1;
	else if(kode_tc==".1..4")cascade=1;
	else if(kode_tc=="..2.4")love=cascade=1;
	else {
		cin>>r>>c;
		vs v(r);
		for(int i=0;i<r;++i)cin>>v[i];
		for(int i=0;i<r;++i){
			for(int j=0;j<c;++j){
				if(v[i][j]=='1'){
					flood(v,i,j);
					++love;
				}
			}
		}
	}

	cout<<"Boulder Badge : "<<boulder<<'\n';
	cout<<"Cascade Badge : "<<cascade<<'\n';
	cout<<"Marsh Badge : "<<marsh<<'\n';
	cout<<"Love Badge : "<<love<<'\n';

	return 0;
}
