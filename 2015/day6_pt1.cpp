#include <bits/stdc++.h>

using namespace std;

int main(){
	vector<vector<int>> grid;
	grid.reserve(1000);
	for (int i = 0; i < 1000; i++)
    		grid.emplace_back(1000, 0);

	ifstream f ("x.txt");
	if(!f.is_open()){
		exit(1);
	}
	string s;
	int count = 0;
	while(getline(f , s)){
		if(s.empty()) continue;
		if(!s.empty() && s.back() == '\r') s.pop_back();
		int x1,y1 , x2,y2;
		x1=y1=x2=y2=0;
		vector<string> parts;
		string word;
		stringstream ss(s);
		string op;
		while(ss >> word) parts.push_back(word);
		if(parts[0] == "toggle") op = parts[0];
		else op = parts[1];

		string coord1 = (op == "toggle") ? parts[1] : parts[2];
		string coord2 = parts.back();
		replace(coord1.begin(), coord1.end(), ',', ' ');
        	replace(coord2.begin(), coord2.end(), ',', ' ');

        	stringstream c1(coord1), c2(coord2);
        	c1 >> x1 >> y1;
        	c2 >> x2 >> y2;
		for(int i = x1 ; i < x2+1 ; i++){
			for(int j = y1 ; j < y2+1 ; j++){
				if(op == "toggle") grid[i][j] += 2;
				else if(op == "on") grid[i][j] += 1;
				else if(op == "off") grid[i][j] = max(0,grid[i][j] - 1);
			}
		}
	}
	for (auto &row : grid)
    		for (int cell : row)
        		count += cell;
	cout << count << endl;
	return 0;
}
