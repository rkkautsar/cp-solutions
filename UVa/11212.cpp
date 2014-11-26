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
#define ceildiv(_a,_b) ((_a)%(_b)==0?(_a)/(_b):((_a)/(_b))+1)

int n,x;
map<string,int> m1,m2;
string s,t,tmp,tmp2,tmp3;
queue<pair<string,int> > q;
pair<string,int> now;
bool ketemu;

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tc=0;
	while(true){
		while(!q.empty())q.pop();
		m1.clear();
		m2.clear();
		s.clear();s="";
		t.clear();t="";
		tmp.clear();tmp="";
		tmp2.clear();tmp2="";
		tmp3.clear();tmp3="";
		x=0;
		ketemu=false;

		cin>>n;

		if(n==0) break;
		++tc;

		cout<<"Case "<<tc<<": ";

		if(n<=1){
			cout<<"0\n";
			continue;
		}

		s="";
		t="";
		

		for(int i=0;i<n;++i){
			cin>>x;
			s=s+ (char)('0'+x);
		}
		for(int i=0;i<n;++i)
			t=t+ (char)('0'+(i+1));


		if(s==t){
			cout<<"0\n";
			continue;
		}

		//cari dari t

		while(!q.empty())q.pop();

		q.push(mp(t,0));


		while(!q.empty()){
			now=q.front();
			q.pop();

			if(now.first == s){
				cout<<now.second<<'\n';
				ketemu=true;
				break;
			}

			m1[now.first]=now.second;

			if(now.second>=2)continue;

			//cout<<now.first<<'\n';
			for(int i=0;i<n-1;++i){
				for(int j=1;(i+j)<=n;++j){
					tmp3=now.first;
					tmp=tmp3.substr(i,j);
					tmp3.erase(i,j);
					for(int k=0;k<(n-j)+1; ++k){
						tmp2=tmp3;
						tmp2.insert(k,tmp);
						if(m1.find(tmp2)==m1.end())	q.push(mp(tmp2,now.second+1));
					}
				}
			}
		}


		if(ketemu) continue;

		//belom ketemu
		//cari dari s

		while(!q.empty())q.pop();
		q.push(mp(s,0));
		while(!q.empty()){
			now=q.front();
			q.pop();

			m2[now.first]=now.second;
			if(m1.find(now.first)!=m1.end()){
				//mitm
				cout<<now.second + m1[now.first]<<'\n';
				ketemu=true;
				break;
			}

			if(now.second>=2)continue;

			for(int i=0;i<n-1;++i){
				for(int j=1;(i+j)<=n;++j){
					tmp3=now.first;
					tmp=tmp3.substr(i,j);
					tmp3.erase(i,j);
					for(int k=0;k<(n-j)+1; ++k){
						tmp2=tmp3;
						tmp2.insert(k,tmp);
						if(m2.find(tmp2)==m2.end())	q.push(mp(tmp2,now.second+1));
					}
				}
			}
		}
		
		while(!q.empty())q.pop();

		if(ketemu) continue;

		cout<<"5\n";
	}

	return 0;
}