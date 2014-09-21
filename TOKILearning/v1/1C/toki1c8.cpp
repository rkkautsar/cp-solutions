#include <iostream>
#include <cmath>

using namespace std;

bool isprime(int x){
	bool c;
	if (x<2) return false;
	else if (x==2) return true;
	else if (x%2==0) return false;
	else {
		c=true;
		for(int i=3;i<=trunc(sqrt(x));i+=2) if(x%i==0) c=false;
		return c;
	}
}

int main(){
	int n;
	while(cin>>n){
		if (isprime(n)) cout<<"YA\n";
		else cout<<"TIDAK\n";
	}
	return 0;
}
	
	
