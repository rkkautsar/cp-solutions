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
typedef pair<int,ii> iii;
 
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
	
	int n,q;
	cin>>n>>q;
	priority_queue<iii,vector<iii>,greater<iii> > pq;
	iii x;
	for(int i=0;i<n;++i){
		cin>>x.second.first>>x.second.second;
		x.first=0;
		pq.push(x);
	}

	for(int i=0;i<q;++i){
		x=pq.top();
		pq.pop();
		cout<<x.second.first<<' '<<x.first<<'\n';
		pq.push(mp(x.first+x.second.second,x.second));
	}

	return 0;
}
