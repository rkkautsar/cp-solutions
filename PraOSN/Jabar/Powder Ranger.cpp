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

bool cmp(const pair<int,double> &a, const pair<int,double> &b){
	return a.second<b.second;
}

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	int n,g;
	cin>>n>>g;
	vector<pair<int,double> > v(n);
	for(int i=0;i<n;++i){
		cin>>v[i].first>>v[i].second;
		v[i].second/=v[i].first;
	}
	sort(v.begin(),v.end(),cmp);
	int j;
	double perih=0;
	// for(int i=0;i<n;++i){
	// 	cout<<v[i].first<<' '<<v[i].second<<' '<<v[i].second/v[i].first<<'\n';
	// }
	for(int i=n-1;i>=0;--i){
		//cout<<min(g,v[i].first)*v[i].second<<'\n';
		perih+=min(g,v[i].first)*v[i].second;
		g-=min(g,v[i].first);
	}
	cout.precision(5);
	cout<<fixed<<perih<<'\n';

	return 0;
}
