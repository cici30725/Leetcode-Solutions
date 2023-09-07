class Solution {
public:
    void dfs(vector<vector<int>>& sol, vector<int>& nums, vector<int>& cur_arr, int idx){
        sol.push_back(cur_arr);
        for(int i=idx; i<nums.size(); i++){
            if(i>idx && nums[i]==nums[i-1])
                continue;
            cur_arr.push_back(nums[i]);
            dfs(sol, nums, cur_arr, i+1);
            cur_arr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> sol;
        vector<int> cur_arr;
        dfs(sol, nums, cur_arr, 0);
        return sol;
    }
};