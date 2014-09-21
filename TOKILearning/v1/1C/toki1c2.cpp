#include <cstdio>
using namespace std;

int main(){
	int i,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		if(i==93) {
			printf("ERROR\n");
			break;
		}
		else if (i%10!=0) printf("%d\n",i);
	}
	return 0;
}
