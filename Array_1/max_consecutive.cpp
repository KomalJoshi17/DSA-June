// class Solution {
// public:
//     int findMaxConsecutiveOnes(vector<int>& nums) {
//         int maxCount=0;
//         int count=0;
//         for(int num:nums){
//             if(num==1){
//                 count++;
//                 maxCount=max(maxCount,count);
//             }else{
//                 count=0;
//             }
//         }
//         return maxCount;
//     }
// };


// #include <bits/stdc++.h>
// using namespace std;

// int findMaxConsecutiveOnes(vector<int>& arr) {
// 	// final_ans: stores the maximum consecutive ones.
// 	// cur_count: stores the number of consecutive ones in the current window.
// 	int final_ans = 0, cur_count = 0;
	
// 	for(int num : arr) {
// 		if(num == 1)
// 			cur_count++;
// 		else
// 			cur_count = 0;
// 		final_ans = max(final_ans, cur_count);
// 	}
// 	return final_ans;
// }

// int main()
// {
//     vector<int> arr = {1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1};
//     cout << findMaxConsecutiveOnes(arr) << '\n';
//     return 0;
// }
