class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        
        vector<int> firstTrade(prices.size(), 0);
        vector<int> secondTrade(prices.size(), 0);
        
        int minPrice = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (minPrice > prices[i]) minPrice = prices[i];
            if (prices[i] - minPrice > firstTrade[i - 1]) {
                firstTrade[i] = prices[i] - minPrice;
            } else {
                firstTrade[i] = firstTrade[i - 1];
            }
        }
        
        int maxPrice = prices.back();
        for (int i = prices.size() - 2; i >= 0; i--) {
            if (maxPrice < prices[i]) maxPrice = prices[i];
            if (maxPrice - prices[i] > secondTrade[i + 1]) {
                secondTrade[i] = maxPrice - prices[i];
            } else {
                secondTrade[i] = secondTrade[i + 1];
            }
        }
        
        int result = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (firstTrade[i] + secondTrade[i] > result) {
                result = firstTrade[i] + secondTrade[i];
            }
        }
        
        return result;
    }
};