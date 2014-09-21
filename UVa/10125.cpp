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

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	vector<ll> v;
	ll ans;
	int n,idx;
	while(cin>>n && n){
		v.resize(n);
		for(int i=0;i<n;++i)
			cin>>v[i];
		sort(v.begin(),v.end());

		ans=0;
		for(int i=0;i<n-3;++i)
			for(int j=i+1;j<n-2;++j)
				for(int k=j+1;k<n-1;++k){
					idx=distance(v.begin(),lower_bound(v.begin()+(k+1),v.end(),v[i]+v[j]+v[k]));
					if(idx<n && v[idx]==v[i]+v[j]+v[k]) ans=max(ans,v[idx]);
				}
					
		if(ans==0)
			cout<<"no solution\n";
		else
			cout<<ans<<'\n';
				
	}

	return 0;
}
