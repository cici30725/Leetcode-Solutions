class Solution {
    public int trap(int[] height) {
        if(height.length<=2)
            return 0;
        var pq = new PriorityQueue<int[]>((x, y) -> (y[0]-x[0]));
        for(int i=height.length-1; i>1; i--)
            pq.offer(new int[]{height[i], i});
        
        int l_max = height[0];
        int sol = 0;
        for(int i=1; i<height.length-1; i++){
            while(pq.peek()[1] <= i)
                pq.poll();
            int r_max = pq.peek()[0];
            int k = Math.min(l_max, r_max);
            int added = Math.max(0, k - height[i]);
            // System.out.format("%d %d %d %d\n", i, l_max, r_max, added);
            sol += added;
            l_max = Math.max(l_max, height[i]);
            // pq.remove({height[i], i});
        }
        return sol;
    }
}