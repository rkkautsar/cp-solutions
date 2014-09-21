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

vvi sum;
vs v;

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	int t;
	cin>>t;
	string s;
	
	int n;
	bool first=true;
	while(t--){
		if(!first)
			cout<<'\n';
		else first=false;
		cin>>s;
		n=s.size();
		v.clear();
		sum.clear();
		v.resize(n);
		sum.resize(n,vi(n,0));
		v[0]=s;
		for(int i=1;i<n;++i)cin>>v[i];

		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j){
				sum[i][j]=(v[i][j]-'0');
				if(i>0) sum[i][j]+=sum[i-1][j];
				if(j>0) sum[i][j]+=sum[i][j-1];
				if(i>0 && j>0) sum[i][j]-=sum[i-1][j-1];
			}
		
		int largest=0,sumhere;

		/*for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)cout<<sum[i][j]<<(j==n-1?'\n':' ');*/

		for(int i=0;i<n;++i)for(int j=0;j<n;++j)
		for(int p=i;p<n;++p)for(int q=j;q<n;++q){
			//cout<<"("<<i<<","<<j<<") . "<<"("<<p<<","<<q<<")"<<endl;
			sumhere=sum[p][q];
			if(i>0) sumhere-=sum[i-1][q];
			if(j>0) sumhere-=sum[p][j-1];
			if(i>0 && j>0) sumhere+=sum[i-1][j-1];
			if(v[i][j]=='1' && sumhere==(p-i+1)*(q-j+1)) largest=max(largest,sumhere);
		}

		cout<<largest<<'\n';

	}

	return 0;
}
