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

void lowercase(string &s){
	int n=s.size();
	for(int i=0;i<n;++i)
		if(s[i]>='A' && s[i]<='Z')s[i]=s[i]-'A'+'a';
}

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	set<string> st;

	string s;

	int n,i,j;

	while(getline(cin,s)){
		n=s.size();
		lowercase(s);
		i=0;
		while(i<n){
			if(s[i]>='a' && s[i]<='z'){
				j=i;
				while(j<n && s[j]>='a' && s[j]<='z') ++j;
				st.insert(s.substr(i,j-i));
				i=j+1;
			} else ++i;
		}
	}

	for(set<string>::iterator it=st.begin();it!=st.end();++it)
		cout<<*it<<'\n';


	return 0;
}
