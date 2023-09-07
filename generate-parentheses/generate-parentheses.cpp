class Solution {
public:
    void dfs(vector<string>& sol, string& cur, int left_cnt, int depth, int n){
        if(depth == 2*n){
            if(left_cnt==0)
                sol.push_back(cur);
            return;
        }
        
        if(left_cnt<n){
            cur.push_back('(');
            dfs(sol, cur, left_cnt+1, depth+1, n);
            cur.pop_back();
        }
        if(left_cnt>0){
            cur.push_back(')') ;
            dfs(sol, cur, left_cnt-1, depth+1, n);
            cur.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> sol;
        string s;
        dfs(sol, s, 0, 0, n);
        return sol;
    }
};