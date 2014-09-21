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

int v[10][100],
	prev[10][100];

void printpath(int r,int c){
	if(c==0){
		cout<<r+1;
	} else {
		printpath(prev[r][c],c-1);
		cout<<' '<<r+1;
	}
}

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	vi newrow(3);
	int r,c,minimal,minimalrow;
	while(cin>>r>>c){
		for(int i=0;i<r;++i)
			for(int j=0;j<c;++j)
				cin>>v[i][j];
		for(int j=1;j<c;++j){
			for(int i=0;i<r;++i){
				minimal=INF;
				minimalrow=0;

				newrow[0]=(i-1<0?r-1:i-1);
				newrow[1]=i;
				newrow[2]=(i+1==r?0:i+1);
				sort(newrow.begin(),newrow.end());

				for(int k=0;k<3;++k){
					if(v[newrow[k]][j-1]<minimal){
						minimalrow=newrow[k];
						minimal=v[newrow[k]][j-1];
					}
				}
				v[i][j]+=minimal;
				prev[i][j]=minimalrow;
			}
		}
		/*for(int i=0;i<r;++i)
			for(int j=0;j<c;++j)cout<<v[i][j]<<(j==c-1?'\n':' ');*/
		minimal=INF;
		minimalrow=0;
		for(int i=0;i<r;++i)
			if(v[i][c-1]<minimal){
				minimal=v[i][c-1];
				minimalrow=i;
			}

		printpath(minimalrow,c-1);
		cout<<'\n';
		cout<<minimal<<'\n';
	}

	return 0;
}
