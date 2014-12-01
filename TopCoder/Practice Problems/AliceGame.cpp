#include <bits/stdc++.h>
#define EPS 1e-9
using namespace std;

class AliceGame{
private:
	bool is_quadratic(long long x){
		double tmp=sqrt(x);
		long long dum=tmp;
		return fabs(tmp-dum)<EPS;
	}
	inline long long _root(long long x){
		return (sqrt(x)*2-1)+2;
	}
public:
	long long findMinimumValue(long long x,long long y){
		long long sum=x+y;
		if(!is_quadratic(sum)) return -1;
		long long n=_root(sum),count=0;
		while(x){
			if(x>=n) x-=n,++count;
			n-=2;
		}
		return count;
	}
};