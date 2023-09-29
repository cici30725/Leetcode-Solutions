class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX-1);
        dp[0] = 0;
        
        for(int c : coins){
            for(int i=1; i<=amount; i++){
                if(i-c>=0)
                    dp[i] = min(dp[i], dp[i-c]+1);
            }
        }
        
        return dp[amount] == INT_MAX-1 ? -1 : dp[amount];
    }
};