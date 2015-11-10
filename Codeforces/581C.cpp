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


bool cmp(const int &a,const int &b){
	return (a%10)>(b%10);
}

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,k;
	cin>>n>>k;
	vi v(n);
	int score=0;
	for(int i=0;i<n;++i){
		cin>>v[i];
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<n;++i){
		int temp=10-(v[i]%10);
		if(k>=temp && v[i]+temp<=100){
			k-=temp;
			v[i]+=temp;
		}
	}
	for(int i=0;i<n;++i){
		if(v[i]%10!=0)continue;
		while(k>=10 && v[i]+10<=100){
			k-=10;
			v[i]+=10;
		}
	}
	for(int i=0;i<n;++i)
		score+=v[i]/10;
	cout<<score<<'\n';
	
	return 0;
}
