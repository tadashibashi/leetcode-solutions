#include <algorithm>

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // STL solution
        return std::remove_if(nums.begin(), nums.end(), 
            [val](auto i) { return i == val; }) - nums.begin();
    }
};