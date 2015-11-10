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
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<bool> vb;
 
//defines
#define abs(_x) ((_x)<0?-(_x):(_x))
#define REP(_x) for(int __x=0;__x<_x;++__x)
#define mp(_x,_y) make_pair((_x),(_y))
#define PI acos(-1)
#define EPS 1e-9
#define INF 0x0FFFFFFF
#define INFLL 0x0FFFFFFFFFFFFFFFLL
#define ceildiv(_a,_b) ((_a)%(_b)==0?(_a)/(_b):((_a)/(_b))+1)
#define fi first
#define se second

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	int n;
	cin>>n;
	vi v(n);
	for(int i=0;i<n;++i)
		cin>>v[i];
	sort(v.begin(),v.end());

	priority_queue<int> pq;

	for(int i=n-1;i>0;){
		if(v[i]==v[i-1]){
			//yay pake
			pq.push(v[i]);
			i-=2;
		} else if(v[i]-v[i-1]==1){
			//yay potong
			pq.push(v[i-1]);
			i-=2;
		} else {
			//yah
			--i;
		}
	}

	ll a,b,sum=0;
	while(!pq.empty()){
		a=pq.top();pq.pop();
		if(pq.empty()) break;
		b=pq.top();pq.pop();
		sum+=a*b;
	}

	cout<<sum<<'\n';


	return 0;
}
