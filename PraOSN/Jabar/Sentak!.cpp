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

void geser(vi &v,int l,int r,int x){
	vi vx(r-l+1);
	int offset;
	x%=(r-l+1);
	for(int i=0;i<r-l+1;++i){
		offset=l+i-x;
		if(offset<l)offset+=r-l+1;
		vx[i]=v[offset];
	}
	for(int i=l;i<=r;++i)v[i]=vx[i-l];
}

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	int n,m,a,b,x,mn,mx;
	cin>>n>>m;
	string op;
	vi v(n);
	for(int i=0;i<n;++i)cin>>v[i];
	while(m--){
		cin>>op;
		if(op[0]=='G'){
			cin>>a>>b>>x;
			--a,--b;
			geser(v,a,b,x);
			//for(int i=0;i<n;++i) cout<<v[i]<<' '; cout<<'\n';
		} else {
			cin>>a>>b;
			--a,--b;
			if(b<a)swap(a,b);
			mn=a,mx=a;
			for(int i=a+1;i<=b;++i){
				if(v[i]<v[mn])mn=i;
				if(v[i]>v[mx])mx=i;
			}
			cout<<v[mn]<<' '<<v[mx]<<'\n';
		}
	}

	return 0;
}
