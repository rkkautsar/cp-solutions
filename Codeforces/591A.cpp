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

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	double l,p,q;
	cin>>l>>p>>q;
	double t,sp,sq;
	t = l / (p+q);
	sp = p * t;
	sq = q * t;
	

	if(sp/p < sq/q) {
		sp = (sq/q - sp/p) * p;
		sq = 0;
	} else {
		sq = (sp/p - sq/q) * q;
		sp = 0;
	}
	
	t = (l - sp - sq)/(p + q);

	cout<<fixed<<setprecision(12)<<p * t<<'\n';
	
	return 0;
}
