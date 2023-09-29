class Solution {
public:
    void dfs(int idx, vector<int>& cur, vector<int>& candidates, vector<vector<int>>& sol, int target){
        if(target == 0){
            sol.push_back(cur);
            return;
        }
        else if(target < 0)
            return;
        
        if(idx==candidates.size())
            return;
        
        cur.push_back(candidates[idx]);
        dfs(idx, cur, candidates, sol, target-candidates[idx]);
        cur.pop_back();
        dfs(idx+1, cur, candidates, sol, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> cur;
        vector<vector<int>> sol;
        dfs(0, cur, candidates, sol, target);
        return sol;
    }
};