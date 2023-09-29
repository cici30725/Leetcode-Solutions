class Solution {
public:
    vector<pair<int, int>> dir = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==0){
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }
        
        auto isValid = [](int i, int j, int m, int n) -> bool{
            return (i>=0 && i<m) && (j>=0 && j<n);
        };
        
        while(!q.empty()){
            auto [i, j] = q.front();
            q.pop();
            
            for(auto [di, dj]: dir){
                int ii = i+di, jj = j+dj;
                if(isValid(ii, jj, m, n) && dist[ii][jj]==-1){
                    dist[ii][jj] = dist[i][j] + 1;
                    q.push({ii, jj});
                }
            }
        }
        
        return dist;
    }
};