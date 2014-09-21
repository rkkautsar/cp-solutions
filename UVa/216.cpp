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
#define X first
#define Y second

vii v;
vector<vd> memo;
vector<vd> cable;
int n;

double tsp(int idx,int bitmask){
	if(memo[idx][bitmask]!=-1) return memo[idx][bitmask];
	if(bitmask==(1<<n)-1) return 0;
	memo[idx][bitmask]=INF;
	double tmp;
	int select,selecttmp;
	for(int i=0;i<n;++i)
		if(!(bitmask & (1<<i))){
			tmp=tsp(i,bitmask|(1<<i))+16+hypot(abs(v[idx].X-v[i].X),abs(v[idx].Y-v[i].Y)));
			if(tmp<memo[idx][bitmask])select=i,selecttmp=tmp;
		}
	cable[idx][select]=dist[select][idx]=selecttmp;
	return memo[idx][bitmask];

}

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	int count=0;
	while(cin>>n && n){
		cout<<"**********************************************************\n";
		cout<<"Network #"<<++count<<'\n';
		v.resize(n);
		memo.resize(n,vd(1<<n,-1.0));
		cable.resize(n,vd(n,-1.0));
		for(int i=0;i<n;++i){
			cin>>v[i].X>>v[i].Y;
		}
		double ans=1e100;
		for(int i=0;i<n;++i)
			ans=min(ans,tsp(i,1<<i));
		//TODO: output cut length
		cout<<fixed<<setprecision(2)<<ans<<'\n';
	}

	return 0;
}
