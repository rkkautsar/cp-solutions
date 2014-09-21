#include <cstdio>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	double arr[n];
	double min,max,sum;
	sum=0;
	for(int i=0;i<n;i++){
		scanf("%lf",&arr[i]);
		if(i==0) {
			min=arr[0];
			max=arr[0];
		} else {
			if (arr[i]>max) max=arr[i];
			if (arr[i]<min) min=arr[i];
		}
		sum+=arr[i];
	}
	double rata=sum/n;
	printf("%.2lf %.2lf %.2lf\n",min,max,rata);
	return 0;
}
