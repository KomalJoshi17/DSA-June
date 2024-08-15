// class MinHeap {
//     private:
//     vector<int> heap;
//     public:
//     MinHeap() {
//         heap.push_back(-1);
//     }
//     bool isEmpty() {
//         if(heap.size() == 1) return true;
//         return false;
//     }
//     int top() {
//         if(isEmpty()) return -1;
//         return heap[1];
//     }
//     int pop() {
//         if(isEmpty()) return -1;
//         int top_ele = heap[1];
//         swap(heap[1], heap.back());
//         heap.pop_back();
//         int i = 1;
//         int n = heap.size();
//         while(i < n) {
//             if(i*2 >= n) return top_ele;
//             if(i*2+1 >= n) {
//                 int left = heap[i*2];
//                 if(left < heap[i]) {
//                     swap(heap[i], heap[i*2]);
//                 }
//                 return top_ele;
//             }else {
//                 int left = heap[i*2];
//                 int right = heap[i*2 + 1];
//                 if(left <= right && left <= heap[i]) {
//                     swap(heap[i], heap[i*2]);
//                     i = i * 2;
//                 } else if(right <= left && right <= heap[i]) {
//                     swap(heap[i], heap[i*2+1]);
//                     i = i * 2 + 1;
//                 } else {
//                     return top_ele;
//                 }
//             }
            
//         }
//         return top_ele;
//     }

//     void push(int a) {
//         heap.push_back(a);
//         int i = heap.size() - 1;
//         while(i > 1 && heap[i] <= heap[i/2]) {
//             swap(heap[i], heap[i/2]);
//             i = i / 2;
//         }
//     }
// };

// class Solution {
// public:
//     vector<int> numberGame(vector<int>& nums) {
//         MinHeap minheap;
//         vector<int> ans;
//         for(int i = 0; i < nums.size(); i++) {
//             minheap.push(nums[i]);
//         }

//         while(!minheap.isEmpty()) {
//             int a = minheap.pop();
//             int b = minheap.pop();
//             ans.push_back(b);
//             ans.push_back(a);
//         }
//         return ans;

//     }
// };