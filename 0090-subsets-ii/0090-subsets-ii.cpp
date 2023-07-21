class Solution {
public:
    
    void dfs(int idx, vector<int>& nums, vector<int>& cur_sol, vector<vector<int>>& sol){
        if(idx == nums.size()){
            sol.push_back(cur_sol);
            return;
        }
        
        cur_sol.push_back(nums[idx]);
        dfs(idx+1, nums, cur_sol, sol);
        cur_sol.pop_back();
        
        while(idx+1 < nums.size() && nums[idx+1]==nums[idx])
            idx+=1;
        dfs(idx+1, nums, cur_sol, sol);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> cur_sol;
        vector<vector<int>> sol;
        dfs(0, nums, cur_sol, sol);
        return sol;
    }
};