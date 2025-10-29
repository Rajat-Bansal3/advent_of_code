#include <bits/stdc++.h>
using namespace std;

unordered_map<string, string> expressions;
unordered_map<string, int> memo;

int getVal(const string &wire){
	if (isdigit(wire[0])) {
		return static_cast<int>(stoi(wire));
	}
	if (memo.count(wire)) return memo[wire];
	if (!expressions.count(wire)) {
        	cerr << "No expression for wire: " << wire << "\n";
        	return 0;
    	}
	string s = expressions[wire];
	stringstream ss(s);
	vector<string> token;
	string tok;
	while (ss >> tok) token.push_back(tok);
		int res = 0;
		if(token.size() == 1){
			res = getVal(token[0]);
		}else if(token.size() == 2 && token[0] == "NOT"){
			res = ~getVal(token[1]);
		}else if (token.size() == 3){
			if (token[1] == "AND"){
				res = getVal(token[0]) & getVal(token[2]);
			}
			else if(token[1] == "OR"){
				res = getVal(token[0]) | getVal(token[2]);
			}
			else if(token[1] == "LSHIFT"){
				res = getVal(token[0]) << getVal(token[2]);
			}
			else if(token[1] == "RSHIFT"){
				res = getVal(token[0]) >> getVal(token[2]);
			}
		}
		memo[wire] = res;
		return res;
}
int main() {
    	ifstream f("x.txt");
    	if (!f.is_open()) {
        	cerr << "Error: could not open x.txt\n";
        	return 1;
    	}

    	string line;

    	while (getline(f, line)) {
        	if (line.empty()) continue;

        	stringstream ss(line);
        	vector<string> tokens;
        	string token;

        	while (ss >> token) { 
            		tokens.push_back(token);
        	}

        	auto arrow_pos = find(tokens.begin(), tokens.end(), "->");
        	if (arrow_pos == tokens.end() || arrow_pos + 1 == tokens.end()) {
            		continue;
        	}

        	string lhs = "";
        	for (auto it = tokens.begin(); it != arrow_pos; ++it) {
            		if (it != tokens.begin()) lhs += " ";
            	lhs += *it;
        	}

        	string rhs = *(arrow_pos + 1);

        	expressions[rhs] = lhs;
	}
	cout << getVal("a");
    	return 0;
}

