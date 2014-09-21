#include <bits/stdc++.h>
using namespace std;
 
// typedef
typedef long long ll;
typedef vector<ll> vll;
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
#define MAX 1000001

vi nod(MAX,1);

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	for(int i=2;i<MAX;++i)
		for(int j=i;j<MAX;j+=i)
				++nod[j];

	vll N(MAX);
	N[0]=1;
	for(int i=1;i<MAX;++i){
		N[i]=N[i-1]+nod[N[i-1]];
		//cout<<N[i]<<' ';
	}
	//cout<<'\n';

	int t,a,b;
	cin>>t;
	for(int test=1;test<=t;++test){
		cin>>a>>b;
		cout<<"Case "<<test<<": "<<upper_bound(N.begin(),N.end(),b)-lower_bound(N.begin(),N.end(),a)<<'\n';
	}



	return 0;
}
