#include <iostream>
#include <list>
using namespace std;
 
bool reverse=false;
int len=0;
list<int> q,f; //q=queue, f=freq
 
inline void add(int m){
    int n;
    cin>>n;
    len+=n;
    cout<<len<<"\n";
    if(reverse){
        if(q.empty() || q.front()!=m){
            q.push_front(m);
            f.push_front(n);
        } else {
            f.front()+=n;
        }
    } else {
        if(q.empty() || q.back()!=m){
            q.push_back(m);
            f.push_back(n);
        } else {
            f.back()+=n;
        }
    }
}
 
inline void loopdel(int n){
    if (f.front()>n) f.front()-=n;
    else {
        n-=q.front();
        q.pop_front();
        f.pop_front();
        if(n!=0) loopdel(n);
    }
}
 
inline void loopdelr(int n){
    if (f.back()>n) f.back()-=n;
    else {
        n-=q.back();
        q.pop_back();
        f.pop_back();
        if(n!=0) loopdelr(n);
    }
}
 
inline void del(int n){
    len-=n;
    if(reverse){
        cout<<q.back()<<"\n";
        loopdelr(n);
    } else {
        cout<<q.front()<<"\n";
        loopdel(n);
    }
}       
     
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     
    int n,x;
    string s;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        if(s[0]=='r') reverse=not reverse;
        else{
            cin>>x;
            if(s[0]=='a') add(x);
            else del(x);
        }
    }
    return 0;
}
