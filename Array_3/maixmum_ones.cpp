class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeroCount = 0, start = 0, ans = 0;

        for(int end = 0; end < nums.size(); ++end) {
            if(nums[end] == 0)
                zeroCount++;
            while(zeroCount > k){
                if(nums[start] == 0)
                    zeroCount--;
                start++;
            }
            ans = max(ans, end - start + 1);
        }
        return ans;
    }
};