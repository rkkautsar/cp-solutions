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
	
	// int x[6]={2, 3, 4, 5, 6, 7};

	// for(int i=0;i<6;++i)
	// 	for(int j=0;j<6;++j){
	// 		if(i==j) continue;
	// 		for(int k=0;k<6;++k){
	// 			if(j==k || i==k) continue;
	// 			int tmp,z,y=x[i]*(x[j]*10+x[k]);
	// 			z=y;
	// 			bool good=true;
	// 			while(good && z){
	// 				tmp=z%10;
	// 				if(tmp<2 || tmp>7) good=false;
	// 				z/=10;
	// 			}
	// 			if(good)printf("%d x %d%d = %d\n",x[i],x[j],x[k],x[i]*(x[j]*10+x[k]));
	// 		}
	// 	}

	cout<<"6*57=342\n";

	return 0;
}
