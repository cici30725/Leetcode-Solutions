class Solution {
public:
    int dfs(vector<int>& prices, int idx, int state, vector<vector<int>>& dp){
        if(idx>=prices.size())
            return 0;
        if(dp[idx][state]!=-1)
            return dp[idx][state];
        
        if(state == 0){
            // buy
            int buy_profit = -prices[idx] + dfs(prices, idx+1, 1, dp);
            int cool_profit = dfs(prices, idx+1, 0, dp);
            return dp[idx][state] = max(buy_profit, cool_profit);
        }
        else{
            int sell_profit = prices[idx] + dfs(prices, idx+2, 0, dp);
            int cool_profit = dfs(prices, idx+1, 1, dp);
            return dp[idx][state] = max(sell_profit, cool_profit);
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return dfs(prices, 0, 0, dp);
    }
};