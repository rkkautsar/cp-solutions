#include <bits/stdc++.h>
using namespace std;
 
// typedef
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<double,double> dd;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<bool> vb;
 
//defines
#define abs(_x) ((_x)<0?-(_x):(_x))
#define REP(_x) for(int __x=0;__x<_x;++__x)
#define mp(_x,_y) make_pair((_x),(_y))
#define PI acos(-1)
#define EPS 1e-9
#define INF 0x0FFFFFFF
#define INFLL 0x0FFFFFFFFFFFFFFFLL
#define ceildiv(_a,_b) ((_a)%(_b)==0?(_a)/(_b):((_a)/(_b))+1)
#define fi first
#define se second

struct point{ 
    double x,y; 
    point(){}
    point(double a,double b):x(a),y(b){}
};
struct vec{ 
    double x,y; 
    vec(){}
    vec(double dx,double dy):x(dx),y(dy){}
    vec(point a,point b):x(b.x-a.x),y(b.y-a.y){}
};
struct line{
	point a,b;
	line(){}
	line(point x,point y):a(x),b(y) {}
};
point translate(point p,vec v){
    return point(p.x+v.x,p.y+v.y);
}
vec scale(vec v,double s){
    return vec(v.x*s,v.y*s);
}
double dist(point a,point b){
    return hypot(fabs(a.x-b.x),fabs(a.y-b.y));
}
double cross(vec a,vec b){
    return (a.x*b.y)-(a.y*b.x);
}
double cross(point a,point b,point c){
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
bool ccw(point a,point b,point c){
    return cross(a,b,c)< -EPS;
}
bool collinear(point a,point b,point c){
    return fabs(cross(a,b,c))<EPS;
}
bool parallel(point a,point b,point c,point d){
    return fabs((fabs(a.y-b.y)/fabs(a.x-b.x))-(fabs(c.y-d.y)/fabs(c.x-d.x)))<EPS;
}
double dot(vec a,vec b){
    return a.x*b.x+a.y*b.y;
}
double norm_sq(vec a){
    return a.x*a.x+a.y*a.y;
}
bool is_intersect(point a,point b,point c,point d){
    return (ccw(a,b,c)!=ccw(a,b,d)) && (ccw(c,d,a)!=ccw(c,d,b));
}
bool is_intersect(line a,line b){
	return is_intersect(a.a,a.b,b.a,b.b);
}
bool in_segment(point p,point a,point b){
    return fabs(dist(a,p)+dist(p,b)-dist(a,b))<EPS;
}
double dist_point_line(point p,point a,point b,point &intersection){
    vec ap(a,p), ab(a,b);
    double u=dot(ap,ab)/norm_sq(ab);
    intersection=translate(a,scale(ab,u));
    return dist(p,intersection);
}
point intersection(point a,point b,point c,point d){
    point intersect;
    double pembagi=(a.x-b.x)*(c.y-d.y)-(a.y-b.y)*(c.x-d.x);
    intersect.x=(((a.x*b.y)-(a.y*b.x))*(c.x-d.x)-
                 ((c.x*d.y)-(c.y*d.x))*(a.x-b.x))/pembagi;
    intersect.y=(((a.x*b.y)-(a.y*b.x))*(c.y-d.y)-
                 ((c.x*d.y)-(c.y*d.x))*(a.y-b.y))/pembagi;
    return intersect;
}
point intersection(line a,line b){
	return intersection(a.a,a.b,b.a,b.b);
}

double length(const vector<point> &v){
	int n=v.size();
	double len=0;
	for(int i=0;i<n-1;++i)
		len+=dist(v[i],v[i+1]);
	return len;
}

point travel(const vector<point> &v,double target){
	int i,n=v.size();
	double tmp=0;
	
	//find the segment i where to point lies
	for(i=0;i<n-1;++i){
		if(tmp+dist(v[i],v[i+1])-EPS>target)break;
		tmp+=dist(v[i],v[i+1]);
	}

	double ratio=(target-tmp)/dist(v[i],v[i+1]);
	return translate(v[i],scale(vec(v[i],v[i+1]),ratio));

}

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	int t,n,k;
	vector<point> v;
	point now;
	double len,every;
	cin>>t;
	for(int road=1;road<=t;++road){
		cout<<"Road #"<<road<<":\n";
		cin>>n>>k;
		v.resize(n);
		for(int i=0;i<n;++i)
			cin>>v[i].x>>v[i].y;
		//get length of the road
		len=length(v);
		//we must plant trees every len/(k-1), including first and last coord
		every=len/(k-1);

		for(int i=0;i<k;++i){
			now=travel(v,i*every);
			cout<<fixed<<setprecision(2)<<now.x<<' '<<now.y<<'\n';
		}

		cout<<'\n';

	}

	return 0;
}
