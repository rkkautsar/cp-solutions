#include <iostream>
using namespace std;

int main(){
	int n;
	int a=0;
	int b;
	cin>>n;
	for(int i=1;i<=n;i++){
		b=1;
		while(b<=i){
			cout<<a;
			if(a<9) a++;
			else a=0;
			b++;
		}
		cout<<endl;
	}
	return 0;
}
