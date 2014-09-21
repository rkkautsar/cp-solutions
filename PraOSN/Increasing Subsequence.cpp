//IO
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
 
//C Header
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
 
//container
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
 
//misc
#include <algorithm>
#include <functional>
#include <limits>
#include <string>
 
using namespace std;
 
// typedef
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<double,double> dd;
typedef pair<int,ii> iii;
typedef pair<double,dd> ddd;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<ii> vii;
typedef vector<dd> vdd;
typedef vector<vi> vvi;
typedef vector<vd> vvd;
typedef vector<vc> vvc;
typedef vector<bool> vb;
 
//defines
#define abs(_x) ((_x)<0?-(_x):(_x))
#define REP(_x) for(int __x=0;__x<_x;++__x)
#define mp(_x,_y) make_pair((_x),(_y))
#define mp3(_x,_y,_z) make_pair((_x),(mp(_y,_z)))
#define fir first
#define sec second
#define PI 3.1415926535897932385
#define EPS 1e-9
#define PHI 1.6180339887498948482
#define INF 0x7FFFFFFF
#define INFLL 0x7FFFFFFFFFFFFFFFLL
#define readl(_s) getline(cin,_s);cin.ignore(9999,'\n')
#define ceildiv(_a,_b) ((_a)%(_b)==0?(_a)/(_b):((_a)/(_b))+1)

//classes
#define MOD 5000000

class BIT{
private:
	vi tree;
	int size;
public:
	BIT(const int &n){
		size=n+1;
		tree.resize(n+1,0);
	}
	void update(int x,const int &d){
		while(x<size) tree[x]=(tree[x]+d)%MOD, x+=x&(-x);
	}
	int sum(int x){
		int sum=0;
		while(x) sum=(sum+tree[x])%MOD, x-=x&(-x);
		return sum;
	}
};
 
int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	

	vi v;
	
	int n,k;
	cin>>n>>k;
	v.resize(n);
	const int MAX_VAL=100005;
	vector<BIT> b(k+1,BIT(MAX_VAL));
	for(int i=0;i<n;++i){
		cin>>v[i];
		for(int j=1;j<=k;++j){
			if(j==1) b[j].update(v[i]+1,1);
			else	 b[j].update(v[i]+1,b[j-1].sum(v[i]));
		}
	}

	cout<<b[k].sum(MAX_VAL-1)<<'\n';

	return 0;
}
