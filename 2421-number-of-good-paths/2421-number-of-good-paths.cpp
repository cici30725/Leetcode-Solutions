class UnionFind {
    private:
        vector<int> id, rank;
        int cnt;
    public:
        UnionFind(int cnt) : cnt(cnt) {
            id = vector<int>(cnt);
            rank = vector<int>(cnt, 0);
            for (int i = 0; i < cnt; ++i) id[i] = i;
        }
        int find(int p) {
            if (id[p] == p) return p;
            return id[p] = find(id[p]);
        }
        bool connected(int p, int q) { 
            return find(p) == find(q); 
        }
        void connect(int p, int q) {
            int i = find(p), j = find(q);
            if (i == j) return;
            if (rank[i] < rank[j]) {
                id[i] = j;  
            } else {
                id[j] = i;
                if (rank[i] == rank[j]) rank[j]++;
            }
            --cnt;
        }
};

class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        vector<vector<int>> adj(n);
        map<int, vector<int>> M;
        for(auto& e : edges){
            int u = e[0], v = e[1];
            if(vals[u]>=vals[v])
                adj[u].push_back(v);
            else
                adj[v].push_back(u);
        }
        
        for(int i=0; i<n; i++){
            M[vals[i]].push_back(i);
        }
        
        UnionFind uf(n);
        
        int sol = 0;
        
        for(auto& [cur_weight, allNodes] : M){
            for(int u : allNodes){
                for(int v : adj[u]){
                    uf.connect(u, v);
                }
            }
            
            sol += allNodes.size();
            
            unordered_map<int, int> um;
            for(int u : allNodes){
                um[uf.find(u)]++;
            }
            
            for(auto& [leader, cnt] : um){
                sol += (cnt * (cnt-1))/2;
            }
        }
        
        return sol;
    }
};