#include <cstdio>
using namespace std;

int main()
{
	char op;
	int a,b;
	scanf("%d %s %d",&a,&op,&b);
	switch (op){
		case '+': printf("%d\n",a+b);
		break;
		case '-': printf("%d\n",a-b);
		break;
		case '*': printf("%d\n",a*b);		
		break;
		case '>': if(a>b) printf("benar\n"); else printf("salah\n");
		break;
		case '<': if(a<b) printf("benar\n"); else printf("salah\n");
		break;
		case '=': if(a==b) printf("benar\n"); else printf("salah\n");
		break;
	}
	return 0;
}

