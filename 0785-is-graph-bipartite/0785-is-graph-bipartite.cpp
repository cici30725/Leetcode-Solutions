class Solution {
public:
    bool check(int root, vector<int>& color, vector<vector<int>>& graph){
        int cur_color = 0;
        
        queue<int> q;
        q.push(root);
        color[root] = cur_color;
            
        int len = 1;
        while(len){
            int next_color = (cur_color+1)%2;
            while(len--){
                int cur = q.front();
                q.pop();
                for(int& v : graph[cur]){
                    if(color[v] == cur_color)
                        return false;
                    else if(color[v]==2){
                        color[v] = next_color;
                        q.push(v);
                    }
                }
            }
            len = q.size();
            cur_color = next_color;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 2);
        for(int i=0; i<n; i++){
            if(color[i]==2 && !check(i, color, graph))
                return false;
        }
        return true;
    }
};