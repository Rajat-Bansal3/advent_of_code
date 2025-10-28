#include <bits/stdc++.h>

using namespace std;

int main(){
	ifstream f("x.txt");
	if(!f.is_open()){
		exit(1);
	}
	string s;
	int count = 0;
	int flag_1 = 0;
	int flag_2 = 0;
	while(getline(f , s)){
		flag_1=0;flag_2=0;
		for(int i = 1 ; i < s.size(); i++){
			if( ( i < s.size() - 1 ) && ( s[i] != s[i - 1] ) && ( s[i - 1] == s[i+1] ) ){
				flag_1= 1;
			}
			string sub = s.substr(i-1 , 2);
			for(int j = i + 2 ; j < s.size() ; j++){
				if( s.substr(j - 1 , 2) == sub ) {
					flag_2 = 1;
					break;
				}
			}	
		}
		if(flag_1 && flag_2) count++; 
	}
	cout << count << endl;
	return 0;
}
