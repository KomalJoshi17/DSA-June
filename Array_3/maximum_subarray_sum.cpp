class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int max_sum = nums[0];
        int sum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum > max_sum) {
                max_sum = sum;
            }
            if (sum < 0) {
                sum = 0;
            }
        }
        
        return max_sum;
    }
};