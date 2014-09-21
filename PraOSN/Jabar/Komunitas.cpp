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

bool musuh[16][16];
int a,b,n,m;

int f(int bitmask,int idx){
	if(idx==n) return 0;
	bool boleh=true;
	for(int i=0;i<m && boleh;++i)if(bitmask&(1<<i) && musuh[i][idx]) boleh=false;
	if(!boleh) return f(bitmask,idx+1);
	else return max(f(bitmask,idx+1),1+f(bitmask|(1<<idx),idx+1));
}

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	

	cin>>n>>m;
	for(int i=0;i<m;++i){
		cin>>a>>b;
		musuh[a-1][b-1]=musuh[b-1][a-1]=1;
	}
	cout<<f(0,0)<<'\n';

	return 0;
}
