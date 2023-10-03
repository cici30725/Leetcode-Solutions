class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<pair<int, int>> arr(n);
        for(int i=0; i<n; i++)
            arr[i] = {i, endTime[i]};
        
        sort(arr.begin(), arr.end(), [](const auto& lhs, const auto& rhs){
            return lhs.second < rhs.second;
        });
        
        vector<int> dp(n);
        dp[0] = profit[arr[0].first];
        for(int i=1; i<n; i++){
            int curIdx = arr[i].first;
            dp[i] = dp[i-1];
            pair<int, int> curStartTime = {0, startTime[curIdx]};
            auto it = upper_bound(arr.begin(), arr.begin()+i, curStartTime, [](const pair<int, int>& lhs, const pair<int, int>& rhs){
                return lhs.second < rhs.second;
            });
            if(it!=arr.begin()){
                it--;
                int idx = it-arr.begin();
                dp[i] = max(dp[i], profit[curIdx] + dp[idx]);
            }
            else{
                dp[i] = max(dp[i], profit[curIdx]);
            }
        }
        
        return dp[n-1];
    }
};