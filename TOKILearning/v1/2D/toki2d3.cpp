#include <iostream>
#include <list>
using namespace std;

list<long> l;

int main(){
	cout.sync_with_stdio(false);
	cin	.sync_with_stdio(false);
	
	int n;
	long x;
	cin>>n;
	string s;
	for(int i=0;i<n;i++){
		cin>>s;
		if(s=="push_back"){
			cin>>x;
			l.push_back(x);
		}
		else if(s=="push_front"){
			cin>>x;
			l.push_front(x);
		}
		else if(s=="pop_back") l.pop_back();
		else l.pop_front();
	}
	 list<long>::iterator p = l.begin();  
	 while(p != l.end()) {
		cout << *p << "\n";
		p++;
	 }
	return 0;
}
			
