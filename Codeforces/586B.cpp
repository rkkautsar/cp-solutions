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

	int n;
	cin>>n;
	vi a(n-1),b(n-1),c(n);
	for(int i=0;i<n-1;++i)cin>>a[i];
	for(int i=0;i<n-1;++i)cin>>b[i];
	for(int i=0;i<n;++i)cin>>c[i];

	int ans=INF,cost;
	for(int i=0;i<n;++i)
	for(int j=0;j<n;++j){
		if(i==j)continue;

		cost = 0;
		for(int k=i;k<n-1;++k)cost+=b[k];
		cost+=c[i];
		for(int k=0;k<i;++k)cost+=a[k];

		for(int k=0;k<j;++k)cost+=a[k];
		cost+=c[j];
		for(int k=j;k<n-1;++k)cost+=b[k];

		ans=min(ans,cost);
	}

	cout<<ans<<'\n';

	return 0;
}
