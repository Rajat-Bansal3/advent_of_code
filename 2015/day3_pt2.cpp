#include <bits/stdc++.h>

using namespace std;

int main(){
	set<pair<int, int>> cords = { { 0 , 0 } } ;
	ifstream f ("x.txt");
	if(!f.is_open()){
		exit(1);
	}
	string s;
	int sx , sy;sx=sy= 0;
	int rx , ry;rx=ry= 0;
	while(getline(f , s)){
	 for(int i = 0 ; i < s.size() ; i++){
		if(i % 2 == 0){
			if(s[i] == '^') cords.insert({sx , ++sy});
			else if(s[i] == 'v') cords.insert({sx , --sy});
			else if(s[i] == '>') cords.insert({++sx , sy}); 
			else if(s[i] == '<') cords.insert({--sx , sy});
		}
		else{
			if(s[i] == '^') cords.insert({rx , ++ry});
			else if(s[i] == 'v') cords.insert({rx , --ry});
			else if(s[i] == '>') cords.insert({++rx , ry}); 
			else if(s[i] == '<') cords.insert({--rx , ry});
		 }
	 }	
	}
	cout << cords.size()<<endl;
	return 0;
}

