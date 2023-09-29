class Solution {
public:
    void dfs(int idx, vector<int>& nums, vector<vector<int>>& sol){
        if(idx==nums.size()){
            sol.push_back(nums);
            return;
        }
        
        for(int i=idx; i<nums.size(); i++){
            swap(nums[i], nums[idx]);
            dfs(idx+1, nums, sol);
            swap(nums[i], nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> sol;
        dfs(0, nums, sol);
        return sol;
    }
};