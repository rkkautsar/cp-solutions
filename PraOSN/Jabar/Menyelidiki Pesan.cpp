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
	
	int len;
	cin>>len;
	string a,b,c;
	cin>>a>>b>>c;
	map<char,char> hash;
	for(int i=0;i<26;++i)
		hash[('A'+i)]='?';
	//bool bingung=false;

	vi occurrence(26,0);
	for(int i=0;i<len;++i){
		if(b[i]<'A' || b[i]>'Z'){
			cout<<"Pak Dengklek bingung\n";
			return 0;
		} else if(hash[b[i]]!='?' && hash[b[i]]!=a[i]){
			cout<<"Pak Dengklek bingung\n";
			return 0;
		}
		hash[b[i]]=a[i];
	}
	for(int i=0;i<26;++i)
		if(hash['A'+i]!='?') ++occurrence[hash['A'+i]-'A'];

	//for(int i=0;i<26;++i)cout<<((char)('A'+i))<<" = "<<hash[('A'+i)]<<'\n';

	for(int i=0;i<26;++i){
		if(occurrence[i]>1){
			cout<<"Pak Dengklek bingung\n";
			return 0;
		}
	}

	bool bingung=false;
	for(int i=0;i<len;++i)
		cout<<hash[c[i]];
	cout<<'\n';

	return 0;
}
