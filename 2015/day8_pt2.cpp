#include <bits/stdc++.h>

using namespace std;

int main(){

	ifstream f("x.txt");
	if(!f.is_open()){
		cout << "x";
		exit(1);
	}
	int sum = 0;
	string s;
	while(getline(f , s)){
		if(s.empty()){continue;}
		int size_string = s.size();
		int encode_len = 2;
		for(int i = 0; i < s.size(); i++){
			if (s[i] == '\\' || s[i] == '"') encode_len++;
			encode_len++;
		}
		sum += encode_len - size_string;
	}
	cout << sum << endl;
	return 0;
}
