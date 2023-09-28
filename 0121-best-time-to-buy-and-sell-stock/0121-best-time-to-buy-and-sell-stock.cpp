class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int n = prices.size();
        int res = 0;
        for(int i=1; i<n; i++){
            res = max(res, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        return res;
    }
};