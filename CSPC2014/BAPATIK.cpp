//IO
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
 
//C Header
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
 
//container
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
 
//misc
#include <algorithm>
#include <functional>
#include <limits>
#include <string>
 
using namespace std;
 
// typedef
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<double,double> dd;
typedef pair<int,ii> iii;
typedef pair<double,dd> ddd;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<ii> vii;
typedef vector<dd> vdd;
typedef vector<vi> vvi;
typedef vector<vd> vvd;
typedef vector<vc> vvc;
typedef vector<bool> vb;
 
//defines
#define abs(_x) ((_x)<0?-(_x):(_x))
#define REP(_x) for(int __x=0;__x<_x;++__x)
#define mp(_x,_y) make_pair((_x),(_y))
#define mp3(_x,_y,_z) make_pair((_x),(mp(_y,_z)))
#define fir first
#define sec second
#define PI 3.1415926535897932385
#define EPS 1e-9
#define PHI 1.6180339887498948482
#define INF 0x7FFFFFFF
#define INFLL 0x7FFFFFFFFFFFFFFFLL
#define readl(_s) getline(cin,_s);cin.ignore(9999,'\n');
#define ceildiv(_a,_b) ((_a)%(_b)==0?(_a)/(_b):((_a)/(_b))+1)
 
//functions
template<class T,class Type> 
inline void reset(T begin, T end, Type fills=0){
	fill(begin,end,fills);
}
template<class T,class Type>
inline void reset(T stdcontainer, Type fills=0){
	fill(stdcontainer.begin(),stdcontainer.end(),fills);
}
template<class T,class Type>
inline void mfill(T container, int r, int c, Type fills=0){
	for(int i=0;i<r;++i)
		fill(container[i],container[i]+c,fills);
}

bool comp(ii a,ii b){
	if(a.second==b.second)return a.first<b.first;
	else return a.second<b.second;
}
 
int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	int n,x,y;
	bool good;
	string bangun;
	vii v(3);
	cin>>n;cin.ignore(9999,'\n');
	while(n--){
		getline(cin,bangun);
		for(int i=0;i<3;++i){
			cin>>x>>y;
			v[i]=mp(x,y);
		}
		sort(v.begin(),v.end(),comp);
		if(bangun=="persegi"){
			good=true;
			if(v[0].second==v[1].second){ //yang ketiga atau keempat ilang
				y=v[2].second;
				if(v[2].first==v[0].first && v[2].first!=v[1].first)
					x=v[1].first;
				else if(v[2].first!=v[0].first)
					x=v[0].first;
				else good=false;
				if(!(abs(v[0].first-v[1].first)==abs(v[2].first-x) && abs(v[2].first-x)==abs(y-v[1].second)))good=false;
			} else { //yang pertama atau kedua ilang
				y=v[0].second;
				if(v[0].first==v[1].first && v[0].first!=v[2].first)
					x=v[2].first;
				else if(v[0].first!=v[1].first)
					x=v[1].first;
				else good=false;
				if(!(abs(v[0].first-x)==abs(v[1].first-v[2].first) && abs(v[0].first-x)==abs(y-v[2].second)))good=false;
			}
		} else if(bangun=="persegi panjang"){
			good=true;
			if(v[0].second==v[1].second){ //yang ketiga atau keempat ilang
				y=v[2].second;
				if(v[2].first==v[0].first && v[2].first!=v[1].first)
					x=v[1].first;
				else if(v[2].first!=v[0].first)
					x=v[0].first;
				else good=false;
				if(abs(v[0].first-v[1].first)!=abs(v[2].first-x))good=false;
			} else { //yang pertama atau kedua ilang
				y=v[0].second;
				if(v[0].first==v[1].first && v[0].first!=v[2].first)
					x=v[2].first;
				else if(v[0].first!=v[1].first)
					x=v[1].first;
				else good=false;
				if(abs(v[0].first-x)!=abs(v[1].first-v[2].first))good=false;
			}
		}
		if(good)cout<<x<<' '<<y<<'\n';
		else cout<<"tidak bisa\n";
	}

	return 0;
}
