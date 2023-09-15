class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if(total%2!=0)
            return false;
        total/=2;
        
        int n = nums.size();
        vector<vector<bool>> dp(total+1, vector<bool>(n+1, false));
        for(int i=0; i<=n; i++)
            dp[0][i] = true;
        
        for(int cur=1; cur<=total; cur++){
            for(int i=1; i<=n; i++){
                dp[cur][i] = dp[cur][i-1];
                if(cur - nums[i-1] >=0)
                    dp[cur][i] = dp[cur][i] || dp[cur-nums[i-1]][i-1];
            }
        }
        
        return dp[total][n];
    }
};