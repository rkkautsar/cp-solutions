#include <iostream>
#include <set>
using namespace std;
set<string> st;
bool issub(string a,string b){
    int pos=-1;
    bool ok=1;
    for(int i=0,n=b.size();ok && i<n;++i)
        ok=(pos=a.find(b[i],pos+1))!=string::npos;
    return ok;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin>>s;
    int n,cnt=0;
    cin>>n;
    string x;
    for(int i=0;i<n;++i){
        cin>>x;
        if(st.find(x)!=st.end()){
            ++cnt;
            continue;
        }
        if(issub(s,x)){
            ++cnt;
            st.insert(x);
        }
    }
    cout<<cnt<<'\n';
    return 0;
}
