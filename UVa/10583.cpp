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

//Union Find
class UnionFind{
private:
	vi parent;
	vi rank;
public:
	UnionFind(int n){
		rank.resize(n,0);
		parent.resize(n);
		for(int i=0;i<n;++i)parent[i]=i;
	}
	int findSet(int i){
        return (parent[i]==i)? i : (parent[i]=findSet(parent[i]));
	}
	bool isSameSet(int i,int j){
        return findSet(i)==findSet(j);
	}
	void unionSet(int i,int j){
        if(!isSameSet(i,j)){
            int x=findSet(i), y=findSet(j);
            if(rank[x]>rank[y]) parent[y]=x;
            else {
                parent[x]=y;
                if(rank[x]==rank[y]) ++rank[y];
            }
        }
	}
	int countDisjointSet(){
		int n=parent.size();
		vi v(n);
		for(int i=0;i<n;++i)v[i]=findSet(i);
		sort(v.begin(),v.end());
		v.resize(unique(v.begin(),v.end())-v.begin());
		return v.size();
	}
};

 
int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	int n,m,a,b,c=0;
	while(cin>>n>>m && (n && m)){
		UnionFind u(n);
		for(int i=0;i<m;++i){
			cin>>a>>b;
			u.unionSet(a-1,b-1);
		}
		cout<<"Case "<<++c<<": ";
		cout<<u.countDisjointSet()<<'\n';
	}

	return 0;
}
