class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);cout.tie(0);
        
        for (auto it = nums.begin(); it != nums.end(); ++it) {
            if (*it >= target) {
                return it - nums.begin();
            }
        }

        return nums.size();
    }
};