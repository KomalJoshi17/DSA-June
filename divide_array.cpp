class Solution {
public:
    bool divideArray(vector<int>& nums) {
       unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }
        for (auto i : count) {
            if (i.second % 2 != 0) {
                return false;
            }
        }
        return true;
    }
};