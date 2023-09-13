class Solution {
public:
    pair<int, int> intToPos(int pos, int n){
        int r = (n-1) - pos / n;
        if((r-n+1)%2==0){
            int c = (pos % n);
            return {r, c};
        }
        else{
            int c = (n-1) - (pos%n);
            return {r, c};
        }
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        queue<pair<int, int>> q;
        
        q.push({0, 0});
        vector<bool> visit(n*n, false);
            
        while(!q.empty()){
            auto cur = q.front();
            int pos = cur.first, val = cur.second;
            q.pop();
            if(visit[pos])
                continue;
            visit[pos] = true;
            
            if(pos == n*n-1)
                return val;
            
            for(int i=pos+1; i<=min(pos+6, n*n-1); i++){
                auto coord = intToPos(i, n);
                int r = coord.first, c = coord.second;
                if(board[r][c]==-1){
                    q.push({i, val+1});
                }
                else{
                    q.push({board[r][c]-1, val+1});
                }
            }
        }
        return -1;
    }
};