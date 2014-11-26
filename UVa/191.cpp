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
typedef vector<vi> vvi;
typedef vector<bool> vb;
 
//defines
#define abs(_x) ((_x)<0?-(_x):(_x))
#define REP(_x) for(int __x=0;__x<_x;++__x)
#define mp(_x,_y) make_pair((_x),(_y))
#define PI 3.1415926535897932385
#define EPS 1e-9
#define INF 0x7FFFFFFF
#define INFLL 0x7FFFFFFFFFFFFFFFLL
#define ceildiv(_a,_b) ((_a)%(_b)==0?(_a)/(_b):((_a)/(_b))+1)

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
    return (cross(a,b,c)< -EPS) || (fabs(cross(a,b,c))<EPS);
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

bool in_polygon(point x,vector<point> p){
	int n=p.size();
	for(int i=0;i<n-1;++i){
		if(!ccw(p[i],p[i+1],x)) return false;
	}
	return true;
}

bool overlap(line p, line q){
	return collinear(p.a,p.b,q.a) && collinear(p.a,p.b,q.b) ;
}

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	int tc;
	cin>>tc;
	int p,q,r,s,left,top,right,bottom;
	point a,b,top_left,top_right,bottom_left,bottom_right;
	vector<point> sq;
	bool flag;
	line x,square[4];

	while(tc--){
		cin>>a.x>>a.y>>b.x>>b.y;
		cin>>p>>q>>r>>s;
		left=min(p,r);
		right=max(p,r);
		top=max(q,s);
		bottom=min(q,s);
		top_left=point(left,top);
		top_right=point(right,top);
		bottom_left=point(left,bottom);
		bottom_right=point(right,bottom);

		sq.clear();
		sq.push_back(top_left);
		sq.push_back(top_right);
		sq.push_back(bottom_right);
		sq.push_back(bottom_left);
		sq.push_back(top_left);

		x=line(a,b);
		square[0]=line(top_left,top_right);
		square[1]=line(top_right,bottom_right);
		square[2]=line(bottom_right,bottom_left);
		square[3]=line(bottom_left,top_left);

		flag=true;
		for(int i=0;i<4 && flag;++i){
			if(	is_intersect(x,square[i]) || 
				in_segment(a,square[i].a,square[i].b) || 
				in_segment(b,square[i].a,square[i].b) || 
				in_segment(square[i].a,a,b) ||
				in_segment(square[i].b,a,b) ||
				in_polygon(a,sq) || 
				in_polygon(b,sq)
				){
				cout<<"T\n";
				flag=false;
			}
		}

		if(flag) cout<<"F\n";

	}

	return 0;
}
