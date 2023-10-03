class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<array<int, 3>> arr(n);
        for(int i=0; i<n; i++){
            arr[i] = {endTime[i], startTime[i], profit[i]};
        }
        
        sort(arr.begin(), arr.end());
        
        map<int, int> dp{{0, 0}};
        for(auto& cur : arr){
            int cur_profit = prev(dp.upper_bound(cur[1]))->second + cur[2];
            if(cur_profit > dp.rbegin()->second)
                dp[cur[0]] = cur_profit;
        }
        
        return dp.rbegin()->second;
    }
};