#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    /*int guess[1200];
    int n;
    cout<<"init\n"<<flush;
    cin>>n;
    fill(guess,guess+n,500);
    cout<<"ask";
    int idx=0,w,x;
    for(int i=0;i<n;++i)cout<<' '<<guess[i];
    cout<<'\n'<<flush;
    cin>>w;
    while(true){
        
    }*/
    
    cout<<"init\n"<<flush;
    int n,w;
    cin>>n;
    cout<<"ask";
    for(int i=0;i<n;++i)cout<<" 1";
    cout<<'\n'<<flush;
    cin>>w;
    if(w==0){
        cout<<"ask";
        for(int i=0;i<n;++i)cout<<" 1";
        cout<<'\n'<<flush;
    }
    return 0;
}
