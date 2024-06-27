#include <bits/stdc++.h>
using namespace std;

// Link : https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/ 
// Time : O(N)

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n), suf(n);

        // find pref
        for(int i = 0; i < n; ++i)
            pref[i] = (i == 0)? nums[i] : pref[i-1] + nums[i];

        // find suf
        for(int i = n - 1; i >= 0; --i)
            suf[i] = (i == n - 1)? nums[i] : suf[i+1] + nums[i];

        vector<int> ans(n);
        for(int i = 0; i < n; ++i) {
            int prefSum = (i == 0)? 0 : pref[i - 1];
            int sufSum = (i == n-1)? 0 : suf[i + 1];

            int leftSum = i*nums[i] - prefSum;
            int rightSum = sufSum - (n-1-i)*nums[i];

            ans[i] = leftSum + rightSum;
        }

        return ans;
    }
};

int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    Solution sol;
    vector<int> ans = sol.getSumAbsoluteDifferences(arr);
    for(int num : ans)
        cout << num << ' ';
	return 0;
}