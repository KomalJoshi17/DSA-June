//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> ans;
    void findPathHelper(int i, int j, vector<vector<int>> &m, int n, string &dir) {
        if(i == -1 || j == -1 || i == n || j == n || m[i][j] == 0) return;
        if(i == n-1 && j == n-1) {
            ans.push_back(dir);
            return;
        }
        m[i][j] = 0;
        // go up
        dir.push_back('U');
        findPathHelper(i-1,j,m,n,dir);
        dir.pop_back();
         // go right
        dir.push_back('R');
        findPathHelper(i,j+1,m,n,dir);
        dir.pop_back();
        // go down
        dir.push_back('D');
        findPathHelper(i+1,j,m,n,dir);
        dir.pop_back();
        // go left
        dir.push_back('L');
        findPathHelper(i,j-1,m,n,dir);
        dir.pop_back();
        
        m[i][j] = 1;
        return;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        if(m[0][0] == 0) return {};
        string dir;
        findPathHelper(0,0,m,n,dir);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends