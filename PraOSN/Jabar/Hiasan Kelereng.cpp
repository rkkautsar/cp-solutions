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


int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	//cin.tie(0);	
	
	int n;
	cin>>n;
	string s;
	cin>>s;
	vi remaining(26,0),remcopy;
	for(int i=0,len=s.size();i<len;++i)
		++remaining[s[i]-'A'];
	s="";
	for(int i=0;i<26;++i)
		if(remaining[i]) s+=('A'+i);
	if(s.size()<3){
		cout<<"-1\n";
		return 0;
	}
	int mx=0,val,offset;
	vs select;
	string tmp;
	tmp="aaa";
	for(int i=0,len=s.size();i<len;++i){
		tmp[0]=s[i];
		for(int j=0;j<len;++j){
			if(j==i)continue;
			tmp[1]=s[j];
			for(int k=0;k<len;++k){
				if(k==j || k==i)continue;
				tmp[2]=s[k];
				//cout<<tmp<<'\n';
				select.push_back(tmp);
			}
		}
	}
	int lololol;
	for(int i=0,len=select.size();i<len;++i){
		lololol=min(remaining[select[i][0]-'A'],min(remaining[select[i][1]-'A'],remaining[select[i][2]-'A']));
		val=3*lololol;
		//cout<<select[i]<<' '<<lololol<<'\n';
		for(int j=0;j<3;++j){
			if(remaining[select[i][j]-'A']<=lololol)break;
			++val;
		}
		mx=max(mx,val);
	}
	cout<<mx<<'\n';

	return 0;
}
