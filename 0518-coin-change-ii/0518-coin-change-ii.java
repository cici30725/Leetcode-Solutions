class Solution {
    public int change(int amount, int[] coins) {
        int[] dp = new int[amount+1];
        dp[0] = 1;
        for(int c : coins){
            if(c<=amount)
                dp[c] += 1;
            for(int i=c+1; i<=amount; i++){
                dp[i] += dp[i-c];
            }
        }
        return dp[amount];
    }
}