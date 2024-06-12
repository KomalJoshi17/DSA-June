
// class Solution {
// public:
//     long long maximumSubarraySum(vector<int>& nums, int k) {
//         if (k > nums.size()) return 0;

//         long long current_sum = 0;
//         long long max_sum = 0;
//         unordered_map<int, int> freq;

//         // Initialize the first window
//         for (int i = 0; i < k; ++i) {
//             current_sum += nums[i];
//             freq[nums[i]]++;
//         }

//         // Check if the initial window has all distinct elements
//         if (freq.size() == k) {
//             max_sum = current_sum;
//         }

//         // Slide the window across the array
//         for (int i = k; i < nums.size(); ++i) {
//             // Remove the element that goes out of the window
//             int left_elem = nums[i - k];
//             current_sum -= left_elem;
//             if (--freq[left_elem] == 0) {
//                 freq.erase(left_elem);
//             }

//             // Add the new element coming into the window
//             int right_elem = nums[i];
//             current_sum += right_elem;
//             freq[right_elem]++;

//             // Check if the current window has all distinct elements
//             if (freq.size() == k) {
//                 max_sum = max(max_sum, current_sum);
//             }
//         }

//         return max_sum;
//     }
// };


#include <bits/stdc++.h>
using namespace std;

long maximumSumSubarray(int K, vector<int> &arr , int N){
	// code here
	long cur_sum = 0;

	// find the sum for 1st window of size k
	for(int i = 0; i < K; ++i)
		cur_sum += arr[i];

	long max_sum = cur_sum;

	// keep updating cur_sum as we
	// slide through other windows
	// and track max_sum
	for(int st = 1, en = K; en < N; st++, en++) {
		cur_sum -= arr[st - 1];
		cur_sum += arr[en];

		max_sum = max(max_sum, cur_sum);
	}

	return max_sum;
}

int main() {
	// your code goes here
	int N = 6, K = 3;
	vector<int> arr = {5, 1, 2, 6, 3, 1};
	cout << maximumSumSubarray(K, arr, N);
	return 0;
}
