// Link : https://www.spoj.com/problems/NAJPF/

#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

vector<int> find_occurences(const string &str, const string &pat) {
	vector<int> pi = prefix_function(pat);
	
	int i = 0, j = 0, l1 = str.length(), l2 = pat.length();
	vector<int> ans;
	while(i < l1) {
		if(str[i] == pat[j])
			i++, j++;
		else if(j == 0)
			i++;
		else
			j = pi[j-1];
		
		if(j == l2) {
			ans.push_back(i - l2 + 1);
			j = pi[j-1];
		}
	}
	return ans;
}

int main() {
	FIO;
    int t; cin >> t;
    while(t--) {
        string a, b; cin >> a >> b;
        vector<int> ids = find_occurences(a, b);
        if(ids.empty()) {
            cout << "Not Found\n";
        }
        else {
            cout << ids.size() << '\n';
            for(int id : ids)
                cout << id << ' ';
            cout << '\n';
        }
    }
	return 0;
}