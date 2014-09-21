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
typedef vector<ll> vll;
 
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
	
	int m,n,x,l=0,r=0,ans=-1;
	ll jarak=0,mx;
	cin>>n>>m;
	vi kandang(m,0);
	for(int i=0;i<n;++i){
		cin>>x;
		--x;
		++kandang[x];
		if(x>0)++r;
		jarak+=x;
	}
	l=n-r;
	mx=-1;
	if(kandang[0]==0)ans=1,mx=jarak;
	//cout<<"1 = "<<jarak<<' '<<l<<' '<<r<<'\n';
	for(int i=1;i<m;++i){
		jarak-=r;
		jarak+=l;
		l+=kandang[i];
		r-=kandang[i];
		//cout<<i+1<<" = "<<jarak<<' '<<l<<' '<<r<<'\n';
		if(jarak>mx && kandang[i]==0)ans=i+1,mx=jarak;
	}

	cout<<ans<<'\n';

	return 0;
}
