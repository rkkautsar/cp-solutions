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
 
//defines
#define abs(_x) ((_x)<0?-(_x):(_x))
#define REP(_x) for(int __x=0;__x<_x;++__x)
#define mp(_x,_y) make_pair((_x),(_y))
#define PI 3.1415926535897932385
#define EPS 1e-9
#define INF 0x7FFFFFFF
#define INFLL 0x7FFFFFFFFFFFFFFFLL
#define INFD 1e12
#define ceildiv(_a,_b) ((_a)%(_b)==0?(_a)/(_b):((_a)/(_b))+1)

int n,m,a,b,c,d;
double v,l;
vd x,dist;
vector<vector<pair<int,double> > > adjlist;
priority_queue<pair<double,int>,vector<pair<double,int> >,greater<pair<double,int> > > pq;
int node;
double waktu;

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		cin>>a>>b>>v;
		--a;--b;
		x.clear();
		adjlist.clear();
		dist.clear();

		x.resize(n);
		adjlist.resize(n);
		x[b]=INF;
		for(int i=0;i<n;++i){
			if(i==b)continue;
			cin>>x[i];
		}
		for(int i=0;i<m;++i){
			cin>>c>>d>>l;
			--c;
			--d;
			adjlist[c].push_back(mp(d,l));
			adjlist[d].push_back(mp(c,l));
		}
		dist.resize(n,INFD);
		while(!pq.empty())pq.pop();
		if(x[a]>0)pq.push(mp(0,a));
		while(!pq.empty()){
			waktu=pq.top().first;
			node=pq.top().second;
			pq.pop();
			if((x[node]-waktu)<EPS)continue;
			if(waktu>dist[node])continue;
			for(int i=0;i<adjlist[node].size();++i){
				if(waktu+adjlist[node][i].second/v < dist[adjlist[node][i].first] && waktu+adjlist[node][i].second/v < x[adjlist[node][i].first]){
					//cout<<"here\n";
					dist[adjlist[node][i].first]=waktu+adjlist[node][i].second/v;
					pq.push(mp(dist[adjlist[node][i].first],adjlist[node][i].first));
				}
			}
		}
		//for(int i=0;i<n;++i) cout<<fixed<<setprecision(3)<<dist[i]<<'\n';
		if(dist[b]>=INFD){
			cout<<"GAME OVER\n";
		} else {
			cout<<fixed<<setprecision(6)<<dist[b]<<'\n';
		}
	}

	return 0;
}
