class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int total = 0;
        int cur = 0;
        while (cur < prices.size()) {
            int buyDay = cur + 1;
            while (buyDay < prices.size()) {
                // find smallest consecutive
                if (prices[buyDay] > prices[buyDay-1]) {
                    buyDay = buyDay-1;
                    break;
                } 
                ++buyDay;
            }

            if (buyDay >= prices.size()-1) break;

            int sellDay = buyDay + 1;
            while (sellDay < prices.size()) {
                if (prices[sellDay-1] > prices[buyDay] && prices[sellDay] < prices[sellDay-1]) {
                    sellDay = sellDay-1;
                    break;
                }
                ++sellDay;
            }

            if (sellDay >= prices.size())
                sellDay = prices.size()-1;

            total += prices.at(sellDay) - prices.at(buyDay);
            cur = sellDay + 1;

                
        }


        return total;
    }
};