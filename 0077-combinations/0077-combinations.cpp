class Solution {
public:
    void dfs(int n, int idx, int k, vector<int>& vec, vector<vector<int>>& sol){
        if(k==0){
            sol.push_back(vec);
            return;
        }
        
        if(n-idx+1 < k)
            return;
        
        vec.push_back(idx);
        dfs(n, idx+1, k-1, vec, sol);
        vec.pop_back();
        dfs(n, idx+1, k, vec, sol);
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> sol;
        vector<int> vec;
        dfs(n, 1, k, vec, sol);
        return sol;
    }
};