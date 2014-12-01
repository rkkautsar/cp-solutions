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

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	int t;
	cin>>t;
	double x0,y0,x1,y1,cx,cy,r;
	while(t--){
		cin>>x0>>y0>>x1>>y1>>cx>>cy>>r;
		x1-=x0;
		cx-=x0;
		y1-=y0;
		cy-=y0;
		if(	fabs((y1/x1)-0.6)<EPS &&
			fabs((r/x1)-0.2)<EPS &&
			fabs(cx-0.45*x1)<EPS &&
			fabs(cy-0.5*y1)<EPS )
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}

	return 0;
}
