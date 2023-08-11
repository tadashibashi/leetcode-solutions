class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 3) return nums.size();

        int k = 0, size=nums.size();
        for (int i = 0, size=nums.size(); i < size; ++i) {
            if (i < size - 2) {
                if (nums[i] != nums[i+1] || nums[i] != nums[i+2])
                    nums[k++] = nums[i];
            } else {
                nums[k++] = nums[i];
            }

        }
        
        return k;
    }
};