class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0;
        int sol = INT_MAX;
        int cur = nums[0];
        while(r < nums.size()){
            // cout<<l<<" "<<r<<" "<<cur<<endl;
            if(cur >= target){
                sol = min(sol, r-l+1);
                cur-=nums[l];
                l++;
            }
            else{
                r++;
                if(r < nums.size())
                    cur+=nums[r];
            }
        }
        
        return sol==INT_MAX ? 0 : sol;
    }
};