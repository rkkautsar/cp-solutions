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

vi v,solusi;

bool f(int now,int step,const int &m,const int &n){
	if(step>=m) return true;
	if(v[step]==now){
		solusi.pop_back();
		return false;
	}
	bool tmp=false;
	if(now-1>=1 && now-1<=n){
		solusi.push_back(now-1);
		tmp|=f(now-1,step+1,m,n);
	}
	if(!tmp && now+1>=1 && now+1<=n){
		solusi.push_back(now+1);
		tmp|=f(now+1,step+1,m,n);
	}
	return tmp;
}


int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	int n,m;
	cin>>n>>m;
	v.resize(m);
	for(int i=0;i<m;++i)cin>>v[i];
	bool bisa=false;
	for(int i=1;i<=n && !bisa;++i){
		solusi.clear();
		solusi.push_back(i);
		if(f(i,0,m,n)){
			bisa=true;
			for(int j=0;j<m;++j)cout<<solusi[j]<<'\n';
			return 0;
		}
	}
	if(!bisa) cout<<"menyerah\n";

	return 0;
}
