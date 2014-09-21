#include <cstdio>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	while (n%2==0) n/=2;
	if (n==1) printf("TRUE\n");
	else printf("FALSE\n");
	return 0;
}
