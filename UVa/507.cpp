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

struct summation{
	int val,a,b;
};

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	

	int _t,n,x;
	summation nice,sum;
	cin>>_t;
	for(int tc=1;tc<=_t;++tc){
		cin>>n;
		nice.val=sum.val=0;
		nice.a=nice.b=sum.a=sum.b=1;
		for(int i=2;i<=n;++i){
			cin>>x;
			++sum.b;
			sum.val+=x;
			if(sum.val>nice.val)nice=sum;
			else if(sum.val==nice.val){
				if((sum.b-sum.a)>(nice.b-nice.a))nice=sum;
			}	
			if(sum.2<<h<0){
				sum.2<<h=0;
				sum.a=sum.b=i;
			}
		}
		if(nice.val==0)cout<<"Route "<<tc<<" has no nice parts\n";
		else cout<<"The nicest part of route "<<tc<<" is between stops "<<nice.a<<" and "<<nice.b<<"\n";
	}

	return 0;
}
