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
    cin.tie(0); 
     
    string s;
    getline(cin,s);
    int n,k,q;
    cin>>n>>k>>q;
    if(q<n || n>100){
	    int l=1,r=n,m;
	    while(l<r){
	        m=(l+r)/2;
	        //cout<<l<<' '<<m<<' '<<r<<'\n';
	        cout<<1<<' '<<m<<'\n'<<flush;
	        cin>>s;
	        if(s[0]=='t') r=m-1;
	        else{
	            cout<<m<<' ';
	            for(int i=1;i<=m;++i)cout<<i<<(i==m?'\n':' ');
	            cout<<flush;
	            cin>>s;
	            if(s[0]=='y') return 0;
	            else l=m+1;
	        }
	        if(l==r)break;
	    }
	    cout<<l<<' ';
	    for(int i=1;i<=l;++i)cout<<i<<(i==l?'\n':' ');
	    cout<<flush;
	} else {
		if(k==1){
			vi jawaban;
			for(int i=1;i<=n;++i){
				cout<<"1 "<<i<<'\n'<<flush;
				cin>>s;
				if(s[0]!='t') jawaban.push_back(i);
			}
			cout<<jawaban.size()<<' ';
			for(int i=0,len=jawaban.size();i<len;++i)cout<<jawaban[i]<<(i==len-1?'\n':' ');
			cout<<flush;
		} else {
			//TODO: k=2
		}
	}
 
    return 0;
}