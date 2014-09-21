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
#define fir first
#define sec second
#define PI 3.1415926535897932385
#define EPS 1e-9
#define PHI 1.6180339887498948482
#define INF 0x7FFFFFFF
#define INFLL 0x7FFFFFFFFFFFFFFFLL
#define readl(_s) getline(cin,_s);cin.ignore(9999,'\n')
 
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

struct iii{
	int first,second,third;
	iii(){
		first=second=third=0;
	}
	iii(int a,int b,int c){
		first=a,second=b,third=c;
	}
	bool operator<(iii other) const{
		if(other.first==first){
			if(other.second==second)return other.third<third;
			return other.second<second;
		}
		return other.first<first;
	}
};

vs board(8);
set<iii> m;
int dirx[4]={-2,-2,2,2},
	diry[4]={-2,2,-2,2};
void dfs(vector<vb> &v,int x,int y,vector<vvi> &sk,int depth=0){
	m.insert(iii(x,y,depth));
	v[x][y]=true;
	sk[x][y].push_back(depth);
	for(int i=0;i<4;++i){
		int newx=x+dirx[i],newy=y+diry[i];
		if(newx>=0 && newx<8 && newy>=0 && newy<8 && m.find(iii(newx,newy,depth+1))==m.end() && sk[newx][newy].size()<20)
			dfs(v,newx,newy,sk,depth+1);
	}
}

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	int t;
	cin>>t;
	while(t--){
		m.clear();
		vector<vb> bk1(8,vb(8,false)), bk2(8,vb(8,false));
		vector<vvi> sk1(8,vvi(8)),sk2(8,vvi(8));
		for(int i=0;i<8;++i)cin>>board[i];
		ii k1,k2;
		for(int i=0,k=0;i<8;++i)
			for(int j=0;j<8;++j)
				if(board[i][j]=='K' && k==0)k1=ii(i,j),++k;
				else if(board[i][j]=='K')k2=ii(i,j);
		dfs(bk1,k1.first,k1.second,sk1);
		dfs(bk2,k2.first,k2.second,sk2);
		bool found=false;
		/*
		for(int i=0;i<8;++i)
			for(int j=0;j<8;++j)
				cerr<<bk1[i][j]<<(j==7?'\n':' ');
		cerr<<'\n';
		for(int i=0;i<8;++i)
			for(int j=0;j<8;++j)
				cerr<<bk2[i][j]<<(j==7?'\n':' ');
		cerr<<'\n';
		*/
		for(int i=0;i<8 && !found;++i)
			for(int j=0;j<8 && !found;++j)
				if(bk1[i][j] && bk2[i][j] && board[i][j]=='.'){
					for(int k=0;k<sk1[i][j].size();++k)
						for(int l=0;l<sk2[i][j].size();++l)
							if(sk1[i][j][k]==sk2[i][j][l])
					found =true;
				}
		if(!found)cout<<"NO\n";
	}

	return 0;
}
