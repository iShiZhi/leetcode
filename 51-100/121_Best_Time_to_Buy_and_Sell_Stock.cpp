class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        int minPrice = INT_MIN;
        
        for (int i = 0; i < prices.size(); i++) {
            if (i != 0 && minPrice < prices[i] && prices[i] - minPrice > result) {
                result = prices[i] - minPrice;
            }
            
            if (minPrice == INT_MIN || minPrice > prices[i]) {
                minPrice = prices[i];
            }
        }
        
        return result;
    }
};