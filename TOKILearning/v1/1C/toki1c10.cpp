#include <iostream>
#include <cmath>
using namespace std;

int jmlfaktor(long n) {
	int jf=0;
	int s=trunc(sqrt(n));
	if (s*s==n) jf++;
	else if (n%s==0) jf+=2;
	for(int j=1;j<trunc(sqrt(n));j++) if(!(n%j)) jf+=2;
	return jf;
}

int main(){
	int n;
	long x;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		if(jmlfaktor(x)<5) cout<<"YA\n";
		else cout<<"TIDAK\n";
	}
	return 0;
}
