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
		int mem_string = 0;
		for(int i = 1 ; i < s.size() - 1; i++){
			if (s[i] == '\\') {
				if ((i + 3 < s.size()) && (s[i + 1] == 'x')) {
            				i += 3;
        			} else if (i + 1 < s.size()) {
            				i++;
        			}
				
    			}
			if (s[i] == ' ') continue;
			mem_string++;
		}
		sum += size_string - mem_string;
	}
	cout << sum << endl;
	return 0;

}
