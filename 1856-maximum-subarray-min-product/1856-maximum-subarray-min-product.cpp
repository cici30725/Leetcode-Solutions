class Solution {
public:
    using ll = long long;
    
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        vector<ll> cum(n);
        cum[0] = nums[0];
        for(int i=1; i<n; i++){
            cum[i] = cum[i-1]+nums[i];
        }
        
        vector<ll> left_dp(n, 0), right_dp(n, 0);
        stack<pair<int, int>> s1, s2;
        for(int i=0; i<nums.size(); i++){
            int idx = -1;
            while(!s1.empty() && s1.top().first >= nums[i]){
                s1.pop();
            }
            
            if(!s1.empty())
                idx = s1.top().second;
            
            left_dp[i] = idx;
            s1.push({nums[i], i});
        }
        
        for(int i=n-1; i>=0; i--){
            int idx = n;
            while(!s2.empty() && s2.top().first >= nums[i]){
                s2.pop();
            }
            
            if(!s2.empty())
                idx = s2.top().second;
            
            right_dp[i] = idx;
            s2.push({nums[i], i});
        }
        
        
        ll res = 0;
        for(int i=0; i<n; i++){
            // cout<<left_dp[i]<<" "<<right_dp[i]<<endl;
            ll right = right_dp[i]-1, left = left_dp[i];
            ll cur_sum = cum[right] - (left>=0 ? cum[left] : 0);
            // ll cur_num = static_cast<ll>(nums[i])*static_cast<ll>(nums[i]);
            res = max(res, cur_sum * nums[i]);
        }
        
        return res % static_cast<int>(1e9 + 7);
    }
};