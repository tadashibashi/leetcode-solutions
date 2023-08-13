class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2)
    {
        auto ret = vector<vector<int>>{};
        ret.reserve(items1.size() + items2.size());

        sort(items1.begin(), items1.end(), [](auto &a, auto&b) { return a[0] < b[0]; });
        sort(items2.begin(), items2.end(), [](auto &a, auto&b) { return a[0] < b[0]; });

        int i=0, j=0;

        while (i < items1.size() && j < items2.size()) {
            if (items1[i][0] == items2[j][0]) {
                ret.emplace_back(vector<int>{items1[i][0], items1[i][1] + items2[j][1]});
                ++i;
                ++j;
            } else if (items1[i][0] < items2[j][0]) {
                ret.emplace_back(items1[i]);
                ++i;
            } else {
                ret.emplace_back(items2[j]);
                ++j;
            }
        }

        while (i < items1.size())
            ret.emplace_back(items1[i++]);

        while (j < items2.size())
            ret.emplace_back(items2[j++]);
        
        return ret;
    }
};