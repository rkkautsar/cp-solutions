#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
string s;

char lowest(){
    char c=s[0];
    for(int i=1,n=s.size();i<n;++i)c=min(c,s[i]);
    return c;
}

void f(){
    char now=lowest();
    int n=s.size(),i=0;
    while(i<n){
        if(s[i]==now){
            s.erase(i,1);
            --n;
        } else ++i;
        if(s.find(now)==string::npos)now=lowest();
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>s;
    int c=0;
    while(!s.empty()){
        f();
        ++c;
    }
    cout<<c-1<<'\n';
    return 0;
}
