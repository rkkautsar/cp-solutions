#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
 
double x, y, s, maks, mins, sds, n;
double a[10005];
 
int main() {
    scanf("%lf", &n);
    for (int i = 0; i < n; i++)
    scanf("%lf", &a[i]);
    maks = a[0];
    mins = a[0];
    s = a[0];
    for (int i = 1; i < n; i++) {
    maks = max(maks, a[i]);
    mins = min(mins, a[i]);
    s += a[i];
    }
    s = s / n;
    for (int i = 0; i < n; i++) {
    x = (a[i]-s) * (a[i]-s);
    y += x;
    }
    if (n == 1) sds = 0;
    else sds = sqrt(y / (n-1));
    printf("%.2lf %.2lf %.2lf %.2lf\n", mins, maks, s, sds);
}
