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
	
	int t,w,a,b,diff;
	cin>>t;

	bool 	first=true,
			slide;

	while(t--){
		
		if(!first) cout<<'\n';
		else first=false;

		slide=true;
		
		cin>>w;
		cin>>a>>b;
		diff=a-b;
		w--;
		
		while(w--){
			cin>>a>>b;
			if(diff!=a-b)slide=false;
		}

		cout<<(slide?"yes":"no")<<'\n';
	}

	return 0;
}
