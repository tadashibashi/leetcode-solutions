class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums[0] < nums[nums.size()-1]) return nums[0];

        int start = 0;
        int end = nums.size()-1;

        while (end - start > 1) {
            int mid = (start + end) / 2;
            if (nums[mid] > nums[start]) {
                start = mid;
            } else {
                end = mid;
            }
        }

        return std::min(nums[start], nums[end]);
    }
};