#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

namespace hashing {
    namespace md5 {
        void* hash(const std::string& message);
        std::string sig2hex(void* signature);
    }
}

int main() {
	int nonce = 0;
    	string sec = "yzbqklnj";
	string ha = "";
	while (true) {
        	void* sig = hashing::md5::hash(sec + to_string(nonce));
        	ha = hashing::md5::sig2hex(sig);
        	if (ha.substr(0, 6) == "000000")
        		break;
        	nonce++;
	}
	cout << nonce << endl;
	return 0;
}
