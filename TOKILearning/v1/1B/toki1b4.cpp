#include <iostream>
using namespace std;

int main()
{
	int a;
	cin>>a;
	if(a/10==0) cout<<"satuan\n";
	else if(a/100==0) cout<<"puluhan\n";
	else if(a/1000==0) cout<<"ratusan\n";
	else if(a/10000==0) cout<<"ribuan\n";
	else if(a/100000==0) cout<<"puluhribuan\n";
	else cout<<"ratusribuan\n";
	return 0;
}

