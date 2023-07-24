class Solution {
    boolean[][][] dp;
    
    public boolean isInterleave(String s1, String s2, String s3) {
        if(s3.length()!= s1.length()+s2.length())
            return false;
        
        dp = new boolean[s3.length()+1][s1.length()+1][s2.length()+1];
        for(int i=0; i<=s3.length(); i++){
            for(int j=0; j<=s1.length(); j++){
                for(int k=0; k<=s2.length(); k++){
                    dp[i][j][k] = false;
                }
            }
        }
        dp[0][0][0] = true;
        // dp[1][1][0] = (s3.charAt(0) == s1.charAt(0));
        // dp[1][0][1] = (s3.charAt(0) == s2.charAt(0));
        
        for(int i=0; i<=s3.length(); i++){
            for(int j=0; j<=s1.length(); j++){
                for(int k=0; k<=s2.length(); k++){
                    if(i==0 && j==0 && k==0)
                        dp[i][j][k] = true;
                    else if(i!=j+k)
                        dp[i][j][k] = false;
                    else if(j==0)
                        dp[i][0][k] = s3.substring(0, i).equals(s2.substring(0, k));
                    else if(k==0)
                        dp[i][j][0] = s3.substring(0, i).equals(s1.substring(0, j));
                    else{
                        boolean first = dp[i-1][j-1][k] && (s3.charAt(i-1)==s1.charAt(j-1));
                        boolean sec = dp[i-1][j][k-1] && (s3.charAt(i-1)==s2.charAt(k-1));
                        dp[i][j][k] = first || sec;
                        // System.out.format("(%d, %d, %d) = first %b\n", i, j, k, dp[i-1][j-1][k]);
                    }
                    // System.out.format("(%d, %d, %d) = %b\n", i, j, k, dp[i][j][k]);
                }
            }
        }
        
      return dp[s3.length()][s1.length()][s2.length()];
    }
}