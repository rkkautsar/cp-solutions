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
	
	string s;
	int m;
	cin>>s;
	cin>>m;
	vi v(m);
	// int x;
	int len=s.size();
	
	for(int i=0;i<m;++i){
		cin>>v[i];
		--v[i];
		// cin>>x;
		// for(int j=x-1;j<len/2;++j){
		// 	swap(s[j],s[len-j-1]);
		// }
	}

	sort(v.begin(),v.end());
	
	int i=m-1,kanan=len/2;
	while(i>=0){
		// cout<<i<<'\n';
		if(!(i&1)){ //0..i ngereverse semua
			// cout<<"reverse "<<v[i]<<"..."<<kanan<<'\n';
			for(int j=v[i];j<kanan;++j){
				swap(s[j],s[len-j-1]);
			}
		}

		kanan=v[i];

		while(i>=0 && v[i]==v[i-1]) --i;
		--i;
	}


	cout<<s<<'\n';

	return 0;
}
