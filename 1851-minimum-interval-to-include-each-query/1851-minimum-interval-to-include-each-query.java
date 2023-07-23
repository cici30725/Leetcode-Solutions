class Solution {
    public int[] minInterval(int[][] intervals, int[] queries) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((x, y) -> ((x[1]-x[0])-(y[1]-y[0])));
        var H = new HashMap<Integer, Integer>();
        int[] arr = queries.clone();
        Arrays.sort(arr);
        Arrays.sort(intervals, (x, y) -> (x[0] - y[0])); 
        int i = 0;
        for(int q : arr){
            while(i<intervals.length && intervals[i][0] <= q)
                pq.offer(intervals[i++]);
            
            while(!pq.isEmpty() && pq.peek()[1] < q)
                pq.poll();
            
            H.put(q, pq.isEmpty() ? -1 : pq.peek()[1] - pq.peek()[0]+1);
        }
        
        for(int j=0; j<queries.length; j++)
            queries[j] = H.get(queries[j]);
        
        return queries;
    }
}