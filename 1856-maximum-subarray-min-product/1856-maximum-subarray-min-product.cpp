class Solution {
public:
    using ll = long long;
    
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        vector<ll> cum(n);
        vector<ll> right_cum(n);
        for(int i=0; i<n; i++){
            if(i==0)
                cum[0] = nums[0];
            else
                cum[i] = cum[i-1]+nums[i];
        }
        for(int i=n-1; i>=0; i--){
            if(i==n-1)
                right_cum[n-1] = nums[n-1];
            else
                right_cum[i] = right_cum[i+1]+nums[i];
        }
        
        vector<ll> left_dp(n, 0);
        vector<pair<int, int>> sk;
        for(int i=0; i<nums.size(); i++){
            int cur_num = nums[i];
            while(!sk.empty()){
                if(sk.back().first < cur_num)
                    break;
                sk.pop_back();
            }
            
            if(sk.empty()){
                left_dp[i] = cur_num*cum[i];
                // cout<<"1 "<<cur_num<<" "<<res<<endl;
            }
            else{
                int idx = sk.back().second;
                left_dp[i] = static_cast<ll>(cur_num) * (cum[i] - cum[idx]);
                // cout<<"2 "<<cur_num<<" "<<idx<<" "<<res<<endl;
            }
            
            sk.push_back({cur_num, i});
        }
        
        sk.clear();
        vector<ll> right_dp(n, 0);
        
        for(int i=n-1; i>=0; i--){
            int cur_num = nums[i];
            while(!sk.empty()){
                if(sk.back().first < cur_num)
                    break;
                sk.pop_back();
            }
            
            if(sk.empty()){
                right_dp[i] = cur_num*right_cum[i];
            }
            else{
                int idx = sk.back().second;
                right_dp[i] = static_cast<ll>(cur_num) * (right_cum[i] - right_cum[idx]);
            }
            
            sk.push_back({cur_num, i});
        }
        
        ll res = 0;
        for(int i=0; i<n; i++){
            // cout<<left_dp[i]<<" "<<right_dp[i]<<endl;
            ll cur_num = static_cast<ll>(nums[i])*static_cast<ll>(nums[i]);
            res = max(res, left_dp[i] - cur_num + right_dp[i]);
        }
        
        return res % static_cast<int>(1e9 + 7);
    }
};