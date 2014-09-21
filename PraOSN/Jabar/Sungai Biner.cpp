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

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	string dummy;
	getline(cin,dummy);

	ll x0,y0,x1,y1;
	cin>>x0>>y0>>x1>>y1;
	int offset=60-y1;
	x0>>=offset;
	x1>>=offset;
	y0+=offset;
	y1+=offset;

	ll count=0;
	bool sebelum=false;
	for(int i=0;i<(y1-y0+1);++i){
		if(x1&(1LL<<i)){
			if(!sebelum) ++count;
		} else sebelum=false;
	}
	//cout<<count<<'\n';

	count+=ceildiv(x1-x0,2);

	cout<<count<<'\n';

	return 0;
}
