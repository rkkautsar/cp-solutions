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
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<ll> vll;
 
//defines
#define abs(_x) ((_x)<0?-(_x):(_x))
#define REP(_x) for(int __x=0;__x<_x;++__x)
#define mp(_x,_y) make_pair((_x),(_y))
#define PI 3.1415926535897932385
#define EPS 1e-9
#define INF 0x7FFFFFFF
#define INFLL 0x7FFFFFFFFFFFFFFFLL
#define ceildiv(_a,_b) ((_a)%(_b)==0?(_a)/(_b):((_a)/(_b))+1)

ll COUNT;

void divide(vll&,int,int);
void merge(vll&,int,int,int);

void divide(vll &v, int l, int r){
	if(l==r)return;
	int m=(l+r)/2;
	divide(v,l,m);
	divide(v,m+1,r);
	merge(v,l,m,r);
}

void merge(vll &v,int l,int m, int r){
	int i,j,k=0;
	i=l,j=m+1;
	vll tmp(r-l+1);
	while(i<=m && j<=r){
		if(v[j]<v[i]){
			COUNT+=m-i+1;
			tmp[k++]=v[j++];
		} else tmp[k++]=v[i++];
	}
	while(i<=m) tmp[k++]=v[i++];
	while(j<=m) tmp[k++]=v[j++];
	for(int x=0;x<k;++x)
		v[l+x]=tmp[x];
}

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	int t,n;
	ll x;
	vll v,sorted;
	map<ll,int> m;
	while(cin>>n && n){
		v.resize(n);
		for(int i=0;i<n;++i)
			cin>>v[i];
		COUNT=0;
		divide(v,0,n-1);
		cout<<COUNT<<'\n';
	}

	return 0;
}
