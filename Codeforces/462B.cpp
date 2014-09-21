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

map<char,int> m;

bool cmp(const pair<char,int> &a,const pair<char,int> &b){
	return a.second>b.second;
}

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	sort(s.begin(),s.end());
	int idx=0;
	while(idx<n){
		char now=s[idx];
		m[now]=0;
		while(idx<n && s[idx]==now){
			++m[now];
			++idx;
		}
	}
	vector<pair<char,int> > v;
	v.assign(m.begin(),m.end());
	sort(v.begin(),v.end(),cmp);
	ll val=0;
	for(int i=0,len=v.size();i<len && k;++i){
		val+=1LL * min(v[i].second,k) * min(v[i].second,k);
		k-=min(v[i].second,k);
	}
	cout<<val<<'\n';


	return 0;
}
