#include <iostream>
using namespace std;

int main(){
	int n=0;
	int x;
	int a[1000];
	while(cin>>x){
		a[n]=x;
		n++;
	}
	for(int i=n-1;i+1>0;i--){
		cout<<a[i]<<"\n";
	}
	return 0;
}
