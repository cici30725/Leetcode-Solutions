class Solution {
public:
    void dfs(vector<vector<int>>& image, int r, int c, int orgColor, int color){
        if(image[r][c] == orgColor){
            image[r][c] = color;
            if(r>=1) dfs(image, r-1, c, orgColor, color);
            if(r<image.size()-1) dfs(image, r+1, c, orgColor, color);
            if(c>=1) dfs(image, r, c-1, orgColor, color);
            if(c < image[0].size()-1) dfs(image, r, c+1, orgColor, color);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int orgColor = image[sr][sc];
        if(orgColor != color) dfs(image, sr, sc, orgColor, color);
        return image;
    }
};