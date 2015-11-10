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

#define abs(_x) ((_x)<0?-(_x):(_x))
#define REP(_a,_b) for(int (_a)=0;(_a)<(_b);++(_a))
#define mp(_x,_y) make_pair((_x),(_y))
#define PI 3.1415926535897932385
#define EPS 1e-9
#define INF 0x00FFFFFF
#define INFLL 0x00FFFFFFFFFFFFFFLL
#define ceildiv(_a,_b) ((_a)%(_b)==0?(_a)/(_b):((_a)/(_b))+1)
#define fi first
#define se second

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,m;
	string a,b;
	string s;
	cin>>n>>m;
	cin>>s;
	map<char,char> ganti;
	for(char c='a';c<='z';++c)
		ganti[c] = c;
	for(int i=0;i<m;++i){
		cin>>a>>b;
		for(char c='a';c<='z';++c){
			if(ganti[c] == a[0]) ganti[c] = b[0];
			else if(ganti[c] == b[0]) ganti[c] = a[0];
		}
	}
	for(int i=0;i<n;++i)
		s[i] = ganti[s[i]];
	cout<<s<<'\n';
	
	return 0;
}
