#include <bits/stdc++.h>
using namespace std;

int main()
{
    int sum = 0;
    ifstream f("x.txt");
    if (!f.is_open())
    {
        cerr << "Error opening the file!";
        return 1;
    }
    string s;
    while (getline(f, s))
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                sum++;
            else if (s[i] == ')')
                sum--;
        
		if(sum == -1) {
			cout << i + 1<< endl;
		}
	} 

    cout << sum;
    return 0;
}

