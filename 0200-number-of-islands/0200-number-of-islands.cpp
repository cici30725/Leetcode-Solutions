class Solution {
public:
    vector<pair<int, int>> dir = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };
    
    void dfs(int i, int j, vector<vector<char>>& grid){
        if(grid[i][j]=='0')
            return;
        
        grid[i][j] = '0';
        for(auto [di, dj] : dir){
            int ii = i + di, jj = j + dj;
            if(ii>=0 && ii < grid.size() && jj>=0 && jj<grid[0].size()){
                dfs(ii, jj, grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='1'){
                    dfs(i, j, grid);
                    res++;
                }
            }
        }
        
        return res;
    }
};