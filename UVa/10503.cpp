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

ii mulai,selesai;
vii domino;
int m,n;

bool f(int sebelum, const int &mau_ke_mana, ll bitmask, int n){
	if(n==0){
		if(sebelum==mau_ke_mana)return true;
		else return false;
	}
	bool bisa=false;
	for(int i=0;i<m && !bisa;++i){
		if(!(bitmask&(1<<i))){
			if(sebelum==domino[i].first) bisa|=f(domino[i].second,mau_ke_mana,bitmask|(1<<i),n-1);
			else if(sebelum==domino[i].second) bisa|=f(domino[i].first,mau_ke_mana,bitmask|(1<<i),n-1);
		}
	}
	return bisa;
}

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	while(cin>>n && n){
		cin>>m;
		cin>>mulai.first>>mulai.second;
		cin>>selesai.first>>selesai.second;
		domino.resize(m);
		for(int i=0;i<m;++i){
			cin>>domino[i].first>>domino[i].second;
			domino[i+1].first=domino[i].second;
			domino[i+1].second=domino[i].first;
		}
		if(f(mulai.second,selesai.first,0,n))
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}

	return 0;
}
