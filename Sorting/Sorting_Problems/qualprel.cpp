#include <bits/stdc++.h>
using namespace std;

// Link: https://www.codechef.com/SNCKQL19/problems/QUALPREL
// Time : O(NLogN)

int main() {
    int t;
    cin >> t;
    
    for(int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;
        
        int scores[n];
        for(int j=0;j<n;j++){
            cin >> scores[j];
        }
        
        sort(scores, scores + n, greater<int>());
        
        int ans = 0;
        for(int i = 0; i < n; ++i)
            if(scores[i] >= scores[k - 1])
                ans++;
        
        cout << ans << endl;
    }
    return 0;
}