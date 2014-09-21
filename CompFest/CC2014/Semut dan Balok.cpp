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
	
	int test;
	double p,l,t,pintar;
	cin>>test;
	while(test--){
		cin>>p>>l>>t;
		pintar=min(sqrt((p+l)*(p+l)+t*t),min(sqrt((p+t)*(p+t)+l*l),sqrt((l+t)*(l+t)+p*p)));
		cout<<fixed<<setprecision(10)<<pintar<<' ';
		cout<<fixed<<setprecision(10)<<p+l+t<<' ';
		cout<<fixed<<setprecision(10)<<(sqrt(p*p+l*l+t*t))<<'\n';
	}

	return 0;
}
