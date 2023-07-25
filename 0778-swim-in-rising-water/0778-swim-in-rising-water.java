class Solution {
    int[][] dir;
    public int swimInWater(int[][] grid) {
        dir = new int[][]{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        PriorityQueue<int[]> Q = new PriorityQueue<>((x, y)->(x[2]-y[2]));
        int n = grid.length;
        Integer[][] dp = new Integer[n][n];
        Q.offer(new int[]{0, 0, grid[0][0]});
        while(!Q.isEmpty()){
            var cur = Q.poll();
            int x = cur[0], y = cur[1], cost = cur[2];
            if(dp[x][y]!=null && cost>=dp[x][y])
                continue;
            dp[x][y] = cost;
            if(x==n-1 && y==n-1)
                break;
            // System.out.format("(%d, %d) = %d\n", x, y, cost);
            for(int[] d : dir){
                int n_x = x+d[0], n_y = y+d[1];
                if(0<= n_x && n_x < n && 0<= n_y && n_y < n){
                    int new_cost = Math.max(grid[n_x][n_y], cost);
                    Q.offer(new int[]{n_x, n_y, new_cost});
                }
            }
        }
        return dp[n-1][n-1];
    }
}