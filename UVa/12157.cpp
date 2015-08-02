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
	
	int t,n,dur,mile,juice;
	cin>>t;
	for(int _t=1;_t<=t;++_t){
		cout<<"Case "<<_t<<": ";
		cin>>n;
		mile=juice=0;
		while(n--){
			cin>>dur;
			mile+=10*(1+(dur/30));
			juice+=15*(1+(dur/60));
		}
		if(mile==juice)
			cout<<"Mile Juice "<<mile;
		else if(mile<juice)
			cout<<"Mile "<<mile;
		else
			cout<<"Juice "<<juice;

		cout<<'\n';
	}

	return 0;
}
