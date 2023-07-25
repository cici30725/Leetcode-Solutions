class Solution {
    public int jump(int[] nums) {
        int sol = 0;
        int n = nums.length;
        if(n==1)
            return 0;
        int l = 0;
        int r = nums[0];
        while(r<n-1){
            int cur_max = 0;
            for(int i=l; i<=r; i++){
                cur_max = Math.max(cur_max, i+nums[i]);
            }
            l = r+1;
            r = cur_max;
            sol++;
        }
        return sol+1;
    }
}