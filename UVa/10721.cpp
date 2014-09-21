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

int n,k,m;

int memo[55][55][55][2];

ll f(int idx,int bar,int used,bool dark){
	if(idx==n && bar==k) return 1;
	if(idx==n && bar!=k || bar==k && idx!=n) return 0;
	if(memo[idx][bar][used][dark]!=-1) return memo[idx][bar][used][dark];
	memo[idx][bar][used][dark]=0;
	if(used<m) memo[idx][bar][used][dark]+=f(idx+1,bar,used+1,dark);
	memo[idx][bar][used][dark]+=f(idx+1,bar+1,1,!dark);
	return memo[idx][bar][used][dark];
}

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	

	for(int i=0;i<55;++i)
		for(int j=0;j<55;++j)
			for(int k=0;k<55;++k)
				for(int l=0;l<2;++l)
					memo[i][j][k][l]=-1;

	// for(int i=0;i<55;++i)
	// 	for(int j=0;j<55;++j)
	// 		for(int k=0;k<55;++k)
	// 			for(int l=0;l<2;++l)
	// 				cout<<"("<<i<<','<<j<<','<<k<<','<<l<<") = "<<f(i,j,k,l)<<endl;

	while(cin>>n>>k>>m){
		cout<<f(0,1,1,1)<<'\n';
	}

	return 0;
}
