#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m;
    cin>>n>>m;
    vector<int> v(n),b(n+1,0),c(m+1,0),l(n+1,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
        b[v[i]]+=c[v[i]]*(i-l[v[i]]);
        c[v[i]]++;
        l[v[i]]=i+1;
    }
    for(int i=1;i<=m;i++){
        b[i]+=c[i]*(n-l[i]);
    }
    cout<<max_element(b.begin(),b.end())-b.begin()<<"\n";
    return 0;        
}
