#include <iostream>
using namespace std;
long long n,i,j,imax,maks;
long long x[100000],arr[100000];

void sort(long long a[],long long n){
	int i,j,temp;
	for (i=0;i<n;i++){
		for (j=n-1;j>i;j--){
			if (a[j]>a[j-1]){
				temp=a[j];
				a[j]=a[j-1];
				a[j-1]=temp;
			}
		}
	}
}

int main(){
	cin>>n;
	for(i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,n);
	for(i=0;i<n;i++){
		x[i]=0;
		for(j=i;j<n;j++){
			if(arr[i]==arr[j]){
				x[i]+=1;
			}
		}
	}
	imax=0;
	maks=x[0];
	for(i=0;i<n;i++){
		maks=max(maks,x[i]);
	}
	for(i=0;i<n;i++){
		if (x[i]==maks) {
			imax=i;
			break;
		}
	}
	cout<<arr[imax]<<'\n';
	return 0;
}
