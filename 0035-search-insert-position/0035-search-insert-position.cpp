class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty()) return 0;

        int start = 0;
        int end = nums.size()-1;

        while (start < end) {
            int i = (start + end) / 2;
            if (nums[i] == target) return i;
            
            if (target < nums[i]) {
                end = std::max(i - 1, start); 
            } else {
                start = std::min(i + 1, end);
            }
        }

        return target <= nums[start] ? start : start + 1;
    }
};