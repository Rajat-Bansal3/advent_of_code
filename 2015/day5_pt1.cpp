#include <bits/stdc++.h>

using namespace std;

int main(){
	
	ifstream f("x.txt");
	if(!f.is_open()){
		exit(1);
	}
	string s;
	int nice = 0;
	int vowel = 0;
	int flag = 0;
	int glag = 0;
	int count = 0;
	while(getline( f , s )){
		vowel = 0;
		flag = 0;
		glag = 0;
	for(int i = 0 ; i < s.size() ; i++){
		if(s[i] == 'a' || s[i] == 'e' ||  s[i] == 'i' || s[i] == 'o' || s[i] == 'u' )
			vowel++;
		if(i > 0 && s[i] == s[i-1]) flag = 1;
		if(i > 0 && (s.substr(i-1 , 2) == "ab" || s.substr(i-1 , 2) == "cd" || s.substr(i-1 , 2) == "pq" || s.substr(i-1 , 2) == "xy")) {glag = 1;break;}
	}
		if(flag && vowel >= 3 && !glag) nice++;
		count++;
	}
	cout << nice << endl;

	return 0;
}
