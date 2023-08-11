class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        std::set<int> set;
        return std::remove_if(nums.begin(), nums.end(), [&set](auto &i) {
            if (set.count(i))
                return true;
            
            set.emplace(i);
            return false;
        }) - nums.begin();
    }
};