class Solution {
public:
    bool flag = false;
    array<int, 26> dfs(int cur, vector<vector<int>>& edges, vector<int>& visit, vector<array<int, 26>>& max_freq, string& colors){
        if(visit[cur]==1){
            flag = true;
            return {};
        }
        
        if(visit[cur]==2)
            return max_freq[cur];
        
        visit[cur] = 1;
        array<int, 26> cur_freq{};
        for(int v : edges[cur]){
            auto arr = dfs(v, edges, visit, max_freq, colors);
            for(int i=0; i<26; i++)
                cur_freq[i] = max(cur_freq[i], arr[i]);
        }
        
        cur_freq[colors[cur]-'a']+=1;
        visit[cur] = 2;
        //cout<<cur<<" "<<cur_p.first<<" "<<cur_p.second<<endl;
        return max_freq[cur] = cur_freq;
    }
    
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<int> visit(n, 0);
        vector<array<int, 26>> max_freq(n);
        vector<vector<int>> adj(n);
        
        for(auto& e : edges){
            adj[e[0]].push_back(e[1]);
        }
        
        int res = 0;
        for(int i=0; i<n; i++){
            auto arr = dfs(i, adj, visit, max_freq, colors);
            for(int i=0; i<26; i++)
                res = max(res, arr[i]);
        }
        
        if(flag)
            return -1;
        return res;
    }
};