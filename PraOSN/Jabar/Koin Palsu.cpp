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
	
	string s;
	
	cout<<"?\n1 2 3\n4 5 6\n"<<flush;
	cin>>s;
	if(s[0]=='S'){
		cout<<"?\n7\n8\n"<<flush;
		cin>>s;
		if(s[1]=='A'){
			cout<<"! 8\n"<<flush;
			return 0;
		} else {
			cout<<"! 7\n"<<flush;
			return 0;
		}
	} else if(s[1]=='A'){
		cout<<"?\n4\n5\n"<<flush;
		cin>>s;
		if(s[1]=='A'){
			cout<<"! 5\n"<<flush;
			return 0;
		} else if(s[1]=='I'){
			cout<<"! 4\n"<<flush;
			return 0;
		} else {
			cout<<"! 6\n"<<flush;
			return 0;
		}
	} else {
		cout<<"?\n1\n2\n"<<flush;
		if(s[0]=='S'){
			cout<<"! 3\n"<<flush;
			return 0;
		} else if(s[1]=='I'){
			cout<<"! 1\n"<<flush;
			return 0;
		} else {
			cout<<"! 2\n"<<flush;
			return 0;
		}
	}

	return 0;
}
