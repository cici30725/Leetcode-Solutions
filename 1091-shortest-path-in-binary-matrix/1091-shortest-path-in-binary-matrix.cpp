class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1)
            return -1;
        
        queue<array<int, 3>> q;
        int n = grid.size();
        vector<vector<bool>> visit(n, vector<bool>(n, false));
        
        q.push({0, 0, 1});
        vector<pair<int, int>> dir{{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            int cur_x = cur[0], cur_y = cur[1];
            if(visit[cur_x][cur_y])
                continue;
            visit[cur_x][cur_y] = true;
            
            if(cur_x==n-1 && cur_y==n-1)
                return cur[2];
            
            for(auto d : dir){
                int x = cur_x+d.first, y = cur_y + d.second;
                if(x<0 || x>=n || y<0 || y>=n || grid[x][y]==1)
                    continue;
                q.push({x, y, cur[2]+1});
            }
        }
        return -1;
    }
};