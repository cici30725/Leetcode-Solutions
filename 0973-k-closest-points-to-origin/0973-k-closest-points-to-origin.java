class Solution {
    public int[][] kClosest(int[][] points, int k) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> (b[0]*b[0] + b[1]*b[1])-(a[0]*a[0] + a[1]*a[1]));
        for(int[] pair : points){
            if(pq.size() < k)
                pq.offer(pair);
            else{
                int[] top = pq.peek();
                if(top[0]*top[0] + top[1]*top[1] > pair[0]*pair[0]+pair[1]*pair[1]){
                    pq.poll();
                    pq.offer(pair);
                }
            }
        }
        
        int[][] sol = new int[k][2];
        for(int i=0; i<k; i++)
            sol[i] = pq.poll();
        return sol;
    }
}