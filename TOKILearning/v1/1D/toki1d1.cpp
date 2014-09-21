#include <iostream>
using namespace std;

void tulis(long n){
	if(n<10) cout<<"satuan\n";
	else if(n<100) cout<<"puluhan\n";
	else if(n<1000) cout<<"ratusan\n";
	else if(n<10000) cout<<"ribuan\n";
	else if(n<100000) cout<<"puluhribuan\n";
	else if(n<1000000) cout<<"ratus ribuan\n";
}

int main(){
	long x;
	while(cin>>x){
		tulis(x);
	}
	return 0;
}
