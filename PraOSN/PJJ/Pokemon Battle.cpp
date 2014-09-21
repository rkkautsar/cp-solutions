#include <bits/stdc++.h>
using namespace std;
 
// typedef
typedef long long ll;
typedef vector<ll> vll;
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


struct Trainer{
	int p,a,b;
	Trainer(){
		p=a=b=0;
	}
};


int n,x,l;
vector<Trainer> trainer;
vll memo;

ll f(int now){
	if(now>=n) return 0;
	if(memo[now]!=-1) return memo[now];
	ll val=0,energy;
	for(int i=now+1;i<=n;++i){
		if(trainer[i].p>=x)break;
		energy=trainer[i].p-trainer[now].p;
		if(energy==0)continue;
		if(energy>=l)val=trainer[i].a;
		else val=trainer[i].b;
		val+=f(i);
		memo[now]=max(memo[now],val);
	}
	return memo[now];
}

bool cmp(const Trainer &a,const Trainer &b){
	return a.p<b.p;
}

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	string dummy;
	getline(cin,dummy);

	cin>>n>>x>>l;
	memo.resize(n+1,-1);
	trainer.resize(n+1);
	for(int i=1;i<=n;++i)
		cin>>trainer[i].p>>trainer[i].a>>trainer[i].b;
	sort(trainer.begin(),trainer.end(),cmp);

	cout<<f(0)<<'\n';

	return 0;
}
