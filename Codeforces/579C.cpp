#include <bits/stdc++.h>
using namespace std;
 
// typedef
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<long double,long double> dd;
typedef vector<int> vi;
typedef vector<long double> vd;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<bool> vb;
 
#define abs(_x) ((_x)<0?-(_x):(_x))
#define REP(_a,_b) for(int (_a)=0;(_a)<(_b);++(_a))
#define mp(_x,_y) make_pair((_x),(_y))
#define PI 3.1415926535897932385
#define EPS 1e-9
#define INF 0x00FFFFFF
#define INFLL 0x00FFFFFFFFFFFFFFLL
#define ceildiv(_a,_b) ((_a)%(_b)==0?(_a)/(_b):((_a)/(_b))+1)
#define fi first
#define se second

struct Point{
	long double x,y;
	Point(): x(0), y(0) {}
	Point(long double xx,long double yy): x(xx), y(yy) {}
	bool nol(){
		return fabs(x)<EPS && fabs(y)<EPS;
	}
};

struct Vector{
	long double dx,dy,magnitude;
	Vector(): dx(0), dy(0), magnitude(0){}
	Vector(long double xx,long double yy): dx(xx), dy(yy) {
		magnitude = hypot(dx,dy);
	}
	Vector(Point a,Point b){
		dx = b.x - a.x;
		dy = b.y - a.y;
		magnitude = hypot(dx,dy);
	}
	bool nol(){
		return fabs(dx)<EPS && fabs(dy)<EPS;
	}
	void normalize(){
		dx/=magnitude;
		dy/=magnitude;
		magnitude = 1;
	}
};

Point translate(Point p,const Vector &v){
	p.x+=v.dx;
	p.y+=v.dy;
	return p;
}

long double cross(Vector a,Vector b){
	return a.dx*b.dy-a.dy*b.dx;
}

bool collinear(Vector a,Vector b){
	return fabs(a.dy/a.dx - b.dy/b.dx)<EPS;
}

bool ccw(Vector a,Vector b){
	return cross(a,b)>0;
}

long double magnitude(Vector v){
	return hypot(v.dx,v.dy);
}

long double dist(Point a,Point b){
	return magnitude(Vector(a,b));
}

long double triangleArea(Point a,Point b,Point c){
	return 0.5*fabs(cross(Vector(a,b),Vector(b,c)));
}


int main(int argc, char **argv){
	// ios_base::sync_with_stdio(0);
	// cin.tie(0);

	int a,b,x,y;
	cin>>a>>b;
	if(a<b){
		cout<<-1<<'\n';
		return 0;
	}
	x=a+b;
	y=x/(2*b);
	cout<<fixed<<setprecision(12)<<x/(2.0*y)<<'\n';
	
	return 0;
}
