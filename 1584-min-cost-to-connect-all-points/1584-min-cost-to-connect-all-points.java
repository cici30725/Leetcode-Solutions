class Solution {
    int[] dsu;
    int[] rank;
    int dist(int[] a, int[] b){
        return Math.abs(a[0]-b[0]) + Math.abs(a[1]-b[1]);
    }
    void make_set(int u){
        dsu[u] = u;
        rank[u] = 0;
    }
    
    int find(int u){
        if(dsu[u] == u)
            return u;
        return dsu[u] = find(dsu[u]);
    }
    
    void join(int u, int v){
        u = find(u);
        v = find(v);
        if(u!=v){
            if(rank[u]<rank[v]){
                var tmp = u;
                u = v;
                v = tmp;
            }
            dsu[v] = u;
            if(rank[u] == rank[v])
                rank[u]++;
        }
    }
    
    public int minCostConnectPoints(int[][] points) {
        ArrayList<int[]> edges = new ArrayList<>();
        for(int i=0; i<points.length; i++){
            for(int j=i+1; j<points.length; j++)
                edges.add(new int[]{i, j});
        }
        edges.sort((x, y) -> (dist(points[x[0]], points[x[1]])-dist(points[y[0]], points[y[1]])));
        /*
        Arrays.sort(edges, new Comparator<int[]>(){
            @Override public int compare(int[] x, int[] y){
               return dist(points[x[0]], points[x[1]]) - dist(points[y[0]], points[y[1]]);
            }
        }); 
        */
        
        int sol = 0;
        dsu = new int[points.length];
        rank = new int[points.length];
        for(int i=0; i<dsu.length; i++)
            make_set(i);
        
        int cnt = 0;
        for(int[] edge : edges){
            int u = edge[0], v = edge[1];
            int p_u = find(u), p_v = find(v);
            if(p_u == p_v)
                continue;
            sol+=dist(points[u], points[v]);
            join(u, v);
            cnt++;
            if(cnt == points.length-1)
                break;
        }
        return sol;
    }
}