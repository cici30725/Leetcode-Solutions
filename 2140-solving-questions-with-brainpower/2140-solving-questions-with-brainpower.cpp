class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        using ll = long long;
        int n = questions.size();
        vector<ll> dp(n, 0);
        
        dp[n-1] = questions[n-1][0];
        for(int i=n-2; i>=0; i--){
            int point = questions[i][0];
            int jump = questions[i][1];
            dp[i] = max(dp[i+1], (i+jump+1<n ? point + dp[i+jump+1] : static_cast<ll>(point)));
        }
        return dp[0];
    }
};