#include <iostream>
using namespace std;

void swap(int &a,int &b){
	int temp;
	temp=a;
	a=b;
	b=temp;
}

int main(){
	int m,n;
	cin>>m>>n;
	swap(m,n);
	cout<<m<<" "<<n<<"\n";
	return 0;
}
