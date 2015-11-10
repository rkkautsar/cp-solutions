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

#define abs(_x) ((_x)<0?-(_x):(_x))
#define REP(_a,_b) for(int (_a)=0;(_a)<(_b);++(_a))
#define mp(_x,_y) make_pair((_x),(_y))
#define PI 3.1415926535897932385
#define EPS 1e-9
#define INF 0x00FFFFFF
#define INFLL 0x00FFFFFFFFFFFFFFLL
#define ceildiv(_a,_b) ((_a)%(_b)==0?(_a)/(_b):((_a)/(_b))+1)
#define fi first
#define se second

const int MAX_BIT = 100005;
int b[MAX_BIT][31]; //2^30, default 0

void update(int x,int y,const int &val){
	while(x<=MAX_BIT){
		b[x][y]+=val;
		x+=x&(-x);
	}}

void update(int l,int r,int y,const int &val){
	update(l,y,val);
	update(r+1,y,-val);
}

int sum(int x,int y){
	int sum=0;
	while(x) sum+=b[x][y], x-=x&(-x);
	return sum;}

ll val(int x){
	ll ret=0,powerTwo=1;
	for(int i=0;i<=30;++i,powerTwo<<=1)
		ret+=1LL*(sum(x,i)>0)*powerTwo;
	return ret;
}

int sum(int l,int r,int y){
	return sum(r,y)-sum(l-1,y);
}

bool isSame(int l,int r,int y){
	return sum(l,r,y)==r-l+1 || sum(l,r,y)==0;
}

struct qr{
	int l,r,q;
	qr(){}
};

bool cmp(qr a,qr b){
	if((a.r-a.l)==(b.r-b.l)) return a.l<b.l;
	else return (a.r-a.l)<(b.r-b.l);
}

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,m,l,r,q,now,digit;
	cin>>n>>m;
	vector<qr> query(m);
	for(int i=0;i<m;++i)
		cin>>query[i].l>>query[i].r>>query[i].q;

	bool conflict=false;
	int cnt=0;
	for(int i=0;i<m && !conflict;++i){
		l=query[i].l;
		r=query[i].r;
		q=query[i].q;

		if(l==r){
			++cnt;
			continue;
		}

		digit=0;


		while(q && !conflict){
			now=q&1;

			if(isSame(l,r,digit))
				update(l,r,digit,now);
			else
				conflict=true;

			q>>=1;
			++digit;
		}
		
	}

	// for(int i=1;i<=n;++i){
	// 	for(int j=5;j>=0;--j)cout<<sum(i,j);
	// 	cout<<'\n';
	// }

	for(int i=0;i<cnt && !conflict;++i){
		l=query[i].l;
		q=query[i].q;
		// cout<<l<<' '<<q<<' '<<val(l)<<' '<<(q&val(l))<<'\n';
		if((q & val(l)) == val(l)){
			if(q==val(l))continue;
			digit=0;
			while(q){
				if(q&1) update(l,l,digit,1);

				q>>=1;
				++digit;
			}
			// for(int i=1;i<=n;++i){
			// 	for(int j=5;j>=0;--j)cout<<sum(i,j);
			// 	cout<<'\n';
			// }
		} else conflict=true;
	}

	if(conflict){
		cout<<"NO\n";
		return 0;
	}

	cout<<"YES\n";
	for(int i=1;i<=n;++i)
		cout<<val(i)<<(i==n?'\n':' ');

	// for(int i=1;i<=n;++i){
	// 	for(int j=5;j>=0;--j)cout<<sum(i,j);
	// 	cout<<'\n';
	// }
	
	return 0;
}
