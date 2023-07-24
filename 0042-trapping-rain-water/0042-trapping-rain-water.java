class Solution {
    public int trap(int[] height) {
        int sol = 0, l = 0, r = height.length-1;
        int lMax = height[l], rMax = height[r];
        while(l<r){
            if(lMax<rMax){
                l++;
                lMax = Math.max(lMax, height[l]);
                sol += lMax-height[l];
            }
            else{
                r--;
                rMax = Math.max(rMax, height[r]);
                sol += rMax-height[r];
            }
        }
        return sol;
    }
}