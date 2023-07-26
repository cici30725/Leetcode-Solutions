class Solution {
    public int largestRectangleArea(int[] heights) {
        TreeMap<Integer, Integer> M = new TreeMap<>();
        TreeMap<Integer, ArrayList<Integer>> heightMap = new TreeMap<>(Collections.reverseOrder());
        for(int i=0; i<heights.length; i++){
            var list = heightMap.computeIfAbsent(heights[i], k-> new ArrayList<Integer>());
            list.add(i);
        }
        
        int sol = 0;
        
        for(Map.Entry<Integer, ArrayList<Integer>> entry : heightMap.entrySet()){
            int h = entry.getKey();
            var list = entry.getValue();
            for(int idx : list){
                var i1 = M.lowerEntry(idx+1);
                var i2 = M.ceilingEntry(idx+1);
                Integer l1, l2, r1, r2;
                if(i1==null){
                    l1 = -100;
                    r1 = -100;
                }
                else{
                    l1 = i1.getKey();
                    r1 = i1.getValue();
                }
                
                if(i2==null){
                    l2 = 1000000;
                    r2 = 1000000;
                }
                else{
                    l2 = i2.getKey();
                    r2 = i2.getValue();
                }
                
                int cur_l = idx, cur_r = idx;
                if(idx-1 == r1){
                    M.remove(l1);
                    cur_l = l1;
                }
                if(idx+1 == l2){
                    M.remove(l2);
                    cur_r = r2;
                }
                
                M.put(cur_l, cur_r);
                sol = Math.max(sol, (cur_r-cur_l+1)*h);
            }
        }
        return sol;
        
    }
}