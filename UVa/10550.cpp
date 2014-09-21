#include <iostream>
#include <cstdio>
using namespace std;

void cek(int& a,int& b,int &c) {
	if (a<0) a=a+40;
	if (b<0) b=b+40;
	if (c<0) c=c+40;
}

int main() {
	int a,b,c,d,deg,temp;
	while(cin>>a>>b>>c>>d){
		if(a==0 && b==0 && c==0 && d==0)return 0;
		deg=1080;
		temp=a-b;
		if(temp<0)temp+=40;
		deg+=temp*9;
		temp=c-b;
		if(temp<0)temp+=40;
		deg+=temp*9;
		temp=c-d;
		if(temp<0)temp+=40;
		deg+=temp*9;
		cout<<deg<<'\n';
	}
}