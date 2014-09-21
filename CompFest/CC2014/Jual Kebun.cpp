#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char arr[700][700];
int R[500000];
int dp[700][700];

int main() {
	int T;
	scanf("%d",&T);
	while (T--) {
		int N,M;
		scanf("%d %d",&N,&M);
		int D,A,B,C,P;
		scanf("%d %d %d %d %d",&D,&A,&B,&C,&P);
		for (int i=0;i<N*N;++i) {
			if (i==0) R[i]=D;
			else {
				R[i]=(A*R[i-1]+B)%C;
			}
		}
		for (int i=0;i<N;++i) {
			for (int j=0;j<N;++j) {
				if (R[N*i+j]>=P) arr[i][j]='u';
				else arr[i][j]='s';
			}
		}
		if (arr[0][0]=='u') dp[0][0]=1;
		else dp[0][0]=0;
		for (int i=0;i<N;++i) {
			for (int j=0;j<N;++j) {
				if (i==0 && j==0) continue;
				if (i==0) {
					dp[i][j]=dp[i][j-1]+(arr[i][j]=='u'?1:0);
				}
				else {
					if (j==0) {
						dp[i][j]=dp[i-1][j]+(arr[i][j]=='u'?1:0);
					}
					else {
						dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+(arr[i][j]=='u'?1:0);
					}
				}
			}
		}

		scanf("%d %d %d %d %d",&D,&A,&B,&C,&P);
		for (int i=0;i<M*M;++i) {
			if (i==0) R[i]=D;
			else {
				R[i]=(A*R[i-1]+B)%C;
			}
		}
		long long Hasil=0;
		for (int i=0;i<M;++i) {
			for (int j=0;j<M;++j) {
				int l;
				if (R[N*i+j]>=P) l='u';
				else l='s';
				if (l=='s') {
					int x0=i,y0=j,x1=N-M+i,y1=N-M+j;
					Hasil+=dp[x1][y1]-(x0>0?dp[x0-1][y1]:0)-(y0>0?dp[x1][y0-1]:0)+(x0>0 && y0>0?dp[x0-1][y0-1]:0);
				} else {
					int x0=i,y0=j,x1=N-M+i,y1=N-M+j;
					Hasil+=(x1-x0+1)*(y1-y0+1)-(dp[x1][y1]-(x0>0?dp[x0-1][y1]:0)-(y0>0?dp[x1][y0-1]:0)+(x0>0 && y0>0?dp[x0-1][y0-1]:0));
				}
			}
		}
		printf("%lld\n",Hasil);
	}
}