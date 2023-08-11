class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowest = INT_MAX;
        int highestProfit = 0;
        for (auto &price : prices) {
            if (price < lowest)
                lowest = price;
            else if (price - lowest > highestProfit)
                highestProfit = price - lowest;
        }

        return highestProfit;
    }
};