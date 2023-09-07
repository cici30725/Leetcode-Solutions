class Solution {
public:
    void dfs(vector<vector<int>>& sol, vector<int>& nums, vector<int>& cur_arr, int idx){
        if(idx == nums.size()){
            sol.push_back(cur_arr);
            return;
        }
        cur_arr.push_back(nums[idx]);
        dfs(sol, nums, cur_arr, idx+1);
        cur_arr.pop_back();
        int i = idx+1;
        while(i<nums.size() && nums[i]==nums[i-1])
            i++;
        dfs(sol, nums, cur_arr, i);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> sol;
        vector<int> cur_arr;
        dfs(sol, nums, cur_arr, 0);
        return sol;
    }
};