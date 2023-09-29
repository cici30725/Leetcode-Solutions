class Solution {
public:
    vector<pair<int, int>> dir = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };
    
    bool isValid(int x, int y, int m, int n){
        return (x>=0 && x<m) && (y>=0 && y<n);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        int freshOrange = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1)
                   freshOrange++; 
                else if(grid[i][j]==2)
                    q.push({i, j});
            }
        }
        
        int res = 0;
        while(!q.empty()){
            int size = q.size();
            int contaminated = 0;
            for(int i=0; i<size; i++){
                auto [x, y] = q.front();
                q.pop();
                for(auto& [dx, dy] : dir){
                    int xx = x+dx;
                    int yy = y+dy;
                    if(isValid(xx, yy, m, n) && grid[xx][yy]==1){
                        grid[xx][yy] = 2;
                        q.push({xx, yy});
                        contaminated++;
                    }
                }
            }
            freshOrange -= contaminated;
            if(contaminated>0)
                res++;
        }
        
        return freshOrange>0 ? -1 : res;
    }
};