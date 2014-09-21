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

vi head,knight;

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	int n,m;
	ll cost;

	while(cin>>n>>m && (n+m)>0){
		head.resize(n);
		knight.resize(m);
		for(int i=0;i<n;++i)cin>>head[i];
		for(int i=0;i<m;++i)cin>>knight[i];
		sort(head.begin(),head.end());
		sort(knight.begin(),knight.end());
		cost=0;
		bool good=true;
		for(int i=0,j=0;i<n && good;++i){
			if(j>=m){
				good=false;
				break;
			}
			while(head[i]>knight[j]){
				++j;
				if(j>=m) good=false;
			}
			cost+=knight[j];
			++j;
		}
		if(!good)
			cout<<"Loowater is doomed!\n";
		else
			cout<<cost<<'\n';
	}


	return 0;
}
