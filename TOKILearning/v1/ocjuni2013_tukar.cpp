#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#define M 1000000007
using namespace std;
typedef pair<string,string> ss;
set<ss> s;
int N,k;

void f(int n,string a,string b,int la,int lb){
    if(n==0){
        if(a.size()==N && b.size()==N)
            s.insert(make_pair(a,b));
        return;
    }
    for(int i=0;i<k;++i){
        char x='a'+i;
        if(la<=i){
            f(n-1,a+x,b,i,lb);
            f(n-1,a,b+x,i,i);
        }
        if(lb<=i){
            f(n-1,a,b+x,la,i);
            f(n-1,a+x,b,i,i);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>k;
    f(2*N,"","",0,0);
    cout<<s.size()<<'\n';
    for(__typeof(s.begin()) it=s.begin();it!=s.end();++it){
        cout<<it->first<<' '<<it->second<<'\n';
    }
    return 0;
}
