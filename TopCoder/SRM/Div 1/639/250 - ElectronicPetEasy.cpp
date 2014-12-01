​​#include <bits/stdc++.h>
using namespace std;

class ElectronicPetEasy{
private:
	set<int> udah;
public:
	string isDifficult(int st1,int p1,int t1,int st2,int p2,int t2){
		udah.clear();
		for(int i=0;i<t1;++i)udah.insert(st1+i*p1);
		for(int i=0;i<t2;++i)
			if(udah.find(st2+i*p2)!=udah.end()) return "Difficult";
		return "Easy"; 
	}
};