class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(3, vector<int>(n, 0));
        
        for(int k=1; k<=2; k++){
            dp[k][0] = 0;
            int minNum = prices[0];
            for(int i=1; i<n; i++){
                dp[k][i] = max(dp[k][i-1], prices[i]-minNum);
                minNum = min(minNum, prices[i]-dp[k-1][i-1]);
            }
        }
        
        return dp[2][n-1];
    }
};