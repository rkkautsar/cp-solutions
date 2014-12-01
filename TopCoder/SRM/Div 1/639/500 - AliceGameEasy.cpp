#include <bits/stdc++.h>
#define EPS 1e-9
using namespace std;

class AliceGameEasy{
private:
	bool is_triangular(long long x){
		double tmp=sqrt(8*x+1);
		long long dum=tmp;
		return fabs(tmp-dum)<EPS;
	}
	inline long long tri_root(long long x){
		return (sqrt(8*x+1)-1)/2;
	}
public:
	long long findMinimumValue(long long x,long long y){
		long long sum=x+y;
		if(!is_triangular(sum)) return -1;
		long long n=tri_root(sum),count=0;
		while(x){
			x-=min(n,x);
			--n;
			++count;
		}
		return count;
	}
};