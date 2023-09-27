class Solution {
public:
    void dfs(int idx, int target, vector<int>& candidates, vector<int>& cur, vector<vector<int>>& sol){
        if(target == 0){
            sol.push_back(cur);
            return;
        }
        else if(target < 0){
            return;
        }
        
        for(int i=idx; i<candidates.size(); i++){
            if(i>idx && candidates[i] == candidates[i-1])
                continue;
            cur.push_back(candidates[i]);
            dfs(i+1, target-candidates[i], candidates, cur, sol);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> cur;
        vector<vector<int>> sol;
        dfs(0, target, candidates, cur, sol);
        return sol;
    }
};