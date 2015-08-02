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
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<bool> vb;
 
//defines
#define abs(_x) ((_x)<0?-(_x):(_x))
#define REP(_x) for(int __x=0;__x<_x;++__x)
#define mp(_x,_y) make_pair((_x),(_y))
#define PI acos(-1)
#define EPS 1e-9
#define INF 0x0FFFFFFF
#define INFLL 0x0FFFFFFFFFFFFFFFLL
#define ceildiv(_a,_b) ((_a)%(_b)==0?(_a)/(_b):((_a)/(_b))+1)
#define fi first
#define se second

const double C = 12.01,
			 H = 1.008,
			 O = 16.00,
			 N = 14.01;

bool is_element(const char &x){
	if(x!='C' && x!='H' && x!='O' && x!='N') return false;
	return true;
}

double Ar(const char &x){
	if(x=='C') return C;
	else if(x=='H') return H;
	else if(x=='O') return O;
	else if(x=='N') return N;
	else return -1;
}

int stoint(const string &num){
	int ret;
	istringstream ss(num);
	ss>>ret;
	return ret;
}


int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	int t,l,r,len;
	double Mr;
	string s,element;
	vs elements;
	cin>>t;
	while(t--){
		cin>>s;
		elements.clear();

		//split by elements (e.g. C11, N2)
		for(l=r=0,len=s.size();r<len;++r){
			if(r+1==s.size() || is_element(s[r+1])){
				elements.push_back(s.substr(l,r-l+1));
				l=r+1;
			}
		}

		Mr=0;
		len=elements.size();
		for(int i=0;i<len;++i){
			element=elements[i];
			// cout<<element<<' ' <<Ar(element[0]) << ' '<<stoint(element.substr(1,element.size()-1))<<'\n';
			Mr+=Ar(element[0]) * (element.size()==1?1:stoint(element.substr(1,element.size()-1)));
		}

		cout << fixed << setprecision(3) << Mr <<'\n';
	}	

	return 0;
}
