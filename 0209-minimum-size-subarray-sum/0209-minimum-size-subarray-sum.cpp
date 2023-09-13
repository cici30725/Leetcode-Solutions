class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0;
        int sol = INT_MAX;
        int cur = 0;
        while(r < nums.size()){
            cur+=nums[r];
            while(cur>=target){
                sol = min(sol, r-l+1);
                cur-=nums[l];
                l++;
            }
            r++;
        }
        
        return sol==INT_MAX ? 0 : sol;
    }
};