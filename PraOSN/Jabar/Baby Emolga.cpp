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

vvi memo;

int timbang(int a,int b){
	if(memo[a][b]!=0)return memo[a][b];
	else {
		int res;
		cout<<"timbang "<<a<<' '<<b<<'\n'<<flush;
		cin>>res;
		memo[a][b]=res;
		memo[b][a]=-res;
		return memo[a][b];
	}
}

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	string kasus;
	getline(cin,kasus);

	int n,m,k;
	cin>>n>>m>>k;
	vi juara,peserta(n),hasil;
	vb isjuara(n,false);
	memo.resize(n+1,vi(n+1,0));
	for(int i=0;i<n;++i)peserta[i]=i+1;
	while(k--){
		do{
			hasil.clear();
			
			/*for(int i=0,len=peserta.size();i<len;++i) cout<<peserta[i]<<' ';
				cout<<'\n'<<flush;
			*/

			int idx=0,len=peserta.size();
			while(idx<len){
				if(idx+1<len){
					if(timbang(peserta[idx],peserta[idx+1])>0){
						hasil.push_back(peserta[idx]);
						idx+=2;
					}
					else{
						hasil.push_back(peserta[idx+1]);
						idx+=2;
					}
				} else {
					hasil.push_back(peserta[idx++]);
				}
			}

			//cout<<hasil.size()<<'\n';
			if(hasil.size()==1)break;
			if(hasil.size()>1) peserta=hasil;
		} while(hasil.size()>1);
		//cout<<hasil[0]<<'\n'<<flush;
		juara.push_back(hasil[0]);
		isjuara[hasil[0]-1]=true;
		peserta.clear();
		for(int i=0;i<n;++i){
			if(isjuara[i])continue;
			bool ada=false;
			for(int j=0;j<juara.size() && !ada;++j)
				if(memo[juara[j]][i+1]>0) peserta.push_back(i+1),ada=true;
		}
	}
	//cout<<juara.size()<<'\n';
	cout<<"jawab "<<juara[juara.size()-1]<<'\n'<<flush;
	

	return 0;
}
