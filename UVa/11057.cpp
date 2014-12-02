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
	
	vi v;
	int n,x,idx;
	while(cin>>n){
		v.assign(n,0);
		for(int i=0;i<n;++i)cin>>v[i];
		sort(v.begin(),v.end());
		cin>>x;
		idx=distance(v.begin(),lower_bound(v.begin(),v.end(),x/2));
		
		for(int i=idx;i<n;++i){
			if(((x-v[i])==v[i]) && (upper_bound(v.begin(),v.end(),v[i])-lower_bound(v.begin(),v.end(),v[i])>1)) {
				cout<<"Peter should buy books whose prices are "<<v[i]<<" and "<<v[i]<<".\n";
				break;
			} else if(binary_search(v.begin(),v.end(),x-v[i])){
				cout<<"Peter should buy books whose prices are "<<x-v[i]<<" and "<<v[i]<<".\n";
				break;
			}
		}
		cout<<'\n';
	}

	return 0;
}
