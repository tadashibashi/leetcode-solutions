class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // no need to rotate anything size 1 or 0
        if (nums.size() < 2) return;

        // rotations cycle about size
        k = k % nums.size();

        // swap blocks
        std::vector<int> temp;
        temp.reserve(nums.size() - k);

        std::copy(nums.begin(), nums.end()-k, std::back_inserter(temp));

        std::copy(nums.end()-k, nums.end(), nums.begin());
        std::copy(temp.begin(), temp.end(), nums.end()-temp.size());
    }
};