#include <bits/stdc++.h>

using namespace std;

int main(){
	set<pair<int, int>> cords = { { 0 , 0 } } ;
	ifstream f ("x.txt");
	if(!f.is_open()){
		exit(1);
	}
	string s;
		int x , y;x=y= 0;
	while(getline(f , s)){
	 for(int i = 0 ; i < s.size() ; i++){
		if(s[i] == '^') cords.insert({x , ++y});
		else if(s[i] == 'v') cords.insert({x , --y});
		else if(s[i] == '>') cords.insert({++x , y}); 
		else if(s[i] == '<') cords.insert({--x , y});
	 }	
	}
	cout << cords.size()<<endl;
	return 0;
}
