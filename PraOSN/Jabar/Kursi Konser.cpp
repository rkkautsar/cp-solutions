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
	
	int n,m,k,count=0;
	cin>>n>>m>>k;
	vector<vb> v(n,vb(m,0));
	queue<ii> q;
	ii x;
	q.push(mp(0,0));
	while(!q.empty()){
		x=q.front();
		q.pop();
		if(v[x.first][x.second]==1)continue;
		v[x.first][x.second]=1;
		//cout<<++count<<"th = "<<x.first+1<<' '<<x.second+1<<'\n';
		--k;
		if(k==0){
			cout<<x.first+1<<' '<<x.second+1<<'\n';
			break;
		}
		if(x.second+1<m && v[x.first][x.second+1]==0)q.push(mp(x.first,x.second+1));
		if(x.first+1<n && v[x.first+1][x.second]==0)q.push(mp(x.first+1,x.second));
	}

	return 0;
}