#include <bits/stdc++.h>
using namespace std;

// Time : O(N)

int main() {
    int n, k; cin >> n >> k;
    
    vector<int> d(n);
    for(int i = 0; i < n; ++i)
        cin >> d[i];
    
    int curId = 0, minJumps = 0;

    while(curId < n) {
        int nextId = curId, curDist = 0;

        while(nextId + 1 <= n && curDist + d[nextId] <= k)
            curDist += d[nextId], nextId++;

        if(nextId == curId) {
            cout << -1 << '\n';
            return 0;
        }

        curId = nextId;
        minJumps++;
    }

    cout << minJumps << '\n';
    
	return 0;
}
