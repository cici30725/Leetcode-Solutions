class Solution {
    public int largestRectangleArea(int[] heights) {
        Stack<int[]> S = new Stack<>();
        int n = heights.length;
        int[] l_arr = new int[n];
        int[] r_arr = new int[n];
        for(int i=0; i<n; i++){
            int val = -1;
            while(!S.isEmpty()){
                int[] top = S.peek();
                if(top[1]<heights[i]){
                    val = top[0];
                    break;
                }
                S.pop();
            }
            l_arr[i] = val;
            S.push(new int[]{i, heights[i]});
        }
        
        S.clear();
        
        for(int i=n-1; i>=0; i--){
            int val = n;
            while(!S.isEmpty()){
                int[] top = S.peek();
                if(top[1]<heights[i]){
                    val = top[0];
                    break;
                }
                S.pop();
            }
            r_arr[i] = val;
            S.push(new int[]{i, heights[i]});
        }
        
        int sol=0;
        for(int i=0; i<n; i++){
            int l_area = (i-l_arr[i])*heights[i];
            int r_area = Math.abs(i-r_arr[i])*heights[i];
            // System.out.format("%d: %d, %d\n", i, l_arr[i], r_arr[i]);
            sol = Math.max(l_area+r_area-heights[i], sol);
        }
        return sol;
    }
}