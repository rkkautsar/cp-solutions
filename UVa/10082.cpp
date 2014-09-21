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
 
int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	map<char,char> M;
	M['1']='`';
	M['2']='1';
	M['3']='2';
	M['4']='3';
	M['5']='4';
	M['6']='5';
	M['7']='6';
	M['8']='7';
	M['9']='8';
	M['0']='9';
	M['-']='0';
	M['=']='-';
	M['W']='Q';
	M['E']='W';
	M['R']='E';
	M['T']='R';
	M['Y']='T';
	M['U']='Y';
	M['I']='U';
	M['O']='I';
	M['P']='O';
	M['[']='P';
	M[']']='[';
	M['\\']=']';
	M['S']='A';
	M['D']='S';
	M['F']='D';
	M['G']='F';
	M['H']='G';
	M['J']='H';
	M['K']='J';
	M['L']='K';
	M[';']='L';
	M['\'']=';';
	M['X']='Z';
	M['C']='X';
	M['V']='C';
	M['B']='V';
	M['N']='B';
	M['M']='N';
	M[',']='M';
	M['.']=',';
	M['/']='.';
	int n;
	string s;
	while(getline(cin,s)){
		n=s.size();
		for(int i=0;i<n;++i){
			if(s[i]==' ')cout<<' ';
			else cout<<M[s[i]];
		}
		cout<<'\n';
	}

	return 0;
}