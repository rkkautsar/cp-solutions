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

string digit="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	ll t,n,b,d;
	cin>>t;
	while(t--){
		cin>>n>>b>>d;
		if(n==2 && b==2){
			cout<<"1\n";
			continue;
		}
		ll i=min(n,d);
		while(i--){
			if(i>n/2){
				cout<<digit[b-1];
			} else if(i==n/2){
				cout<<digit[b-2];
			} else if(i==0){
				cout<<digit[1];
			} else {
				cout<<digit[0];
			}
		}
		cout<<'\n';
	}

	return 0;
}
