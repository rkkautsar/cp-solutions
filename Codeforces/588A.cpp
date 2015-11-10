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
	vi a(n),prefix(n,0);
	vii p(n);
	for(int i=0;i<n;++i){
		p[i].second = i;
		cin>>a[i]>>p[i].first;
		if(i) prefix[i] = prefix[i-1] + a[i];
		else prefix[0] = a[0];
	}

	sort(p.begin(),p.end());
	int mostright = n;
	int cost = 0;
	for(int i=0;i<n && mostright;++i){
		if(p[i].second < mostright){
			cost += p[i].first * prefix[mostright-1];
			if(p[i].second)
				cost -= p[i].first * prefix[p[i].second-1];
			mostright = p[i].second;
		}
	}

	cout<<cost<<'\n';
	
	return 0;
}