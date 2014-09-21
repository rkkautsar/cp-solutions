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

string row="ABCDE",column="12345";

int main(int argc, char **argv){
	ios_base::sync_with_stdio(0);
	cin.tie(0);	

	bool ketemu=false,ada;
	vii jawaban;
	int x,y,ans;
	ada=false;
	//first scan
	for(int i=0;i<5 && !ada;++i){
		cout<<"gali "<<row[i]<<column[2]<<'\n'<<flush;
		cin>>ans;
		if(ans){
			ada=true;
			x=i;
			y=2;
			jawaban.push_back(mp(x,y));
			break;
		}
		if(i==2) continue;
		cout<<"gali "<<row[2]<<column[i]<<'\n'<<flush;
		cin>>ans;
		if(ans){
			ada=true;
			x=2;
			y=i;
			jawaban.push_back(mp(x,y));
			break;
		}
	}

	bool isvertical=false;
	//cek vertikal/horizontal
	if(x<4){
		cout<<"gali "<<row[x+1]<<column[y]<<'\n'<<flush;
		cin>>ans;
		if(ans){
			jawaban.push_back(mp(x+1,y));
			isvertical=true;
		}
		else{
			if(x>0){
				cout<<"gali "<<row[x-1]<<column[y]<<'\n'<<flush;
				cin>>ans;
				if(ans){
					isvertical=true;
					jawaban.push_back(mp(x-1,y));
				}
			}
		}
	}

	if(isvertical){
		if(jawaban[1].first==x-1){ //ke atas
			cout<<"ketemu "<<row[x]<<column[y]<<' '
						   <<row[x-1]<<column[y]<<' '
						   <<row[x-2]<<column[y]<<'\n'<<flush;
			return 0;
		}
		else{
			if(x>0){
				cout<<"gali "<<row[x-1]<<column[y]<<'\n'<<flush;
				cin>>ans;
				if(ans){
					isvertical=true;
					jawaban.push_back(mp(x-1,y));
				}
			}
			if(jawaban.size()==3){
				cout<<"ketemu ";
				for(int i=0;i<3;++i) cout<<row[jawaban[i].first]<<column[jawaban[i].second]<<(i==2?'\n':' ');
				cout<<flush;
				return 0;
			} else { //ke bawah
				cout<<"ketemu "<<row[x]<<column[y]<<' '
						   <<row[x+1]<<column[y]<<' '
						   <<row[x+2]<<column[y]<<'\n'<<flush;
				return 0;
			}
		}
	} else {
		//horizontal
		//cek kanan, kiri
		if(y>0){
			cout<<"gali "<<row[x]<<column[y-1]<<'\n'<<flush;
			cin>>ans;
			if(ans) jawaban.push_back(mp(x,y-1));
		}
		if(y<4){
			cout<<"gali "<<row[x]<<column[y+1]<<'\n'<<flush;
			cin>>ans;
			if(ans) jawaban.push_back(mp(x,y+1));
		}
		if(jawaban.size()==3){
			cout<<"ketemu ";
			for(int i=0;i<3;++i) cout<<row[jawaban[i].first]<<column[jawaban[i].second]<<(i==2?'\n':' ');
			cout<<flush;
			return 0;
		} else if(jawaban[1].second==y-1){ //ke kiri
			cout<<"ketemu "<<row[x]<<column[y]<<' '
						   <<row[x]<<column[y-1]<<' '
						   <<row[x]<<column[y-2]<<'\n'<<flush;
			return 0;
		} else {
			cout<<"ketemu "<<row[x]<<column[y]<<' '
						   <<row[x]<<column[y+1]<<' '
						   <<row[x]<<column[y+2]<<'\n'<<flush;
			return 0;
		}
	}


	
	

	return 0;
}
