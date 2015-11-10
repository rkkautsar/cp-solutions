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
	vi v(n),mx(n+1),h(n);
	for(int i=0;i<n;++i)cin>>v[i];


	mx[n]=0;
	for(int i=n-1;i>=0;--i){
		if(v[i]>mx[i+1])h[i]=0;
		else h[i]=mx[i+1]-v[i]+1;
		mx[i]=max(v[i],mx[i+1]);
	}

	for(int i=0;i<n;++i)
		cout<<h[i]<<(i==n-1?'\n':' ');
	
	return 0;
}
