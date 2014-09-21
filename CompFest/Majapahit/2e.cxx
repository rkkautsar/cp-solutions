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
	
    int t;
    cin>>t;
    vi v(10);
    int balik[3]={0,1,8};
    REP(t){
        for(int i=0;i<10;++i)cin>>v[i];
        string s;
        //coba lebih dari 1 digit
        while(v[9] && v[6]){
            s+='9';
            --v[9];
            --v[6];
        }
        for(int i=2;i>=0;--i){
            if(i==0 && s.empty()) continue;
            while(v[balik[i]]>=2){
                s+=balik[i]+'0';
                v[balik[i]]-=2;
            }
        }
        while(v[0]>=2 && !s.empty()){
            s+='0';
            v[0]-=2;
        }
        if(!s.empty()){
            bool mid=0;
            for(int i=2;i>=0;--i)
                if(v[balik[i]]){
                    s+=balik[i]+'0';
                    mid=1;
                    break;
                }
            for(int i=s.size()-1;i>=0;--i){
                if(mid && i==(int)s.size()-1) continue;
                if(s[i]!='9')s+=s[i];
                else s+='6';
            }
            cout<<s<<'\n';
            continue;
        }
        //coba 1 digit
        for(int i=2;i>=0;--i)
            if(v[balik[i]]){
                s=balik[i]+'0';
                cout<<s<<'\n';
                break;
            }
        if(s.empty()) //ga ada yang bisa
            cout<<-1<<'\n';        
        
    }
    
	return 0;
}

