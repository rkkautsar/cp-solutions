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

const int MAX_LEN=1000000;
int pre[MAX_LEN+1];

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	string s;
	int len,n,a,b,tc=0;
	while(cin>>s){
		cout<<"Case "<<++tc<<":\n";
		len=s.size();
		pre[0]=0;
		for(int i=1;i<=len;++i)
			pre[i]=pre[i-1]+(s[i-1]=='1');

		cin>>n;
		while(n--){
			cin>>a>>b;
			if(a>b)swap(a,b);
			++a,++b;
			if(pre[b]-pre[a-1]==b-a+1 || pre[b]-pre[a-1]==0) cout<<"Yes\n";
			else cout<<"No\n";
		}


	}

	return 0;
}
