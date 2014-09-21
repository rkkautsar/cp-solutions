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
    
    int t,n,m;
    cin>>t;
    REP(t){
        cin>>n>>m;
        vvi v(n,vi(m));
        for(int i=0;i<n;++i)
        for(int j=0;j<m;++j) cin>>v[i][j];
        vi left(n,0),bottom(m,0);
        for(int i=0;i<n;++i){
            int x=i,y=0;
            while(x<n && x>=0 && y<m && y>=0)
                left[i]+=v[x++][y++];
        }
        for(int i=0;i<m;++i){
            int x=n-1,y=i;
            while(x<n && x>=0 && y<m && y>=0)
                bottom[i]+=v[x--][y++];
        }
        int mx=0,cur;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                cur=0;
                if(i>=j) cur+=left[i-j]-v[i][j];
                if(j>=n-i-1) cur+=bottom[j-(n-i-1)]-v[i][j];
                mx=max(mx,cur);
            }
        }
        cout<<mx<<'\n';
    }
	
	return 0;
}

