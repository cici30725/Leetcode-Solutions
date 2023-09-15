class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = triangle[0][0];
        for(int lvl=1; lvl<n; lvl++){
            for(int i=lvl; i>=0; i--){
                if(i==0)
                    dp[0] += triangle[lvl][0];
                else
                    dp[i] = min(dp[i], dp[i-1]) + triangle[lvl][i];
            }
        }
        
        return *min_element(dp.begin(), dp.end());
    }
};