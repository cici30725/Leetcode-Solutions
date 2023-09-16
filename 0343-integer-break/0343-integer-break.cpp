class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        dp[2] = 1;
        
        for(int i=3; i<=n; i++){
            for(int j=1; j<=i-1; j++){
                dp[i] = max(dp[i], max(dp[i-j] * j, (i-j)*j));
            }
            // cout<<i<<" "<<dp[i]<<endl;
        }
        return dp[n];
    }
};