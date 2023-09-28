class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(), n = image[0].size();
        
        vector<vector<int>> visit(m, vector<int>(n, false));
        queue<pair<int, int>> q;
        q.push({sr, sc});
        
        vector<pair<int, int>> dir = {
            {1, 0},
            {0, 1},
            {-1, 0},
            {0, -1}
        };
        
        int org_color = image[sr][sc];
        
        while(!q.empty()){
            auto [cur_r, cur_c] = q.front();
            q.pop();
            
            if(visit[cur_r][cur_c])
                continue;
            
            visit[cur_r][cur_c] = true;
            image[cur_r][cur_c] = color;
            for(auto& [dr, dc]: dir){
                int next_r = cur_r + dr, next_c = cur_c + dc;
                if(0<=next_r && next_r < m && 0<=next_c && next_c < n && image[next_r][next_c] == org_color){
                    q.push({next_r, next_c});
                }
            }
        }
        
        return image;
    }
};