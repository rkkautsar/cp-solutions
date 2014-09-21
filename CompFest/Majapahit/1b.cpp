//IO
#include <iostream> //#include <utility>
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
#include <vector> //#include <iterator>
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

//defines
#define abs(_x) ((_x)<0?-(_x):(_x))
#define REP(_x) for(int __x=0;__x<_x;++__x)
#define PI 3.1415926535897932385
#define EPS 1e-9
#define PHI 1.6180339887498948482
#define INF 0x7FFFFFF
#define INFLL 0x7FFFFFFF

//functions
template<class T,class Type> 
inline void reset(T begin, T end, Type fills=0){
	fill(begin,end,fills);
}
template<class T,class Type>
inline void reset(T stdcontainer, Type fills=0){
	fill(stdcontainer.begin(),stdcontainer.end(),fills);
}

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
    
    int t,mx,cur;
    string s;
    cin>>t;
    getline(cin,s);
    REP(t){
        mx=0;
        getline(cin,s);
        for(int i=0,n=s.size();i<n-3;++i){
            if(s[i]=='l' && s[i+1]=='h'){
                cur=0;
                int j=i+2;
                while(j<n && s[j]=='o'){
                    ++cur;
                    if(s[j]=='?') break;
                    ++j;
                }
                if(s[j]=='?') mx=max(mx,cur);
            }
        }
        cout<<mx<<'\n';
    }
    
	
	return 0;
}

