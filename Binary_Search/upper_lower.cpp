#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int ubUtil(vector<int>& nums, int l, int r, int target) {
        int ans = nums.size();
        while (l <= r) {
            int m = (l + r) / 2;

            if (nums[m] > target) {
                ans = m; // save m in answer.
                r = m - 1; // but still keep searching in [l, m - 1];
            } else { // go to [m + 1, r];
                l = m + 1;
            }
        }
        return ans;
    }

    int lbUtil(vector<int>& nums, int l, int r, int target) {
        int ans = nums.size();
        while (l <= r) {
            int m = (l + r) / 2;

            if (nums[m] >= target) { // This 'if' is the only difference between ub & lb
                ans = m; // save m in answer.
                r = m - 1; // but still keep searching in [l, m - 1];
            } else { // go to [m + 1, r];
                l = m + 1;
            }
        }
        return ans;
    }

    int upperBound(vector<int>& nums, int target) {
        return ubUtil(nums, 0, nums.size() - 1, target);
    }

    int lowerBound(vector<int>& nums, int target) {
        return lbUtil(nums, 0, nums.size() - 1, target);
    }
};

int main() {
    int n, target;
    cin >> n >> target;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    Solution sol;
    cout << "LB: " << sol.lowerBound(arr, target) << endl;
    cout << "UB: " << sol.upperBound(arr, target) << endl;

    return 0;
}
