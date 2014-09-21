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

int x_pojkirat,y_pojkirat,x_pojkanba,y_pojkanba,n;
int dx[4]={-1,0,0,1},
	dy[4]={0,-1,1,0};

void flood(vs &v,int x,int y){
	x_pojkirat=min(x_pojkirat,x);
	x_pojkanba=max(x_pojkanba,x);
	y_pojkirat=min(y_pojkirat,y);
	y_pojkanba=max(y_pojkanba,y);
	v[x][y]='*';
	int nx,ny;
	for(int i=0;i<4;++i){
		nx=x+dx[i];
		ny=y+dy[i];
		if(nx>=0 && nx<n && ny>=0 && ny<n && v[nx][ny]=='1') flood(v,nx,ny);
	}
}

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	

	string dummy;
	getline(cin,dummy);
	
	//5x5
	string 	T[]={	"11111",
					"00100",
					"00100",
					"00100",
					"00100"	},
			O[]={	"01110",
					"10001",
					"10001",
					"10001",
					"01110"	},
			K[]={	"10001",
					"10010",
					"11100",
					"10010",
					"10001"	},
			I[]={	"00100",
					"00100",
					"00100",
					"00100",
					"00100"	};

	cin>>n;
	vs gambar(n);
	for(int i=0;i<n;++i) cin>>gambar[i];

	//cari x_pojkirat,y_pojkirat,x_pojkanba,y_pojkanba pake floodfill
	vs draft=gambar;
	bool ketemu=false;
	for(int i=0;i<n && !ketemu;++i)
		for(int j=0;j<n && !ketemu;++j)
			if(draft[i][j]=='1'){
				x_pojkirat=x_pojkanba=i;
				y_pojkirat=y_pojkanba=j;
				flood(draft,i,j);
				ketemu=true;
				break;
			}
	

	int selisih=min(x_pojkanba-x_pojkirat+1,y_pojkanba-y_pojkirat+1);
	int cut=selisih/5;
	int diff,optimal;
	char hurufoptimal;


	// for(int i=x_pojkirat;i<=x_pojkanba;++i){
	// 	for(int j=y_pojkirat;j<=y_pojkanba;++j)cout<<draft[i][j];cout<<'\n';
	// }
	
	// cout<<x_pojkirat<<' '<<y_pojkirat<<'\n';
	// cout<<x_pojkanba<<' '<<y_pojkanba<<'\n';


	//cek T
	diff=0;
	for(int p=0;p<5;++p){
		for(int q=0;q<5;++q){
			for(int i=x_pojkirat+p*cut;i<min(x_pojkirat+(p+1)*cut,x_pojkirat+selisih);++i)
				for(int j=y_pojkirat+q*cut;j<min(y_pojkirat+(q+1)*cut,y_pojkirat+selisih);++j)
					if(gambar[i][j]!=T[p][q])++diff;
		}
	}
	optimal=diff;
	hurufoptimal='T';
	//cout<<"T, diff = "<<diff<<'\n';

	//cek O
	diff=0;
	for(int p=0;p<5;++p){
		for(int q=0;q<5;++q){
			for(int i=x_pojkirat+p*cut;i<min(x_pojkirat+(p+1)*cut,x_pojkirat+selisih);++i)
				for(int j=y_pojkirat+q*cut;j<min(y_pojkirat+(q+1)*cut,y_pojkirat+selisih);++j)
					if(gambar[i][j]!=O[p][q])++diff;
		}
	}
	if(diff<optimal){
		optimal=diff;
		hurufoptimal='O';
	}
	//cout<<"O, diff = "<<diff<<'\n';

	//cek K
	diff=0;
	for(int p=0;p<5;++p){
		for(int q=0;q<5;++q){
			for(int i=x_pojkirat+p*cut;i<min(x_pojkirat+(p+1)*cut,x_pojkirat+selisih);++i)
				for(int j=y_pojkirat+q*cut;j<min(y_pojkirat+(q+1)*cut,y_pojkirat+selisih);++j)
					if(gambar[i][j]!=K[p][q])++diff;
		}
	}
	if(diff<optimal){
		optimal=diff;
		hurufoptimal='K';
	}
	//cout<<"K, diff = "<<diff<<'\n';

	//cek I
	diff=0;
	for(int p=0;p<5;++p){
		for(int q=0;q<5;++q){
			for(int i=x_pojkirat+p*cut;i<min(x_pojkirat+(p+1)*cut,x_pojkirat+selisih);++i)
				for(int j=y_pojkirat+q*cut;j<min(y_pojkirat+(q+1)*cut,y_pojkirat+selisih);++j)
					if(gambar[i][j]!=I[p][q])++diff;
		}
	}
	if(diff<optimal){
		optimal=diff;
		hurufoptimal='I';
	}
	//cout<<"I, diff = "<<diff<<'\n';

	//huft
	cout<<hurufoptimal<<'\n';


	return 0;
}
