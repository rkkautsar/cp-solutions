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

#define MAX_SQRT 175

int square(int x){
	for(int i=2;i<MAX_SQRT;++i)
		if(i*i==x)return i;
	return -1;
}

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int p[6];
	for(int i=0;i<6;++i)cin>>p[i];

	int area=0;
	for(int i=0;i<3;++i)
		area+=p[i*2]*p[i*2+1];
	
	if(square(area)==-1){
		cout<<-1<<'\n';
		return 0;
	}

	int x = square(area);

	char ci,cj,ck;

	int ii,jj,kk;
	for(int i=0;i<6;++i){
		for(int j=0;j<6;++j){
			if((j>>1)==(i>>1))continue;
			for(int k=0;k<6;++k){
				if((k>>1)==(j>>1) || (k>>1)==(i>>1))continue;
				ii = (i&1?i-1:i+1);
				jj = (j&1?j-1:j+1);
				kk = (k&1?k-1:k+1);
				ci = 'A'+(i>>1);
				cj = 'A'+(j>>1);
				ck = 'A'+(k>>1);
				// cout<<i<<' '<<ii<<','<<j<<' '<<jj<<','<<k<<' '<<kk<<'\n';

				if(p[i]+p[j]==x && p[ii]==p[jj] && p[ii]+p[kk]==x && p[k]==x){
					cout<<x<<'\n';
					for(int a=0;a<p[ii];++a){
						for(int b=0;b<p[i];++b) cout<<ci;
						for(int b=0;b<p[j];++b) cout<<cj;
						cout<<'\n';
					}
					for(int a=0;a<p[kk];++a){
						for(int b=0;b<p[k];++b) cout<<ck;
						cout<<'\n';
					}
					return 0;
				} else if(p[i]==x){
					if(p[j]+p[k]==x && p[jj]==p[kk] && p[ii]+p[jj]==x){
						cout<<x<<'\n';
						for(int a=0;a<p[ii];++a){
							for(int b=0;b<p[i];++b) cout<<ci;
							cout<<'\n';
						}
						for(int a=0;a<p[jj];++a){
							for(int b=0;b<p[j];++b) cout<<cj;
							for(int b=0;b<p[k];++b) cout<<ck;
							cout<<'\n';
						}
						return 0;
					} else if(p[j]==x && p[k]==x && p[ii]+p[kk]+p[jj]==x){
						cout<<x<<'\n';
						for(int a=0;a<p[ii];++a){
							for(int b=0;b<p[i];++b) cout<<ci;
							cout<<'\n';
						}
						for(int a=0;a<p[jj];++a){
							for(int b=0;b<p[j];++b) cout<<cj;
							cout<<'\n';
						}
						for(int a=0;a<p[kk];++a){
							for(int b=0;b<p[k];++b) cout<<ck;
							cout<<'\n';
						}
						return 0;
					}
				} else if(p[i]+p[j]+p[k]==x && p[ii]==x && p[jj]==x && p[kk]==x){
					cout<<x<<'\n';
					for(int a=0;a<p[ii];++a){
						for(int b=0;b<p[i];++b) cout<<ci;
						for(int b=0;b<p[j];++b) cout<<cj;
						for(int b=0;b<p[k];++b) cout<<ck;
						cout<<'\n';
					}
					return 0;
				}
			}
		}
	}	
	
	cout<<-1<<'\n';
	return 0;
}
