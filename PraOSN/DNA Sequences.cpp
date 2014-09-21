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

//Union Find Disjoint Set
class UnionFind{
private:
	vi parent;
	vi rank;
	vi size;
	int disjoint;
public:
	UnionFind(){}
	UnionFind(int n){
		rank.resize(n,0);
		parent.resize(n);
		disjoint=n;
		for(int i=0;i<n;++i)parent[i]=i;
	}
	void reset(int n){
		rank.resize(n,0);
		parent.resize(n);
		disjoint=n;
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
            if(rank[x]>rank[y]){
            	parent[y]=x;
            }
            else {
                parent[x]=y;
                if(rank[x]==rank[y]) ++rank[y];
            }
            --disjoint;
        }
	}
	int countDisjointSet(){
		return disjoint;
	}
};

string a,b;
vvi memo;
int k;

int lcs(int m,int n){
	if(m<0 || n<0 || k<0)return 0;
	if(memo[m][n]!=-1)return memo[m][n];
	if(m+1<k || n+1<k)return memo[m][n]=0;
	if(a[m]==b[n]){
		memo[m][n]=0;
		int i=1;
		while(m-i>=-1 && n-i>=-1 && a[m-i+1]==b[n-i+1]){
			if(i>=k)memo[m][n]=max(memo[m][n],lcs(m-i,n-i)+i);
			++i;
		}
		if(i>=k) return memo[m][n];
		else return memo[m][n]=max(lcs(m-1,n),lcs(m,n-1));
	}
	else return memo[m][n]=max(lcs(m-1,n),lcs(m,n-1));
}


 
int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	while(cin>>k && k){
		cin>>a>>b;
		memo.clear();
		memo.resize(a.size(),vi(b.size(),-1));
		cout<<lcs(a.size()-1,b.size()-1)<<'\n';
	}

	return 0;
}
