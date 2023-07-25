class Solution {
    boolean dp(Boolean[][] memo, int s1_idx, int s2_idx, String s1, String s2, String s3){
        if(s1_idx==-1)
            return s3.substring(0, s2_idx+1).equals(s2.substring(0, s2_idx+1));
        else if(s2_idx==-1)
            return s3.substring(0, s1_idx+1).equals(s1.substring(0, s1_idx+1));
        
        if(memo[s1_idx][s2_idx]!=null)
            return memo[s1_idx][s2_idx];
        
        int s3_idx = s1_idx + s2_idx + 1;
        boolean first = (s3.charAt(s3_idx) == s1.charAt(s1_idx)) && dp(memo, s1_idx-1, s2_idx, s1, s2, s3);
        boolean second = (s3.charAt(s3_idx) == s2.charAt(s2_idx)) && dp(memo, s1_idx, s2_idx-1, s1, s2, s3);
        return memo[s1_idx][s2_idx] = first || second;
    }
    public boolean isInterleave(String s1, String s2, String s3) {
        if(s1.length()+s2.length()!=s3.length())
            return false;
        
        Boolean[][] memo = new Boolean[s1.length()][s2.length()];
        return dp(memo, s1.length()-1, s2.length()-1, s1, s2, s3);
    }
}