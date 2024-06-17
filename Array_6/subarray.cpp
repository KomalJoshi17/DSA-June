class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(),sorted_nums.end());
        int start=-1;
        int end=-2;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=sorted_nums[i]){
                if(start==-1) start=i;
                else end=i;
            }
        }
        return end-start+1;
    }
};