class Solution {
public:
    void dfs(vector<vector<int>>& sol, vector<int>& candidates, vector<int>& cur_arr, int target, int cur_idx){
        if(target == 0){
            sol.push_back(cur_arr);
            return;
        }
        
        if(target < 0 || cur_idx == candidates.size()){
            return;
        }
        
        cur_arr.push_back(candidates[cur_idx]);
        dfs(sol, candidates, cur_arr, target-candidates[cur_idx], cur_idx);
        cur_arr.pop_back();
        dfs(sol, candidates, cur_arr, target, cur_idx+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> sol;
        vector<int> cur_arr;
        dfs(sol, candidates, cur_arr, target, 0);
        return sol;
    }
};