#include <iostream>
using namespace std;

int i,j,m[3][3];

int main()
{
	for (i=0;i<3;i++){
		for (j=0;j<3;j++){
			cin>>m[i][j];
		}
	}
	for (j=0;j<3;j++){
		for (i=0;i<3;i++){
			cout<<m[i][j];
			if(i==2) cout<<endl;
			else cout<<" ";
		}
	}
	return 0;
}
