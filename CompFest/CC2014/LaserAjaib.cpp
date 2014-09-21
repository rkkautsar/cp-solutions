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
	
	int t,m,n,now,candidate;
	bool ada;
	vs v;
	cin>>t;
	while(t--){
		cin>>m>>n;
		v.resize(m);
		now=-1;
		for(int i=0;i<m;++i){
			cin>>v[i];
			if(v[i][0]=='#')now=i;
		}
		if(now<0){
			cout<<"TIDAK KENA\n";
			continue;
		}

		for(int i=0;i<n-1;++i){
			ada=false;
			for(int j=-1;j<=1 && !ada;++j){
				candidate=now+j;
				if(candidate>=0 && candidate<m && v[candidate][i+1]=='#'){
					ada=true;
					now=candidate;
				}
			}
			if(!ada){
				cout<<"TIDAK KENA\n";
				break;
			} else if(i==n-2){
				cout<<"KENA\n";
			}
		}
	}

	return 0;
}
