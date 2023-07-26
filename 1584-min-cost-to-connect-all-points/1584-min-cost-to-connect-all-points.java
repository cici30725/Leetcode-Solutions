class Solution {
    int[] dsu;
    int dist(int[] a, int[] b){
        return Math.abs(a[0]-b[0]) + Math.abs(a[1]-b[1]);
    }
    int find(int u){
        if(dsu[u] == u)
            return u;
        return dsu[u] = find(dsu[u]);
    }
    
    void join(int u, int v){
        int p_u = find(u), p_v = find(v);
        dsu[p_v] = p_u;
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
        for(int i=0; i<dsu.length; i++)
            dsu[i] = i;
        
        for(int[] edge : edges){
            int u = edge[0], v = edge[1];
            int p_u = find(u), p_v = find(v);
            if(p_u == p_v)
                continue;
            sol+=dist(points[u], points[v]);
            join(u, v);
        }
        return sol;
    }
}