#include <bits/stdc++.h>
using namespace std;

// Link : https://leetcode.com/problems/palindrome-partitioning-ii/
// Time : O(N^2)

class Solution {
    int dp1[2000][2000];
    int dp2[2000];
    bool isPal(string &s, int i, int j) {
        if(i >= j)
            return true;
        if(i + 1 == j)
            return s[i] == s[j];
        if(dp1[i][j] != -1)
            return dp1[i][j];
        return dp1[i][j] = (s[i] == s[j]) && isPal(s, i+1, j-1);
    }
    int minCutHelp(string &s, int i) {
        if(i >= s.length() - 1) 
            return 0;
        if(dp2[i] != -1)
            return dp2[i];
        
        dp2[i] = INT_MAX;

        if(isPal(s, i, s.length() - 1))
            return dp2[i] = 0;

        for(int k = i; k + 1 < s.length(); ++k) {
            if(!isPal(s, i, k))
                continue;
            dp2[i] = min(dp2[i], 1 + minCutHelp(s, k+1));
        }
        return dp2[i];
    }
public:
    int minCut(string s) {
        memset(dp1, -1, sizeof(dp1));
        memset(dp2, -1, sizeof(dp2));
        return minCutHelp(s, 0);
    }
};

int main() {
	// your code goes here
	return 0;
}