// class NumArray {
// public:
//     int *prefix_sum;
//     NumArray(vector<int>& nums) {
//         prefix_sum=new int[nums.size()];
//         prefix_sum[0]=nums[0];
//         for(int i=1;i<nums.size();i++){
//             prefix_sum[i]=nums[i]+prefix_sum[i-1];
//         }
//     }
//     int sumRange(int left, int right) {
//         if(left==0)
//             return prefix_sum[right];
//         return prefix_sum[right]-prefix_sum[left-1];
//     }
// };