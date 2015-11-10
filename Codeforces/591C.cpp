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

int THRESHOLD;

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin>>n;
	vi v(n);

	THRESHOLD = 1000000000/n;

	for(int i=0;i<n;++i)
		cin>>v[i];
	
	int change = 0,sum,ll,l;
	bool changed;

	do {
		changed = false;
		
		sum = v[0]+v[0]+v[1];

		ll = l = v[0];

		for(int i=1;i<n-1;++i){
			sum -= ll;
			sum += v[i+1];
			if(sum/2 != v[i]) changed = true;
			ll = l;
			l = v[i];
			v[i] = sum/2;
		}

		if(changed) ++change;
		if(change > THRESHOLD){
			cout<<-1<<'\n';
			return 0;
		}
	} while(changed);

	cout<<change<<'\n';
	for(int i=0;i<n;++i)
		cout<<v[i]<<(i==n-1?'\n':' ');

	
	return 0;
}
