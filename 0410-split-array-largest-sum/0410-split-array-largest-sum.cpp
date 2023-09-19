class Solution {
public:
    using ll = long long;
    int splitArray(vector<int>& nums, int k) {
        
        auto check = [&](ll ub) -> bool {
            for(int i : nums){
                if(i>ub)
                    return false;
            }
            
            ll cur = 0;
            int cur_k = 0;
            for(int i=0; i<nums.size(); i++){
                if(cur+nums[i] > ub){
                    cur_k++;
                    cur=0;
                }
                cur+=nums[i];
            }
            
            cur_k++;
            return cur_k <= k;
        };
        
        ll l = -1, r = 1e9+1;
        while(r-l>1){
            ll m = (l+r)/2;
            if(!check(m))
                l = m;
            else
                r = m;
        }
        
        return r;
    }
};