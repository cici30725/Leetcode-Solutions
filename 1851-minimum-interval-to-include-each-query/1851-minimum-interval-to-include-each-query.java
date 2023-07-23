class Solution {
    public int[] minInterval(int[][] intervals, int[] queries) {
        int[] queries_org = queries.clone();
        Arrays.sort(intervals, new CustomComparator());
        Arrays.sort(queries);
        int[] sol = new int[queries.length];
        var H = new HashMap<Integer, Integer>();
        
        int q_idx = 0;
        int i_idx = 0;
        var M = new TreeMap<Integer, Pair<Integer, Integer>>();
        while(q_idx < queries.length){
            while(i_idx < intervals.length && intervals[i_idx][0] <= queries[q_idx]){
                int l = intervals[i_idx][0];
                int r = intervals[i_idx][1];
                int interval_len = r-l+1;
                if(r >= queries[q_idx])
                    M.put(interval_len, new Pair<Integer, Integer>(l, r));
                i_idx++;
            }
            
            while(!M.isEmpty()){
                var entry = M.firstEntry();
                int cur_interval_len = entry.getKey();
                var cur_interval = entry.getValue();
                int cur_l = cur_interval.getKey();
                int cur_r = cur_interval.getValue();
                
                if(queries[q_idx]>=cur_l && queries[q_idx]<=cur_r){
                    // sol[q_idx] = cur_interval_len;
                    // H[queries[q_idx]] = cur_interval_len;
                    H.put(queries[q_idx], cur_interval_len);
                    break;
                }
                else
                    M.pollFirstEntry();
            }
            
            if(M.isEmpty()){
                // sol[q_idx]=-1;
                // H[queries[q_idx]] = -1;
                H.put(queries[q_idx], -1);
            }
            
            q_idx++;
        }
        
        for(int i=0; i<queries_org.length; i++)
            sol[i] = H.get(queries_org[i]);
        return sol;
    }
    
    // Custom comparator to compare based on the first entry of the subarrays
    static class CustomComparator implements Comparator<int[]> {
        @Override
        public int compare(int[] a, int[] b) {
            // Compare the first element of each subarray
            return Integer.compare(a[0], b[0]);
        }
    }
}