class Solution {
public:
    void dfs(int cur_idx, vector<int>& nums, vector<int>& cur_vec, vector<vector<int>>& sol){
        if(cur_idx >= nums.size()){
            sol.push_back(cur_vec);
            return;
        }

        cur_vec.push_back(nums[cur_idx]);
        dfs(cur_idx+1, nums, cur_vec, sol);
        cur_vec.pop_back();
        dfs(cur_idx+1, nums, cur_vec, sol);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> sol;
        vector<int> cur_vec;
        dfs(0, nums, cur_vec, sol);
        return sol;
    }
};