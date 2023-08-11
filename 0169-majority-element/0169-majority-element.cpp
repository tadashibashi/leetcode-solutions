class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, candidate = 0;
        for (const int &n : nums) {
            if (!count) {
                candidate = n;
                count = 1;
            } else {
                if (candidate == n)
                    ++count;
                else
                    --count;
            }
        }

        return count > 0 ? candidate : nums[nums.size()-1];
    }
};