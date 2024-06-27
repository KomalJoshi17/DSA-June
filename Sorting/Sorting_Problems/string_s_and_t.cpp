#include <bits/stdc++.h>
using namespace std;

bool isSorted(string &s) {
    for(int i = 0; i + 1 < s.length(); ++i)
        if(s[i] > s[i+1])
            return false;
    return true;
}
int main() {
    string s, t; cin >> s >> t;
    
    if(t.length() == 1 and s.find(t) != s.npos) // if t is found
        cout << "Impossible\n";

    else if(isSorted(t)) {
        sort(s.begin(), s.end());
        reverse(s.begin(), s.end());

        cout << s << '\n';
    }

    else {
        sort(s.begin(), s.end());
        cout << s << '\n';
    }
	return 0;
}
