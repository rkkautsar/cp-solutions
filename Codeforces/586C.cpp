#include <bits/stdc++.h>
using namespace std;
 
// typedef
typedef long long ll;
typedef pair<ll,ll> ii;
typedef pair<double,double> dd;
typedef vector<ll> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<bool> vb;

#define abs(_x) ((_x)<0?-(_x):(_x))
#define REP(_a,_b) for(ll (_a)=0;(_a)<(_b);++(_a))
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

	ll n;
	cin>>n;
	vi v(n),d(n),p(n);
	vb udah(n,false);
	for(ll i=0;i<n;++i)
		cin>>v[i]>>d[i]>>p[i];

	vi ans;
	ll idx=0;
	for(ll i=0;i<n;++i){
		// cout<<i<<' '<<p[i]<<'\n';
		if(p[i]<0)continue;
		ans.push_back(i+1);
		udah[i]=true;
		for(ll j=i+1;j<n;++j){
			if(v[i] && p[j]>=0) p[j]-=(v[i]--);
		}

		for(int j=i+1;j<n;++j){
			if(p[j]<0 && !udah[j]){
				udah[j]=true;
				for(ll k=j+1;k<n;++k) p[k]-=d[j];
			}
		}
		// for(ll j=0;j<n;++j)
		// 	cout<<p[j]<<' ';cout<<'\n';
	}

	cout<<ans.size()<<'\n';
	for(ll i=0,len=ans.size();i<len;++i){
		cout<<ans[i]<<(i==len-1?'\n':' ');
	}
	
	
	return 0;
}
