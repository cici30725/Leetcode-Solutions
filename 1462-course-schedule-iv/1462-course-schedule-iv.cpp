class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n = numCourses;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(auto& e : prerequisites){
            dp[e[0]][e[1]] = true;
        }
        
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    dp[i][j] = dp[i][j] || (dp[i][k] & dp[k][j]);
                }
            }
        }
        
        vector<bool> sol;
        for(auto& e : queries){
            sol.push_back(dp[e[0]][e[1]]);
        }
        return sol;
    }
};