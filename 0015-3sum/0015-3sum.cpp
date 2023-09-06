class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> sol;
        for(int i=0; i<nums.size(); i++){
            if(i>0 && nums[i]==nums[i-1])
                continue;
            int target = -nums[i];
            int l = i+1, r = nums.size()-1;
            while(l<r){
                int cur = nums[l] + nums[r];
                if(cur > target)
                    r--;
                else if(cur<target)
                    l++;
                else{
                    sol.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while(l<r && nums[l]==nums[l-1] && nums[r]==nums[r+1]){
                        l++;
                        r--;
                    }
                }
            }
        }
        return sol;
    }
};