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
#define MOD 1000000007

int korek[10]={6,2,5,5,4,5,6,3,7,6};
vi memo(100001,-1);

int f(int n){
	if(n<0) return 0;
	if(n==0) return 1;
	if(n<100001){
		if(memo[n]!=-1) return memo[n];
		memo[n]=0;
		for(int i=0;i<10;++i){
			if(n>=korek[i])memo[n]=(memo[n]+f(n-korek[i]))%MOD;
		}	
		return memo[n];
	}
}

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	

	
	int n,tmp;
	//cin>>n;
	for(int i=1;i<=7;++i)
		cout<<f(i)<<'\n';

	return 0;
}
