#include <iostream>
using namespace std;

int fct(int x){
	if (x==0) return 1;
	else if(x<3) return x;
	else {
		int f=2;
		for(int i=3;i<=x;i++) f*=i;
		return f;
	}
}

int main(){
	int n;
	cin>>n;
	if(n>10) cout<<"ditolak\n";
	else cout<<fct(n)<<"\n";
	return 0;
}
