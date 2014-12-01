#include <bits/stdc++.h>
using namespace std;
 
// typedef
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<double,double> dd;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<bool> vb;
 
//defines
#define abs(_x) ((_x)<0?-(_x):(_x))
#define REP(_x) for(int __x=0;__x<_x;++__x)
#define mp(_x,_y) make_pair((_x),(_y))
#define PI acos(-1)
#define EPS 1e-9
#define INF 0x0FFFFFFF
#define INFLL 0x0FFFFFFFFFFFFFFFLL
#define ceildiv(_a,_b) ((_a)%(_b)==0?(_a)/(_b):((_a)/(_b))+1)
#define fi first
#define se second

int ctox(char c){
	if(c==' ')return 0;
	if(c=='.')return 1;
	if(c=='x')return 2;
	if(c=='W')return 3;
}
char xtoc(int x){
	if(x==0)return ' ';
	if(x==1)return '.';
	if(x==2)return 'x';
	if(x==3)return 'W';
}

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	string s,next;
	int t,dna[10],tmp;
	bool first=true;

	cin>>t;
	while(t--){
		if(!first)cout<<'\n';
		first=false;
		for(int i=0;i<10;++i)cin>>dna[i];
		s.assign(40,' ');
		s[19]='.';
		for(int day=0;day<50;++day){
			cout<<s<<'\n';
			next=s;
			for(int i=0;i<40;++i){
				tmp=ctox(s[i]);
				if(i>0)tmp+=ctox(s[i-1]);
				if(i<39)tmp+=ctox(s[i+1]);
				next[i]=xtoc(dna[tmp]);
			}
			s=next;
		}
	}

	return 0;
}
