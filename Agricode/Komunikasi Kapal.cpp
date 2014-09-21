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

struct cord {
		int x,y,r;
};

vector<cord> arr;
vector<int> tempat2;
vector<int> tempat1;
queue<pair<int, int> > q;
int lol[100];
int X1,Y1,X2,Y2,N;

bool cari(int x,int y,int I) {
	if (abs((arr[I].y-y)*(arr[I].y-y))+abs((arr[I].x-x)*(arr[I].x-x))<=arr[I].r*arr[I].r) return true;
	else return false;
}

bool cari2(int x,int y) {
	if (abs((arr[x].y-arr[y].y)*(arr[x].y-arr[y].y))+abs((arr[x].x-arr[y].x)*(arr[x].x-arr[y].x))<=(arr[x].r+arr[y].r)*(arr[x].r+arr[y].r)) return true;
	else return false;
}

void go(pair<int,int> sekarang) {
	for (int i=0;i<N;++i) {
		if (i==sekarang.first || lol[i]!=0) continue;
		if (cari2(sekarang.first,i)) {
			//printf("tes\n");
			q.push(make_pair(i,sekarang.second+1));
			lol[i]=sekarang.second+1;
		}
	}
}

int find() {
	for (int i=0;i<tempat1.size();++i) {
		q.push(make_pair(tempat1[i],1));
		lol[tempat1[i]]=1;
	}
	while (!q.empty()) {
		pair<int,int> sasaran=q.front();
		//printf("%d\n",sasaran.first);
		q.pop();
		go(sasaran);
	}
	int min=1000000;
	for (int i=0;i<tempat2.size();++i) {
		if (lol[tempat2[i]]!=0) {
			if (lol[tempat2[i]]<min) min=lol[tempat2[i]];
		}
	}
	if (min==1000000) return -1;
	else return min;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i=0;i<100;++i) lol[i]=0;
	cin>>N;
	int x,y,r;		
	for (int i=0;i<N;++i) {
		cin>>x>>y>>r;
		cord a;
		a.x=x;
		a.y=y;
		a.r=r;
		arr.push_back(a);
	}
	cin>>X1>>Y1>>X2>>Y2;
	for (int i=0;i<N;++i) {
		if (cari(X1,Y1,i)) tempat1.push_back(i);
		if (cari(X2,Y2,i)) tempat2.push_back(i);
	}
	cout<<find()<<'\n';
}
