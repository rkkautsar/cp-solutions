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

map<string,int> m;

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	string s;
	int count=-1;
	vi v;
	while(getline(cin,s)){
		if(s[0]=='#'){
			++count;
			v.push_back(0);
			m[s.substr(2,s.size()-2)]=count;
			continue;
		}
		if(s[0]=='!'){
			break;
		}
		++v[count];
	}
	ll ans=0;
	while(getline(cin,s)){
		size_t pos = s.find("+");
		if(pos==string::npos){
			ans=v[m[s]];
			cout<<ans<<'\n';
			continue;
		} else {
			//cout<<s.substr(0,pos-1)<<'\n';
			ans=v[m[s.substr(0,pos-1)]];
			s.erase(0,pos+2);
		}
		while((pos=s.find("+"))!=string::npos){
			//cout<<s.substr(0,pos-1)<<'\n';
			ans*=v[m[s.substr(0,pos-1)]];
			s.erase(0,pos+2);
		}
		ans*=v[m[s]];
		cout<<ans<<'\n';
	}

	return 0;
}
