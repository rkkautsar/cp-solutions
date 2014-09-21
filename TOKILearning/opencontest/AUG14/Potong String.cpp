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
	
	int n,q,a,b;
	bool ketemu;
	string s;
	cin>>n>>q;
	cin>>s;
	while(q--){
		cin>>a>>b;

		ketemu=false;
		for(int i=a;i<b && !ketemu;++i){
			if(s.compare(a-1,i-a+1,s,i,b-i)<0) ketemu=true;
			//if(s.substr(a-1,i-a+1)<s.substr(i,b-i))ketemu=true;
		}
		if(ketemu){
			cout<<"YA\n";
		} else {
			cout<<"TIDAK\n";
		}

	}

	return 0;
}
