class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        int minPrice = INT_MIN;
        for (int i = 0; i < prices.size(); i++) {
            if (i != 0) {
                if (prices[i] < prices[i - 1]) {
                    result += prices[i - 1] - minPrice;
                    minPrice = prices[i];
                } else if (i == prices.size() - 1 && minPrice < prices[i]) {
                    result += prices[i] - minPrice;
                }
            } else {
                minPrice = prices[i];
            }
        }
        
        return result;
    }
};