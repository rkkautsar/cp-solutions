#include <iostream>
#include <cstdio>
using namespace std;

bool ind;


bool go(int val,int pos,int N,int K,int dp[][101][2],int arr[]) {
	val%=K;
	if (pos==N && val%K!=0) return false;
	else if (pos==N && val%K==0) {
		ind=true;
		return true;
	}
	int valT=(val<0?-val:val);
	if (ind) return true;
	int ij;
	if (val<0) ij=0;
	else ij=1; 
	if (dp[pos][valT%K][ij]==1) return true;
	else if (dp[pos][valT%K][ij]==-1) return false;
	else {
		bool test;
		test=go(pos+1,(val+arr[pos])%K,N,K,dp,arr);
		if (!test) test=go(pos+1,(val-arr[pos])%K,N,K,dp,arr);
		if (test==true) dp[pos][valT][ij]=1;
		else dp[pos][valT][ij]=-1;
		return test;
	}
}

int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		ind=false;
		int N,K;
		int arr[10000];
		int dp[10000][101][2];
		for (int i=0;i<10000;++i) for (int j=0;j<101;++j) for (int k=0;k<2;++k) dp[i][j][k]=0;
		cin >> N >> K;
		for (int i=0;i<N;++i) {
			cin >> arr[i];
		}
		ind=go(arr[0],1,N,K,dp,arr);
		if (ind) cout<<"Divisible\n";
		else cout << "Not divisible\n";
	}
}