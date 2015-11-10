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
 
// macros
// #define __debug

#ifndef __debug
	#define IO_INIT() ios_base::sync_with_stdio(0);cin.tie(0)
	#define debug(_x) cerr<<(_x)<<'\n'
	#define debugArray(_array,_size) for(int ___i=0;___i<(_size);++___i)cout<<(__array[___i])<<(___i==(_size)-1?'\n':' ')
#else
	#define IO_INIT() {}
	#define debug(_x) {}
	#define debugArray(_array,_size) {}
#endif

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

const int MAX=1005;
bool isprime[MAX];
vi prime;
int prime_size;

void sieve(){
	for(int i=1;i<=MAX;++i)isprime[i]=true;
	isprime[2]=true;
	prime.push_back(2);
	for(int i=3;i<=MAX;i+=2){
		if(isprime[i])prime.push_back(i);
		for(int j=i*i;j<=MAX;j+=i)isprime[j]=false;
	}
	prime_size=prime.size();
}

int main(int argc, char **argv){
	IO_INIT();

	int n;
	cin>>n;
	vi v;
	sieve();
	for(int i=0;i<prime_size && prime[i]<=n;++i){
		for(int j=prime[i];j<=n;j*=prime[i])v.push_back(j);
	}
	cout<<v.size()<<'\n';
	for(int i=0,len=v.size();i<len;++i)
		cout<<v[i]<<(i==len-1?'\n':' ');

	return 0;
}
