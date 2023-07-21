class Solution {
public:
    int dfs(vector<int>& prices, int left, vector<int>& dp){
        if(left>=prices.size())
            return 0;
        
        if(dp[left]!=-1)
            return dp[left];
        
        int cur_min = prices[left];
        int max_prof = 0;
        
        for(int i=left+1; i<prices.size(); i++){
            cur_min = min(prices[i], cur_min);
            max_prof = max(dfs(prices, i+2, dp) + (prices[i]-cur_min), max_prof);
        }
        
        return dp[left] = max_prof;
    }
    int maxProfit(vector<int>& prices) {
        vector<int> dp(prices.size(), -1);
        return dfs(prices, 0, dp);
    }
};