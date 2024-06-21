// class Solution {
//     int searchHelper(vector<int> &arr, int st, int en, int k) {
//         if(st > en)
//             return -1;
            
//         if(st == en)
//             return arr[st] == k? st : -1;
        
//         int mid = (st + en)/2;    
//         int firstHalf = searchHelper(arr, st, mid, k);
        
//         if(firstHalf != -1)
//             return firstHalf;
            
//         int secondHalf = searchHelper(arr, mid + 1, en, k);
        
//         return secondHalf;
//     }
    
//     public:
//     int search(int n, int k, vector<int> &arr) {
//         int ans = searchHelper(arr, 0, n - 1, k);
//         return ans == -1? ans : ans + 1; // convert 0-based to 1-based.
//     }
// };