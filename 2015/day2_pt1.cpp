#include <bits/stdc++.h>

using namespace std;

int main(){
	ifstream f("x.txt");
	if(!f.is_open()){
		exit(1);
	}
	string s;
	int sum = 0;
	while(getline(f , s, '\n')){
		cout << sum << " <---" << endl; 
		stringstream ss(s);
		int l, b, h;
        	char x1, x2;
		if(ss >> l >> x1 >> b >> x2 >> h && x1 == 'x' && x2 == 'x'){
			vector<int> x = {l , b , h};
			sort(x.begin() , x.end());
			int slack = x[0] + x[0] + x[1] + x[1] ;
			int ribbon = x[0] * x[1] * x[2];
			sum += slack + ribbon;
		}
	}
	cout << sum << endl;
	return 0;
}
