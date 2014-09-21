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
	
	string dummy;
	getline(cin,dummy);

	int n;
	cin>>n;
	int banyak=n*(n+1);
	banyak>>=1;
	vi v(banyak);
	for(int i=0;i<banyak;++i)cin>>v[i];
	sort(v.begin(),v.end());
	if(n<3){
		for(int i=0,now=0;i<n;++i)
			for(int j=0;j<=i;++j)
				cout<<v[now++]<<(j==i?'\n':' ');
		return 0;
	}
	vii kiri(n-2);
	vi kanan(n-2);

	for(int i=0,now=0;i<(n-2)*2;i+=2)
		kiri[now++]=mp(v[i+1],v[i]);
	for(int i=banyak-(n-2),now=0;i<banyak;++i)
		kanan[now++]=v[i];

	int greedy=0,dp=0;

	int gadipake,idx_dipake=(n-2)*2;
	gadipake=idx_dipake;

	for(int i=(n-2)*2;i<(banyak-(n-2)-1);++i)
		if(v[i+1]-v[i] < v[idx_dipake+1]-v[idx_dipake]) idx_dipake=i;
	
	for(int i=0;i<n;++i)
		for(int j=0;j<=i;++j){
			if(i==0 && j==0){
				if(gadipake==idx_dipake)++gadipake;
				if(gadipake==idx_dipake+1)++gadipake;
				cout<<v[gadipake++]<<'\n';
				break;
			} else
			if(i==1){
				cout<<v[idx_dipake+1]<<' '<<v[idx_dipake]<<'\n';
				break;
			} else
			if(j==0){
				cout<<kiri[greedy].first<<' ';
				continue;
			} else
			if(j==1){
				cout<<kiri[greedy].second<<' ';
				++greedy;
				continue;
			} else
			if(j==i){
				cout<<kanan[dp++]<<'\n';
				continue;
			}

			if(gadipake==idx_dipake)++gadipake;
			if(gadipake==idx_dipake+1)++gadipake;
			cout<<v[gadipake++]<<' ';
		}

	return 0;
}
