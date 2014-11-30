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
	
	string a,b;
	int m,n;
	cin>>a>>b;
	m=a.size(),n=b.size();
	int i=0;
	
	if(n>=m){
		cout<<"Wah, tidak bisa :(\n";
		return 0;
	}

	while(i<m){
		if(a[i]!=b[i])break;
		++i;
	}
	
	if(i==m){
		cout<<"Wah, tidak bisa :(\n";
		return 0;
	}

	//cout<<a.substr(i+1,m-1)<<' '<<b.substr(i,n-i+1)<<'\n';

	if(a.substr(i+1,m-i)==b.substr(i,n-i+1)) cout<<"Tentu saja bisa!\n";
	else cout<<"Wah, tidak bisa :(\n";

	return 0;
}
