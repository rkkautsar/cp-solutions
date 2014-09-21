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
#define readl(_s) getline(cin,_s);cin.ignore(9999,'\n')
#define ceildiv(_a,_b) ((_a)%(_b)==0?(_a)/(_b):((_a)/(_b))+1)

//classes

 
int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	int t,n,idx,tmp,last,c;
	//bool first=true;
	vii stick;
	vi l,p;
	cin>>t;
	while(t--){
		c=0;
		cin>>n;
		stick.resize(n);
		for(int i=0;i<n;++i)
			cin>>stick[i].first>>stick[i].second;
		last=stick.size();
		
		while(last){
			sort(stick.begin(),stick.begin()+(last-1));
			l.resize(last,1);
			p.resize(last);
			//cout<<"here\n";
			for(int i=0;i<last;++i)p[i]=i;
			for(int i=0;i<last;++i){
				for(int j=0;j<i;++j)
					if(stick[i].first>=stick[j].first && stick[i].second>=stick[j].second && l[j]+1 > l[i]) p[i]=j,l[i]=l[j]+1;
			}
			idx=0;
			for(int i=1;i<last;++i)
				if(l[i]>l[idx])idx=i;
			//if(first)cout<<l[idx]<<'\n',first=0;
			do{
				swap(stick[idx],stick[last-1]);
				idx=p[idx];
				--last;
			}while(p[idx]!=idx);
			++c;
		}
		cout<<c<<'\n';
		
	}

	return 0;
}
