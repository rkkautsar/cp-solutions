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

const int MAX_PRIME = 4000005;
vector<ll> prime;
vb isprime(MAX_PRIME,true);

void sieve(){
	prime.push_back(2);
	for(int i=3;i<MAX_PRIME;i+=2){
		if(!isprime[i])continue;
		prime.push_back(i);

		if(i>sqrt(MAX_PRIME))continue;

		for(int j = i*i; j<MAX_PRIME; j+=i)
			isprime[j]=false;
	}
}

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll x;
	cin>>x;
	ll akar = sqrt(x);
	ll ans = 1;
	sieve();

	int psize = prime.size();
	for(int i=0;i<psize;++i){
		if(x % prime[i] == 0)
			ans *= prime[i];
	}

	cout<<ans<<'\n';
	
	return 0;
}
