class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n, 0);
        dp[0] = min(costs[0], min(costs[1], costs[2]));
        for(int i=1; i<n; i++){
            dp[i] = costs[0] + dp[i-1];
            int seven = days[i] - 7 + 1;
            int thirty = days[i] - 30 + 1;
            auto it = lower_bound(days.begin(), days.begin()+i, seven);
            if(it!=days.begin()){
                int idx = it - 1 - days.begin();
                dp[i] = min(dp[i], costs[1] + dp[idx]);
            }
            else{
                dp[i] = min(dp[i], costs[1]);
            }
            
            auto it2 = lower_bound(days.begin(), days.begin()+i, thirty);
            if(it2!=days.begin()){
                int idx = it2 - 1 - days.begin();
                dp[i] = min(dp[i], costs[2] + dp[idx]);
            }
            else{
                dp[i] = min(dp[i], costs[2]);
            }
        }
        
        return dp[n-1];
    }
};