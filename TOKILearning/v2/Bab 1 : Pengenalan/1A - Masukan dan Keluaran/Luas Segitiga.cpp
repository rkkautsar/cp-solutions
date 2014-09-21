#include <iostream>
using namespace std;

int main(){
	int a,b;
	cin>>a>>b;
	cout.precision(2);
	cout.setf(ios::fixed);
	cout<<a*b/2.<<'\n';
	return 0;
}
