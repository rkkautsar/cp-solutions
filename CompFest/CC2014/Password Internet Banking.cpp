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

int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107};

inline void encrypt(string &s,const int &l,const int &r){
	int now=0;
	while(prime[now]<r-l+1 && now<28){
		reverse(s.begin()+l,s.begin()+(min(r+1,l+prime[now])));
		if(prime[now]<r-l+1)++now;
	}
}

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	int t,tmp,len,p;
	string s;
	cin>>t;
	while(t--){
		cin>>s;
		len=s.size();
		tmp=0;
		while(tmp<len){
			if(len-tmp<2)break;
			p=distance(prime,upper_bound(prime,prime+25,len-tmp));
			encrypt(s,tmp,tmp+prime[p]-1);
			tmp+=prime[p]-1;
		}

		cout<<s<<'\n';
	}

	return 0;
}
