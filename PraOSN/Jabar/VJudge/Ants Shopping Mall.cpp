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
	
	int t,r,c;
	vs v;
	cin>>t;
	for(int testcase=1;testcase<=t;++testcase){
		cin>>r>>c;
		v.resize(r);
		for(int i=0;i<r;++i)cin>>v[i];
		int val,ans=INF;
		for(int column=0;column<c;++column){
			val=0;
			for(int row=0;row<r;++row){
				if(v[row][column]=='0')continue;
				int i,tmp=INF;
				//coba kanan
				for(i=column;i<c && v[row][i]=='1';++i);
				if(i==c){
					//gabisa
					tmp=min(tmp,INF);
				} else {
					tmp=min(tmp,i-column);
				}

				//coba kiri
				for(i=column;i>=0 && v[row][i]=='1';--i);
				if(i<0){
					//gabisa
					tmp=min(tmp,INF);
				} else {
					tmp=min(tmp,column-i);
				}
				if(tmp==INF){
					val=INF;
					break;
				} else {
					val+=tmp;
				}
			}
			//cout<<column<<' '<<val<<'\n';
			if(val<ans){
				ans=val;
			}
		}
		if(ans==INF)ans=-1;
		cout<<"Case "<<testcase<<": "<<ans<<'\n';
	}


	return 0;
}
