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
	
	string kasus;
	getline(cin,kasus);

	int n,m,q,t;
	cin>>n>>m>>q>>t;
	
	int nilai,provinsi;
	vvi prov(q);
	vii rank(m);
	int k=0;

	for(int i=0;i<m;++i){
		cin>>nilai>>provinsi;
		rank[i]=mp(nilai,provinsi-1);
		prov[provinsi-1].push_back(nilai);
		k=max(k,(int)prov[provinsi-1].size());
	}

	for(int i=0;i<q;++i) sort(prov[i].begin(),prov[i].end(),greater<int>());

	sort(rank.begin(),rank.end(),greater<ii>());
	vi passing_grade(k,100001);

	// for(int i=0;i<q;++i){
	// 	for(int j=0;j<prov[i].size();++j) cout<<prov[i][j]<<' ';
	// 	cout<<'\n';
	// }

	vi t_besar(q,0);
	for(int i=0;i<t;++i){
		passing_grade[t_besar[rank[i].second]]=rank[i].first;
		++t_besar[rank[i].second];
	}

	int sisa=n-t,ranking=0,mx,banyak;
	while(sisa>0){
		mx=-INF;
		for(int i=0;i<q;++i)
			if(ranking<prov[i].size() && prov[i][ranking]<passing_grade[ranking]) mx=max(mx,prov[i][ranking]);
		if(mx<0)++ranking;
		else{
			//cout<<mx<<'\n';
			passing_grade[ranking]=mx;
			--sisa;
		}
	}

	for(int i=0;i<k;++i)cout<<passing_grade[i]<<(i==k-1?'\n':' ');

	return 0;
}
