class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 1) return 1;

        int j = 1;
        for (int i=1, size=nums.size(); i < size; ++i) {
            if (nums[i] != nums[i-1])
                nums[j++] = nums[i];
        }

        return j;
    }
};