#include <iostream>
using namespace std;

int main(){
	long n;
	cin>>n;
	for(int i=n;i>0;i--) if(!(n%i)) cout<<i<<"\n";
	return 0;
}
